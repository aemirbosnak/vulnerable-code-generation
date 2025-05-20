//FormAI DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 5000000 // 5MB Maximum File Size

// Function Prototypes
int getFileSize(FILE *file);
void printMenu();
void grayscale(char *filename);
void mirror(char *filename);
void invertColors(char *filename);
void blur(char *filename);
void edgeDetection(char *filename);
void rotate(char *filename);

int main()
{
    // Initialize variables
    char filename[100];
    int choice;

    // Display main menu
    while (true)
    {
        printMenu();

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the filename: ");
            scanf("%s", filename);
            grayscale(filename);
            break;
        case 2:
            printf("\nEnter the filename: ");
            scanf("%s", filename);
            mirror(filename);
            break;
        case 3:
            printf("\nEnter the filename: ");
            scanf("%s", filename);
            invertColors(filename);
            break;
        case 4:
            printf("\nEnter the filename: ");
            scanf("%s", filename);
            blur(filename);
            break;
        case 5:
            printf("\nEnter the filename: ");
            scanf("%s", filename);
            edgeDetection(filename);
            break;
        case 6:
            printf("\nEnter the filename: ");
            scanf("%s", filename);
            rotate(filename);
            break;
        case 7:
            printf("\nExiting the program.\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}

// Function to get the file size
int getFileSize(FILE *file)
{
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return size;
}

// Function to display the main menu
void printMenu()
{
    printf("\n\n");
    printf("------------------------------------\n");
    printf("|      C Image Editor Program      |\n");
    printf("------------------------------------\n");
    printf("| 1. Convert to Grayscale          |\n");
    printf("| 2. Mirror                        |\n");
    printf("| 3. Invert Colors                 |\n");
    printf("| 4. Blur                          |\n");
    printf("| 5. Edge Detection                |\n");
    printf("| 6. Rotate                        |\n");
    printf("| 7. Exit                          |\n");
    printf("------------------------------------\n");
}

// Function to convert the image to grayscale
void grayscale(char *filename)
{
    // Open the file
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("\nError: Could not open the file.\n");
        return;
    }

    // Get the file size
    int size = getFileSize(file);

    // Check if the file size is too large
    if (size > MAX_FILE_SIZE)
    {
        printf("\nError: The file is too large. Maximum file size is 5MB.\n");
        fclose(file);
        return;
    }

    // Allocate memory for the array
    unsigned char *image = (unsigned char *)malloc(size);

    // Read the file into the array
    fread(image, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Loop through the array and convert the image to grayscale
    for (int i = 0; i < size; i += 3)
    {
        // Calculate the grayscale value
        unsigned char gray = (image[i] + image[i + 1] + image[i + 2]) / 3;

        // Set the pixels to the grayscale value
        image[i] = gray;
        image[i + 1] = gray;
        image[i + 2] = gray;
    }

    // Open the file for writing
    file = fopen(filename, "wb");

    // Write the new image to the file
    fwrite(image, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Free the memory
    free(image);

    printf("\nGrayscale conversion completed successfully.\n");
}

// Function to mirror the image horizontally
void mirror(char *filename)
{
    // Open the file
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("\nError: Could not open the file.\n");
        return;
    }

    // Get the file size
    int size = getFileSize(file);

    // Check if the file size is too large
    if (size > MAX_FILE_SIZE)
    {
        printf("\nError: The file is too large. Maximum file size is 5MB.\n");
        fclose(file);
        return;
    }

    // Allocate memory for the array
    unsigned char *image = (unsigned char *)malloc(size);

    // Read the file into the array
    fread(image, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Loop through the array and mirror the image horizontally
    for (int i = 0; i < size; i += 3)
    {
        // Swap the pixels
        unsigned char temp = image[i];
        image[i] = image[i + 2];
        image[i + 2] = temp;
    }

    // Open the file for writing
    file = fopen(filename, "wb");

    // Write the new image to the file
    fwrite(image, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Free the memory
    free(image);

    printf("\nHorizontal mirror completed successfully.\n");
}

// Function to invert the colors
void invertColors(char *filename)
{
    // Open the file
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("\nError: Could not open the file.\n");
        return;
    }

    // Get the file size
    int size = getFileSize(file);

    // Check if the file size is too large
    if (size > MAX_FILE_SIZE)
    {
        printf("\nError: The file is too large. Maximum file size is 5MB.\n");
        fclose(file);
        return;
    }

    // Allocate memory for the array
    unsigned char *image = (unsigned char *)malloc(size);

    // Read the file into the array
    fread(image, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Loop through the array and invert the colors
    for (int i = 0; i < size; i += 3)
    {
        // Invert the colors
        image[i] = 255 - image[i];
        image[i + 1] = 255 - image[i + 1];
        image[i + 2] = 255 - image[i + 2];
    }

    // Open the file for writing
    file = fopen(filename, "wb");

    // Write the new image to the file
    fwrite(image, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Free the memory
    free(image);

    printf("\nColor inversion completed successfully.\n");
}

// Function to blur the image
void blur(char *filename)
{
    // Open the file
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("\nError: Could not open the file.\n");
        return;
    }

    // Get the file size
    int size = getFileSize(file);

    // Check if the file size is too large
    if (size > MAX_FILE_SIZE)
    {
        printf("\nError: The file is too large. Maximum file size is 5MB.\n");
        fclose(file);
        return;
    }

    // Allocate memory for the array
    unsigned char *image = (unsigned char *)malloc(size);

    // Read the file into the array
    fread(image, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Set the blur radius
    int blurRadius = 3;

    // Loop through the array and apply the blur effect
    for (int i = blurRadius; i < size - blurRadius; i += 3)
    {
        // Get the average color of the surrounding pixels
        int red = 0;
        int green = 0;
        int blue = 0;
        int count = 0;

        for (int j = i - (blurRadius * 3); j <= i + (blurRadius * 3); j += 3)
        {
            red += image[j];
            green += image[j + 1];
            blue += image[j + 2];
            count++;
        }

        red /= count;
        green /= count;
        blue /= count;

        // Set the pixel to the average color
        image[i] = red;
        image[i + 1] = green;
        image[i + 2] = blue;
    }

    // Open the file for writing
    file = fopen(filename, "wb");

    // Write the new image to the file
    fwrite(image, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Free the memory
    free(image);

    printf("\nBlur effect completed successfully.\n");
}

// Function to apply edge detection to the image
void edgeDetection(char *filename)
{
    // Open the file
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("\nError: Could not open the file.\n");
        return;
    }

    // Get the file size
    int size = getFileSize(file);

    // Check if the file size is too large
    if (size > MAX_FILE_SIZE)
    {
        printf("\nError: The file is too large. Maximum file size is 5MB.\n");
        fclose(file);
        return;
    }

    // Allocate memory for the array
    unsigned char *image = (unsigned char *)malloc(size);

    // Read the file into the array
    fread(image, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Loop through the array and apply the edge detection effect
    for (int i = 0; i < size; i += 3)
    {
        // Get the surrounding pixel colors
        int pixel[9];

        pixel[0] = (i > 2) ? image[i - 3] : 0;
        pixel[1] = (i > 5) ? image[i - 6] : 0;
        pixel[2] = (i > 8) ? image[i - 9] : 0;
        pixel[3] = (i > size - 8) ? image[i + 9] : 0;
        pixel[4] = (i > size - 5) ? image[i + 6] : 0;
        pixel[5] = (i > size - 2) ? image[i + 3] : 0;
        pixel[6] = image[i];
        pixel[7] = image[i + 1];
        pixel[8] = image[i + 2];

        // Calculate the edge detection value
        int edge = 0;

        edge -= pixel[0];
        edge -= pixel[1];
        edge -= pixel[2];
        edge += pixel[3];
        edge += pixel[4];
        edge += pixel[5];
        edge *= 2;
        edge -= pixel[6];
        edge -= pixel[7];
        edge -= pixel[8];

        // Set the edge detection value as the pixel color
        image[i] = edge;
        image[i + 1] = edge;
        image[i + 2] = edge;
    }

    // Open the file for writing
    file = fopen(filename, "wb");

    // Write the new image to the file
    fwrite(image, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Free the memory
    free(image);

    printf("\nEdge detection effect completed successfully.\n");
}

// Function to rotate the image clockwise
void rotate(char *filename)
{
    // Open the file
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        printf("\nError: Could not open the file.\n");
        return;
    }

    // Get the file size
    int size = getFileSize(file);

    // Check if the file size is too large
    if (size > MAX_FILE_SIZE)
    {
        printf("\nError: The file is too large. Maximum file size is 5MB.\n");
        fclose(file);
        return;
    }

    // Allocate memory for the array
    unsigned char *image = (unsigned char *)malloc(size);

    // Read the file into the array
    fread(image, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Allocate memory for the rotated image array
    unsigned char *rotatedImage = (unsigned char *)malloc(size);

    // Loop through the array and rotate the image
    int index = 0;
    for (int i = 0; i < size; i += 3)
    {
        int row = i / (3 * 640);
        int col = (i / 3) % 640;

        int newCol = row;
        int newRow = 639 - col;

        int newIndex = (newRow * 3 * 640) + (newCol * 3);

        rotatedImage[newIndex] = image[i];
        rotatedImage[newIndex + 1] = image[i + 1];
        rotatedImage[newIndex + 2] = image[i + 2];
    }

    // Open the file for writing
    file = fopen(filename, "wb");

    // Write the new image to the file
    fwrite(rotatedImage, sizeof(unsigned char), size, file);

    // Close the file
    fclose(file);

    // Free the memory
    free(image);
    free(rotatedImage);

    printf("\nRotation completed successfully.\n");
}