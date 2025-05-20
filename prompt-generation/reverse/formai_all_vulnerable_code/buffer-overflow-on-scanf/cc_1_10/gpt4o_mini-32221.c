//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A structure to hold image metadata
typedef struct {
    char filename[100];
    char format[10];
    int width;
    int height;
    int size; // size in bytes
    time_t created_time;
} ImageMetadata;

// Function prototypes
void printBanner();
void collectMetadata(ImageMetadata *img);
void displayMetadata(const ImageMetadata *img);
void saveMetadata(const ImageMetadata *img);

// Main function
int main() {
    printBanner();

    ImageMetadata img;
    collectMetadata(&img);

    char choice;
    printf("\nWould you like to see the metadata? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        displayMetadata(&img);
    }
    
    printf("\nWould you like to save the metadata to a file? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        saveMetadata(&img);
        printf("Metadata saved successfully!\n");
    }

    printf("\nThank you for using the Metadata Extractor!\n");
    return 0;
}

// Function to print a retro-style banner
void printBanner() {
    printf("*******************************\n");
    printf("*     Metadata Extractor      *\n");
    printf("*      Retro Version 1.0      *\n");
    printf("*      By: The Retro Team     *\n");
    printf("*******************************\n\n");
}

// Function to collect metadata
void collectMetadata(ImageMetadata *img) {
    printf("Enter the filename (with extension): ");
    scanf("%s", img->filename);
    
    printf("Enter the image format (e.g., jpg, png): ");
    scanf("%s", img->format);
    
    printf("Enter the width of the image (in pixels): ");
    scanf("%d", &img->width);
    
    printf("Enter the height of the image (in pixels): ");
    scanf("%d", &img->height);
    
    printf("Enter the size of the image (in bytes): ");
    scanf("%d", &img->size);
    
    img->created_time = time(NULL);
}

// Function to display metadata
void displayMetadata(const ImageMetadata *img) {
    printf("\n--- Image Metadata ---\n");
    printf("Filename: %s\n", img->filename);
    printf("Format: %s\n", img->format);
    printf("Width: %d px\n", img->width);
    printf("Height: %d px\n", img->height);
    printf("Size: %d bytes\n", img->size);
    printf("Created Time: %s", ctime(&img->created_time)); // Convert to human-readable format
    printf("----------------------\n");
}

// Function to save metadata to a file
void saveMetadata(const ImageMetadata *img) {
    FILE *file = fopen("metadata.txt", "w");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "Filename: %s\n", img->filename);
    fprintf(file, "Format: %s\n", img->format);
    fprintf(file, "Width: %d px\n", img->width);
    fprintf(file, "Height: %d px\n", img->height);
    fprintf(file, "Size: %d bytes\n", img->size);
    fprintf(file, "Created Time: %s", ctime(&img->created_time)); // Convert to human-readable format

    fclose(file);
}