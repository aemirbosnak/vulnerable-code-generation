//FormAI DATASET v1.0 Category: Image Editor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILTER_NAME_LENGTH 64

typedef struct Image {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

typedef struct Filter {
    char name[MAX_FILTER_NAME_LENGTH];
    int kernel_size;
    float **kernel;
} Filter;

void resize_image(Image *img, int new_width, int new_height) {
    unsigned char *new_data = malloc(new_width * new_height * img->channels * sizeof(unsigned char));
    float width_ratio = (float) img->width / (float) new_width;
    float height_ratio = (float) img->height / (float) new_height;
    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {
            for (int k = 0; k < img->channels; k++) {
                float x = j * width_ratio;
                float y = i * height_ratio;
                int x_floor = (int) x;
                int y_floor = (int) y;
                int x_ceil = x_floor < img->width - 1 ? x_floor + 1 : x_floor;
                int y_ceil = y_floor < img->height - 1 ? y_floor + 1 : y_floor;
                float x_lerp = x - (float) x_floor;
                float y_lerp = y - (float) y_floor;
                float top_left = (1 - x_lerp) * (1 - y_lerp) * img->data[(y_floor * img->width + x_floor) * img->channels + k];
                float top_right = x_lerp * (1 - y_lerp) * img->data[(y_floor * img->width + x_ceil) * img->channels + k];
                float bottom_left = (1 - x_lerp) * y_lerp * img->data[(y_ceil * img->width + x_floor) * img->channels + k];
                float bottom_right = x_lerp * y_lerp * img->data[(y_ceil * img->width + x_ceil) * img->channels + k];
                float result = top_left + top_right + bottom_left + bottom_right;
                new_data[(i * new_width + j) * img->channels + k] = (unsigned char) result;
            }
        }
    }
    img->width = new_width;
    img->height = new_height;
    free(img->data);
    img->data = new_data;
}

void apply_filter(Image *img, Filter *filter) {
    int padding = filter->kernel_size / 2;
    unsigned char *original_data = malloc(img->width * img->height * img->channels * sizeof(unsigned char));
    memcpy(original_data, img->data, img->width * img->height * img->channels * sizeof(unsigned char));
    for (int i = padding; i < img->height - padding; i++) {
        for (int j = padding; j < img->width - padding; j++) {
            for (int k = 0; k < img->channels; k++) {
                float sum = 0.0f;
                for (int y = -padding; y <= padding; y++) {
                    for (int x = -padding; x <= padding; x++) {
                        float kernel_value = filter->kernel[y + padding][x + padding];
                        int pixel_value = original_data[((i + y) * img->width + (j + x)) * img->channels + k];
                        sum += kernel_value * (float) pixel_value;
                    }
                }
                img->data[(i * img->width + j) * img->channels + k] = (unsigned char) sum;
            }
        }
    }
    free(original_data);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter image filename: ");
    scanf("%s", filename);
    Image img;
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file\n");
        return 0;
    }
    char header[54];
    fread(header, sizeof(char), 54, file);
    img.width = *(int*) &header[18];
    img.height = *(int*) &header[22];
    img.channels = *(int*) &header[28] / 8;
    int padding = (4 - (img.width * img.channels) % 4) % 4;
    img.data = malloc(img.width * img.height * img.channels * sizeof(unsigned char));
    for (int i = img.height - 1; i >= 0; i--) {
        fread(img.data + i * img.width * img.channels, sizeof(unsigned char), img.width * img.channels, file);
        fseek(file, padding, SEEK_CUR);
    }
    fclose(file);
    printf("Image loaded: %d x %d, %d channels\n", img.width, img.height, img.channels);
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Resize image\n");
        printf("2. Apply filter\n");
        printf("3. Save image\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            int new_width, new_height;
            printf("Enter new width: ");
            scanf("%d", &new_width);
            printf("Enter new height: ");
            scanf("%d", &new_height);
            resize_image(&img, new_width, new_height);
            printf("Image resized to %d x %d\n", img.width, img.height);
        } else if (choice == 2) {
            Filter filter;
            printf("Enter filter name: ");
            scanf("%s", filter.name);
            printf("Enter kernel size (must be an odd number): ");
            scanf("%d", &filter.kernel_size);
            filter.kernel = malloc(filter.kernel_size * sizeof(float*));
            for (int i = 0; i < filter.kernel_size; i++) {
                filter.kernel[i] = malloc(filter.kernel_size * sizeof(float));
                for (int j = 0; j < filter.kernel_size; j++) {
                    printf("Enter kernel value (%d, %d): ", i,  j);
                    scanf("%f", &filter.kernel[i][j]);
                }
            }
            apply_filter(&img, &filter);
            printf("Filter \"%s\" applied\n", filter.name);
            for (int i = 0; i < filter.kernel_size; i++) {
                free(filter.kernel[i]);
            }
            free(filter.kernel);
        } else if (choice == 3) {
            printf("Enter output filename: ");
            scanf("%s", filename);
            FILE *file = fopen(filename, "wb");
            if (!file) {
                printf("Could not open file\n");
                return 0;
            }
            char header[54];
            memset(header, 0, 54);
            header[0] = 'B';
            header[1] = 'M';
            int file_size = 54 + img.width * img.height * img.channels + (img.width * img.channels) % 4 * img.height;
            *(int*) &header[2] = file_size;
            *(int*) &header[10] = 54;
            *(int*) &header[14] = 40;
            *(int*) &header[18] = img.width;
            *(int*) &header[22] = img.height;
            *(short*) &header[26] = 1;
            *(short*) &header[28] = img.channels * 8;
            fwrite(header, sizeof(char), 54, file);
            int padding = (4 - (img.width * img.channels) % 4) % 4;
            unsigned char *padding_data = calloc(padding, sizeof(unsigned char));
            for (int i = img.height - 1; i >= 0; i--) {
                fwrite(img.data + i * img.width * img.channels, sizeof(unsigned char), img.width * img.channels, file);
                fwrite(padding_data, sizeof(unsigned char), padding, file);
            }
            fclose(file);
            printf("Image saved to file %s\n", filename);
            free(padding_data);
        } else if (choice == 4) {
            break;
        }
    }
    free(img.data);
    return 0;
}