//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void print_jpeg_metadata(const char *filename);
void print_png_metadata(const char *filename);
void print_mp3_metadata(const char *filename);
void print_text_metadata(const char *filename);
void display_metadata(const char *filename);

int main() {
    char filename[256];

    printf("Welcome to the Metadata Extractor!\n");
    printf("---------------------------------------------------\n");

    while (1) {
        printf("Please enter a filename (or type 'exit' to quit): ");
        scanf("%s", filename);

        if (strcmp(filename, "exit") == 0) {
            printf("Exiting the Metadata Extractor. Goodbye!\n");
            break;
        }

        display_metadata(filename);
    }

    return 0;
}

// Function to display metadata based on file extension
void display_metadata(const char *filename) {
    const char *ext = strrchr(filename, '.');

    if (ext == NULL) {
        printf("Error: No file extension found!\n");
        return;
    }

    if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0) {
        print_jpeg_metadata(filename);
    } else if (strcmp(ext, ".png") == 0) {
        print_png_metadata(filename);
    } else if (strcmp(ext, ".mp3") == 0) {
        print_mp3_metadata(filename);
    } else if (strcmp(ext, ".txt") == 0) {
        print_text_metadata(filename);
    } else {
        printf("Error: Unsupported file type!\n");
    }
}

void print_jpeg_metadata(const char *filename) {
    // Placeholder for actual JPEG metadata extraction logic
    printf("Extracting JPEG metadata from %s...\n", filename);
    // Simulated metadata
    printf("JPEG Metadata:\n");
    printf(" - Resolution: 1920x1080\n");
    printf(" - Color Depth: 24 bits\n");
    printf(" - Camera Model: Canon EOS 80D\n");
    printf(" - Date Taken: %s\n", "2023-10-05");
    printf("---------------------------------------------------\n");
}

void print_png_metadata(const char *filename) {
    // Placeholder for actual PNG metadata extraction logic
    printf("Extracting PNG metadata from %s...\n", filename);
    // Simulated metadata
    printf("PNG Metadata:\n");
    printf(" - Resolution: 1200x800\n");
    printf(" - Color Type: RGB with alpha\n");
    printf(" - Compression Method: 1\n");
    printf(" - Last Modified: %s\n", "2023-10-04");
    printf("---------------------------------------------------\n");
}

void print_mp3_metadata(const char *filename) {
    // Placeholder for actual MP3 metadata extraction logic
    printf("Extracting MP3 metadata from %s...\n", filename);
    // Simulated metadata
    printf("MP3 Metadata:\n");
    printf(" - Artist: Imagine Dragons\n");
    printf(" - Album: Evolve\n");
    printf(" - Track: Believer\n");
    printf(" - Duration: 3:24\n");
    printf("---------------------------------------------------\n");
}

void print_text_metadata(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open text file %s!\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END); // Move to the end of the file
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET); // Move back to the beginning of the file

    // Simulated metadata
    printf("Extracting text file metadata from %s...\n", filename);
    printf("Text File Metadata:\n");
    printf(" - File Size: %ld bytes\n", file_size);

    char creation_time[100];
    time_t now = time(NULL);
    strftime(creation_time, sizeof(creation_time), "%Y-%m-%d %H:%M:%S", localtime(&now));
    printf(" - Creation Date: %s\n", creation_time);
    
    fclose(file);
    printf("---------------------------------------------------\n");
}