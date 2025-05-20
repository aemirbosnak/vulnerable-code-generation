//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image *create_image(int width, int height) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (Pixel *)malloc(sizeof(Pixel) * width * height);
    return img;
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void load_pbm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return;
    }

    // Read P6 header
    char header[3];
    fscanf(file, "%2s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported file format\n");
        fclose(file);
        return;
    }

    // Read width, height, and max color value
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    fgetc(file);  // Read the newline after max color value

    // Read pixel data
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void save_pbm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("File opening failed");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void grayscale_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
}

void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

void apply_sepia(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char originalR = img->data[i].r;
        unsigned char originalG = img->data[i].g;
        unsigned char originalB = img->data[i].b;

        img->data[i].r = fmin(255, (originalR * .393) + (originalG * .769) + (originalB * .189));
        img->data[i].g = fmin(255, (originalR * .349) + (originalG * .686) + (originalB * .168));
        img->data[i].b = fmin(255, (originalR * .272) + (originalG * .534) + (originalB * .131));
    }
}

void blur_image(Image *img) {
    Image *temp = create_image(img->width, img->height);
    for (int y = 1; y < img->height - 1; y++) {
        for (int x = 1; x < img->width - 1; x++) {
            int r_sum = 0, g_sum = 0, b_sum = 0;

            // Accumulate colors from surrounding pixels
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    Pixel p = img->data[(y + ky) * img->width + (x + kx)];
                    r_sum += p.r;
                    g_sum += p.g;
                    b_sum += p.b;
                }
            }

            int count = 9; // 3x3 filter
            temp->data[y * img->width + x].r = r_sum / count;
            temp->data[y * img->width + x].g = g_sum / count;
            temp->data[y * img->width + x].b = b_sum / count;
        }
    }

    // Copy blurred image back to original
    memcpy(img->data, temp->data, sizeof(Pixel) * img->width * img->height);
    free_image(temp);
}

void print_usage() {
    printf("Image Editor Usage:\n");
    printf("1. Load Image: load <filename>\n");
    printf("2. Save Image: save <filename>\n");
    printf("3. Apply Effects: grayscale | invert | sepia | blur\n");
    printf("4. Exit: exit\n");
}

int main(int argc, char *argv[]) {
    Image *image = NULL;
    char command[20];

    print_usage();

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "load") == 0) {
            char filename[100];
            scanf("%s", filename);
            image = create_image(0, 0); // Placeholder for dynamic loading
            load_pbm(filename, image);
            printf("Image loaded: %d x %d\n", image->width, image->height);
        } else if (strcmp(command, "save") == 0) {
            char filename[100];
            scanf("%s", filename);
            save_pbm(filename, image);
            printf("Image saved: %s\n", filename);
        } else if (strcmp(command, "grayscale") == 0) {
            grayscale_image(image);
            printf("Applied grayscale effect.\n");
        } else if (strcmp(command, "invert") == 0) {
            invert_colors(image);
            printf("Applied invert effect.\n");
        } else if (strcmp(command, "sepia") == 0) {
            apply_sepia(image);
            printf("Applied sepia effect.\n");
        } else if (strcmp(command, "blur") == 0) {
            blur_image(image);
            printf("Applied blur effect.\n");
        } else if (strcmp(command, "exit") == 0) {
            free_image(image);
            break;
        } else {
            printf("Unknown command!\n");
        }
    }

    return 0;
}