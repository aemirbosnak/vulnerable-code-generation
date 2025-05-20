//FormAI DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 256
#define MAX_COLOR_VALUE 256

struct Image {
    char type[3];
    int width;
    int height;
    int color_depth;
    unsigned char* data;
};

int main() {
    int option;
    char input_file_name[MAX_FILE_NAME_SIZE];
    char output_file_name[MAX_FILE_NAME_SIZE];
    struct Image img;
    FILE* fptr_input;
    FILE* fptr_output;
    unsigned char red, green, blue, gray;
    int i, x, y;
    
    printf("Welcome to the C Image Editor!\n");
    
    while (1) {
        printf("\n1. Load image\n");
        printf("2. Convert to grayscale\n");
        printf("3. Invert colors\n");
        printf("4. Add border\n");
        printf("5. Save image\n");
        printf("6. Exit\n");
        printf("Please select an option: ");
        scanf("%d", &option);
        printf("\n");
        
        switch (option) {
            case 1:
                printf("Please enter the name of the image file to load: ");
                scanf("%s", input_file_name);
                
                fptr_input = fopen(input_file_name, "rb");
                if (fptr_input == NULL) {
                    printf("Error opening file. Please make sure the file exists and you have permission to access it.\n");
                    break;
                }
                
                // Read header
                fscanf(fptr_input, "%2s", img.type);
                fscanf(fptr_input, "%d", &img.width);
                fscanf(fptr_input, "%d", &img.height);
                fscanf(fptr_input, "%d", &img.color_depth);
                
                // Read data
                img.data = malloc(sizeof(unsigned char) * img.width * img.height * 3);
                fread(img.data, sizeof(unsigned char), img.width * img.height * 3, fptr_input);
                
                fclose(fptr_input);
                
                printf("Image loaded successfully.\n");
                break;
                
            case 2:
                // Convert to grayscale
                if (img.data == NULL) {
                    printf("Please load an image first.\n");
                    break;
                }
                
                for (i = 0; i < img.width * img.height * 3; i += 3) {
                    red = img.data[i];
                    green = img.data[i+1];
                    blue = img.data[i+2];
                    
                    gray = (unsigned char) (0.2126 * red + 0.7152 * green + 0.0722 * blue);
                    img.data[i] = gray;
                    img.data[i+1] = gray;
                    img.data[i+2] = gray;
                }
                
                printf("Image converted to grayscale.\n");
                break;
                
            case 3:
                // Invert colors
                if (img.data == NULL) {
                    printf("Please load an image first.\n");
                    break;
                }
                
                for (i = 0; i < img.width * img.height * 3; i++) {
                    img.data[i] = MAX_COLOR_VALUE - img.data[i];
                }
                
                printf("Colors inverted.\n");
                break;
                
            case 4:
                // Add border
                if (img.data == NULL) {
                    printf("Please load an image first.\n");
                    break;
                }
                
                printf("Please enter the width of the border: ");
                scanf("%d", &x);
                
                // Allocate new image data with border
                unsigned char* new_data = malloc(sizeof(unsigned char) * (img.width + 2*x) * (img.height + 2*x) * 3);
                
                // Copy center of image to new data
                for (y = 0; y < img.height; y++) {
                    for (x = 0; x < img.width; x++) {
                        new_data[((y + x + img.width + 2*x) * 3) + 0] = img.data[(y * img.width + x) * 3 + 0];
                        new_data[((y + x + img.width + 2*x) * 3) + 1] = img.data[(y * img.width + x) * 3 + 1];
                        new_data[((y + x + img.width + 2*x) * 3) + 2] = img.data[(y * img.width + x) * 3 + 2];
                    }
                }
                
                // Fill borders with black
                memset(new_data, 0, sizeof(unsigned char) * (img.width + 2*x) * x * 3);
                memset(new_data + sizeof(unsigned char) * (img.width + 2*x) * (img.height + x) * 3, 0,
                       sizeof(unsigned char) * (img.width + 2*x) * x * 3);
                for (y = 0; y < img.height + 2*x; y++) {
                    memset(new_data + ((y * (img.width + 2*x)) * 3), 0, sizeof(unsigned char) * x * 3);
                    memset(new_data + ((y * (img.width + 2*x) + img.width + x) * 3), 0, sizeof(unsigned char) * x * 3);
                }
                
                // Free old data and assign new data to img
                free(img.data);
                img.data = new_data;
                img.width += 2*x;
                img.height += 2*x;
                
                printf("Border added.\n");
                break;
                
            case 5:
                // Save image
                if (img.data == NULL) {
                    printf("Please load an image first.\n");
                    break;
                }
                
                printf("Please enter the name of the output file: ");
                scanf("%s", output_file_name);
                
                fptr_output = fopen(output_file_name, "wb");
                if (fptr_output == NULL) {
                    printf("Error opening file. Please make sure you have permission to access the output directory.\n");
                    break;
                }
                
                // Write header
                fprintf(fptr_output, "%s\n", img.type);
                fprintf(fptr_output, "%d %d\n", img.width, img.height);
                fprintf(fptr_output, "%d\n", img.color_depth);
                
                // Write data
                fwrite(img.data, sizeof(unsigned char), img.width * img.height * 3, fptr_output);
                fclose(fptr_output);
                
                printf("Image saved successfully.\n");
                break;
                
            case 6:
                // Exit
                if (img.data != NULL) {
                    free(img.data);
                }
                
                printf("Thank you for using the C Image Editor!\n");
                exit(0);
                break;
                
            default:
                printf("Invalid option. Please enter a number between 1 and 6.\n");
                break;
        }
    }
}