//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

void load_image(const char *filename, int image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height);
void save_image(const char *filename, int image[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void flip_image(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void adjust_brightness_contrast(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height, int brightness, float contrast);

int main() {
    int image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;
    char input_file[100], output_file[100];
    int choice;
    int brightness;
    float contrast;

    printf("=== Simple Image Processor ===\n");
    
    // Load image
    printf("Enter the input image filename: ");
    scanf("%s", input_file);
    load_image(input_file, image, &width, &height);
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Flip Image\n");
        printf("2. Adjust Brightness and Contrast\n");
        printf("3. Save Image\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                flip_image(image, width, height);
                printf("Image flipped!\n");
                break;
            case 2:
                printf("Enter brightness adjustment (-255 to 255): ");
                scanf("%d", &brightness);
                printf("Enter contrast adjustment (0.0 to 3.0): ");
                scanf("%f", &contrast);
                adjust_brightness_contrast(image, width, height, brightness, contrast);
                printf("Brightness and contrast adjusted!\n");
                break;
            case 3:
                printf("Enter the output image filename: ");
                scanf("%s", output_file);
                save_image(output_file, image, width, height);
                printf("Image saved as %s!\n", output_file);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void load_image(const char *filename, int image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    fscanf(file, "%d %d", width, height);
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fscanf(file, "%d", &image[i][j]);
        }
    }
    fclose(file);
}

void save_image(const char *filename, int image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Cannot save file %s\n", filename);
        exit(1);
    }

    fprintf(file, "%d %d\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(file, "%d ", image[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void flip_image(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

void adjust_brightness_contrast(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height, int brightness, float contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = image[i][j] + brightness;
            new_value = (int)(new_value * contrast);
            if (new_value < 0) new_value = 0;
            if (new_value > 255) new_value = 255;
            image[i][j] = new_value;
        }
    }
}