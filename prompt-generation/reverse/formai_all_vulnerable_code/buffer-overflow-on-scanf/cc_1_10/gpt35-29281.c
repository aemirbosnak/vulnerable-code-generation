//FormAI DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_IMAGE_SIZE 4096
#define MAX_PIXEL_VALUE 255

typedef struct {
    int width;
    int height;
    int** pixels;
} Image;

Image* create_image(int width, int height) {
    Image* image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(width * sizeof(int));
        memset(image->pixels[i], 0, width * sizeof(int));
    }
    return image;
}

void destroy_image(Image* image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void write_image(Image* image, char* filename) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "P2\n%d %d\n%d\n", image->width, image->height, MAX_PIXEL_VALUE);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(file, "%d ", image->pixels[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

Image* read_image(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("File not found: %s\n", filename);
        return NULL;
    }
    char line[256];
    fgets(line, sizeof(line), file);
    if (strcmp(line, "P2\n") != 0) {
        printf("Invalid file type: %s\n", filename);
        fclose(file);
        return NULL;
    }
    int width, height, max_val;
    fscanf(file, "%d %d %d", &width, &height, &max_val);
    if (max_val != MAX_PIXEL_VALUE) {
        printf("Invalid pixel value in file: %s\n", filename);
        fclose(file);
        return NULL;
    }
    Image* image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        image->pixels[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            fscanf(file, "%d", &image->pixels[i][j]);
        }
    }
    fclose(file);
    return image;
}

void invert_colors(Image* image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i][j] = MAX_PIXEL_VALUE - image->pixels[i][j];
        }
    }
}

void blur(Image* image) {
    int kernel[3][3] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};
    int total_weight = 16;
    Image* blurred = create_image(image->width, image->height);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int sum = 0;
            int weight = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = j + l;
                    int y = i + k;
                    if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
                        sum += image->pixels[y][x] * kernel[k+1][l+1];
                        weight += kernel[k+1][l+1];
                    }
                }
            }
            blurred->pixels[i][j] = sum / weight;
        }
    }
    memcpy(image->pixels, blurred->pixels, image->height * sizeof(int*));
    destroy_image(blurred);
}

void print_menu() {
    printf("Menu\n");
    printf("----\n");
    printf("1. Open image\n");
    printf("2. Save image\n");
    printf("3. Invert colors\n");
    printf("4. Blur\n");
    printf("5. Exit\n");
}

int main() {
    Image* image = NULL;
    char filename[MAX_FILENAME_LENGTH];
    int choice = 0;
    while (choice != 5) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                destroy_image(image);
                image = read_image(filename);
                break;
            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);
                write_image(image, filename);
                break;
            case 3:
                invert_colors(image);
                break;
            case 4:
                blur(image);
                break;
            case 5:
                destroy_image(image);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}