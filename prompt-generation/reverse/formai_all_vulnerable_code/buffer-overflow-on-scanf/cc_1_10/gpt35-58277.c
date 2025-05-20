//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 1000

void print_menu();
void flip_image(FILE *input_file, FILE *output_file);
void change_brightness_contrast(FILE *input_file, FILE *output_file);

int main() {
    char input_file_name[MAX_FILENAME_LENGTH], output_file_name[MAX_FILENAME_LENGTH];
    FILE *input_file, *output_file;
    int menu_choice;

    printf("Enter input file name: ");
    scanf("%s", input_file_name);
    input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    printf("Enter output file name: ");
    scanf("%s", output_file_name);
    output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    do {
        print_menu();
        scanf("%d", &menu_choice);
        switch (menu_choice) {
            case 1:
                flip_image(input_file, output_file);
                break;
            case 2:
                change_brightness_contrast(input_file, output_file);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (menu_choice != 3);

    fclose(input_file);
    fclose(output_file);

    return 0;
}

void print_menu() {
    printf("Image Processing Menu\n");
    printf("1. Flip Image\n");
    printf("2. Change Brightness/Contrast\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
}

void flip_image(FILE *input_file, FILE *output_file) {
    int width, height, max_value;
    char format[3];
    fread(format, sizeof(char), 2, input_file);
    format[2] = '\0';
    if (strcmp(format, "P6") != 0) {
        printf("Invalid input file format\n");
        return;
    }
    fgetc(input_file); // Skip newline
    fscanf(input_file, "%d %d", &width, &height);
    fgetc(input_file); // Skip newline
    fscanf(input_file, "%d", &max_value);
    fgetc(input_file); // Skip newline

    // Allocate memory for image data
    unsigned char *data = malloc(3 * width * height * sizeof(unsigned char));

    // Read image data
    fread(data, sizeof(unsigned char), 3 * width * height, input_file);

    // Flip image horizontally
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width / 2; ++x) {
            for (int c = 0; c < 3; ++c) {
                unsigned char temp = data[3 * (y * width + x) + c];
                data[3 * (y * width + x) + c] = data[3 * (y * width + (width - 1 - x)) + c];
                data[3 * (y * width + (width - 1 - x)) + c] = temp;
            }
        }
    }

    // Write output file header
    fprintf(output_file, "P6\n");
    fprintf(output_file, "%d %d\n", width, height);
    fprintf(output_file, "%d\n", max_value);

    // Write output file data
    fwrite(data, sizeof(unsigned char), 3 * width * height, output_file);

    free(data);
}

void change_brightness_contrast(FILE *input_file, FILE *output_file) {
    int width, height, max_value;
    char format[3];
    fread(format, sizeof(char), 2, input_file);
    format[2] = '\0';
    if (strcmp(format, "P6") != 0) {
        printf("Invalid input file format\n");
        return;
    }
    fgetc(input_file); // Skip newline
    fscanf(input_file, "%d %d", &width, &height);
    fgetc(input_file); // Skip newline
    fscanf(input_file, "%d", &max_value);
    fgetc(input_file); // Skip newline

    // Allocate memory for image data
    unsigned char *data = malloc(3 * width * height * sizeof(unsigned char));

    // Read image data
    fread(data, sizeof(unsigned char), 3 * width * height, input_file);

    // Get brightness and contrast values from user
    int brightness, contrast;
    printf("Enter brightness value (-255 to 255): ");
    scanf("%d", &brightness);
    printf("Enter contrast value (-100 to 100): ");
    scanf("%d", &contrast);

    // Apply brightness and contrast to image data
    for (int i = 0; i < 3 * width * height; ++i) {
        int value = data[i] + brightness;
        value = (value * contrast) / 100;
        value = value > 255 ? 255 : value < 0 ? 0 : value;
        data[i] = (unsigned char) value;
    }

    // Write output file header
    fprintf(output_file, "P6\n");
    fprintf(output_file, "%d %d\n", width, height);
    fprintf(output_file, "%d\n", max_value);

    // Write output file data
    fwrite(data, sizeof(unsigned char), 3 * width * height, output_file);

    free(data);
}