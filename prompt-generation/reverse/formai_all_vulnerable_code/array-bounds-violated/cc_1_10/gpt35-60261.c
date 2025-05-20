//FormAI DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_COMMAND_LENGTH 50

// Function to read image file
void read_image_file(char* file_name, int* width_ptr, int* height_ptr, int** image_data_ptr) {
    // Open the file in binary mode
    FILE* image_file = fopen(file_name, "rb");
    
    // Check if file opened successfully
    if (!image_file) {
        printf("Unable to open file!\n");
        exit(1);
    }
    
    // Read width, height and pixel data from file
    fread(width_ptr, sizeof(int), 1, image_file);
    fread(height_ptr, sizeof(int), 1, image_file);
    
    int image_size = (*width_ptr) * (*height_ptr);
    *image_data_ptr = (int*) malloc(image_size * sizeof(int));
    
    fread(*image_data_ptr, sizeof(int), image_size, image_file);
    
    // Close the file
    fclose(image_file);
}

// Function to write image file
void write_image_file(char* file_name, int width, int height, int* image_data) {
    // Open the file
    FILE* image_file = fopen(file_name, "wb");
    
    // Check if file opened successfully
    if (!image_file) {
        printf("Unable to open file!\n");
        exit(1);
    }
    
    // Write width, height and pixel data to file
    fwrite(&width, sizeof(int), 1, image_file);
    fwrite(&height, sizeof(int), 1, image_file);
    
    int image_size = width * height;
    fwrite(image_data, sizeof(int), image_size, image_file);
    
    // Close the file
    fclose(image_file);
}

int main(void) {
    int width, height, *image_data;
    char file_name[MAX_FILENAME_LENGTH], command[MAX_COMMAND_LENGTH];
    
    // Get input file name from user
    printf("Enter input file name: ");
    fgets(file_name, MAX_FILENAME_LENGTH, stdin);
    
    // Remove newline character from the end of file name
    file_name[strlen(file_name)-1] = '\0';
    
    // Read image data from file
    read_image_file(file_name, &width, &height, &image_data);
    
    // Main program loop
    while(1) {
        // Get user command
        printf("Enter command (quit, invert, blur, save): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        
        // Remove newline character from the end of command
        command[strlen(command)-1] = '\0';
        
        // Check command and perform appropriate action
        if (strcmp(command, "invert") == 0) {
            for (int i = 0; i < width * height; i++) {
                image_data[i] = (image_data[i] ^ 0xFFFFFF);
            }
        }
        else if (strcmp(command, "blur") == 0) {
            int temp_data[width * height];
            memcpy(temp_data, image_data, width * height * sizeof(int));
            
            for (int i = 1; i < height-1; i++) {
                for (int j = 1; j < width-1; j++) {
                    int sum = 0;
                    
                    for (int k = -1; k <= 1; k++) {
                        for (int l = -1; l <= 1; l++) {
                            sum += temp_data[(i+k)*width + (j+l)];
                        }
                    }
                    
                    image_data[i*width + j] = sum / 9;
                }
            }
        }
        else if (strcmp(command, "save") == 0) {
            char output_file_name[MAX_FILENAME_LENGTH];
            
            // Get output file name from user
            printf("Enter output file name: ");
            fgets(output_file_name, MAX_FILENAME_LENGTH, stdin);
            
            // Remove newline character from the end of file name
            output_file_name[strlen(output_file_name)-1] = '\0';
            
            // Write image data to file
            write_image_file(output_file_name, width, height, image_data);
            
            printf("Image saved to file!\n");
        }
        else if (strcmp(command, "quit") == 0) {
            // Exit loop
            break;
        }
        else {
            printf("Invalid command!\n");
        }
    }
    
    // Free memory allocated for image data
    free(image_data);
    
    return 0;
}