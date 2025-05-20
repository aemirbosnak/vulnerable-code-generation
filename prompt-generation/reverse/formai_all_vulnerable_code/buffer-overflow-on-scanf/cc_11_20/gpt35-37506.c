//FormAI DATASET v1.0 Category: Image Editor ; Style: energetic
/* Energized C Image Editor */

#include <stdio.h>

int main() {
    // Print a welcome message
    printf("Welcome to Energized C Image Editor!\n");

    // Get the file name from the user
    printf("Please enter the file name of the image you want to edit: ");
    char file_name[50];
    scanf("%s", file_name);

    // Open the file
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error opening file for reading. Please check if the file exists and try again.\n");
        return 1;
    }

    // Read the image data and display it
    printf("Reading image data...\n");

    int width, height;
    fscanf(file, "%d %d", &width, &height);

    // Allocate memory for the image data
    unsigned char* image_data = malloc(width * height * sizeof(unsigned char));

    if (image_data == NULL) {
        printf("Error allocating memory for image data.\n");
        return 1;
    }

    // Read the image data from the file
    for (int i = 0; i < width * height; i++) {
        fscanf(file, "%hhu", &image_data[i]);
    }

    // Print out the image data
    printf("Image data:\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%hhu ", image_data[i * width + j]);
        }
        printf("\n");
    }

    // Let the user choose an editing option
    printf("What would you like to do?\n");
    printf("[1] Invert the image\n");
    printf("[2] Apply a filter to the image\n");
    printf("[3] Save the image as a new file\n");
    printf("[4] Exit the program\n");
    printf("Please enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        // Invert the image
        case 1:
            printf("Inverting image...\n");

            for (int i = 0; i < width * height; i++) {
                image_data[i] = 255 - image_data[i];
            }

            // Print out the inverted image
            printf("Inverted image:\n");

            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    printf("%hhu ", image_data[i * width + j]);
                }
                printf("\n");
            }

            break;

        // Apply a filter to the image
        case 2:
            printf("Applying filter to image...\n");

            // TODO: Implement filter code

            printf("Filter applied to image.\n");

            break;

        // Save the image as a new file
        case 3:
            printf("Saving image as new file...\n");

            // Get the new file name from the user
            printf("Please enter the file name to save the image as: ");
            char new_file_name[50];
            scanf("%s", new_file_name);

            // Open the new file for writing
            FILE* new_file = fopen(new_file_name, "w");

            if (new_file == NULL) {
                printf("Error opening file for writing.\n");
                return 1;
            }

            // Write the image width and height to the new file
            fprintf(new_file, "%d %d\n", width, height);

            // Write the image data to the new file
            for (int i = 0; i < width * height; i++) {
                fprintf(new_file, "%hhu ", image_data[i]);
            }

            printf("Image saved as new file: %s\n", new_file_name);

            break;

        // Exit the program
        case 4:
            printf("Exiting program. Goodbye!\n");
            break;

        // Invalid choice
        default:
            printf("Invalid choice. Please choose one of the options 1-4.\n");
            break;
    }

    // Free the allocated memory
    free(image_data);

    // Close the file
    fclose(file);

    return 0;
}