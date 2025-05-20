//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from a given file
void extract_metadata(char *filename) {
    FILE *file;
    char buffer[1024]; // Buffer to read data from file
    char *extension; // Pointer to store file extension
    int size; // Size of the file

    // Open the file in read-only mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Get the file extension
    extension = strrchr(filename, '.');
    if (extension == NULL) {
        printf("File extension not found\n");
        fclose(file);
        exit(1);
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Extract metadata from the file
    switch (extension[1]) {
        case 't': // Text file
            printf("File type: Text\n");
            printf("File size: %d bytes\n", size);
            break;
        case 'p': // Image file (PNG, JPG, etc.)
            printf("File type: Image\n");
            printf("File size: %d bytes\n", size);
            break;
        case 'a': // Audio file (MP3, WAV, etc.)
            printf("File type: Audio\n");
            printf("File size: %d bytes\n", size);
            break;
        case 'v': // Video file (MP4, AVI, etc.)
            printf("File type: Video\n");
            printf("File size: %d bytes\n", size);
            break;
        default:
            printf("File type not supported\n");
            break;
    }

    // Close the file
    fclose(file);
}

int main() {
    char filename[1024];

    // Get the filename from user input
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Extract metadata from the file
    extract_metadata(filename);

    return 0;
}