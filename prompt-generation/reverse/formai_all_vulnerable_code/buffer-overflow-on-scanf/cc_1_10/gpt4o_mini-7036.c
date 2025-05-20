//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 256
#define JPEG_HEADER "\xFF\xD8\xFF"
#define PNG_HEADER "\x89PNG\r\n\x1A\n"

// Metadata structure
typedef struct {
    char title[MAX_METADATA_SIZE];
    char author[MAX_METADATA_SIZE];
    char date[MAX_METADATA_SIZE];
    char comments[MAX_METADATA_SIZE];
} Metadata;

// Function declarations
int extract_jpeg_metadata(const char *filename, Metadata *meta);
int extract_png_metadata(const char *filename, Metadata *meta);
void display_metadata(const Metadata *meta);

int main() {
    char input_file[MAX_METADATA_SIZE];
    int file_type; // 1 for JPEG, 2 for PNG

    printf("Metadata Extractor\n");
    printf("Enter the file name (JPEG/PNG): ");
    scanf("%s", input_file);

    printf("Select file type (1 for JPEG, 2 for PNG): ");
    scanf("%d", &file_type);

    Metadata meta = {0};
    int result = 0;

    if (file_type == 1) {
        result = extract_jpeg_metadata(input_file, &meta);
    } else if (file_type == 2) {
        result = extract_png_metadata(input_file, &meta);
    } else {
        printf("Invalid file type selected.\n");
        return 1;
    }

    if (result == 0) {
        display_metadata(&meta);
    } else {
        printf("Failed to extract metadata from %s.\n", input_file);
    }

    return 0;
}

int extract_jpeg_metadata(const char *filename, Metadata *meta) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    unsigned char buffer[2];
    fread(buffer, 1, 2, file);

    // Check for JPEG header
    if (buffer[0] != JPEG_HEADER[0] || buffer[1] != JPEG_HEADER[1]) {
        fclose(file);
        printf("Not a valid JPEG file.\n");
        return -1;
    }

    // For simplicity, let's assume static values as placeholders.
    strncpy(meta->title, "Sample JPEG Image", MAX_METADATA_SIZE);
    strncpy(meta->author, "John Doe", MAX_METADATA_SIZE);
    strncpy(meta->date, "2023:01:01 10:00:00", MAX_METADATA_SIZE);
    strncpy(meta->comments, "No comments available.", MAX_METADATA_SIZE);

    fclose(file);
    return 0;
}

int extract_png_metadata(const char *filename, Metadata *meta) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    unsigned char buffer[8];
    fread(buffer, 1, 8, file);

    // Check for PNG header
    if (memcmp(buffer, PNG_HEADER, 8) != 0) {
        fclose(file);
        printf("Not a valid PNG file.\n");
        return -1;
    }

    // Again, we'll use static metadata for demonstration
    strncpy(meta->title, "Sample PNG Image", MAX_METADATA_SIZE);
    strncpy(meta->author, "Jane Smith", MAX_METADATA_SIZE);
    strncpy(meta->date, "2023:01:01 10:00:00", MAX_METADATA_SIZE);
    strncpy(meta->comments, "No comments available.", MAX_METADATA_SIZE);

    fclose(file);
    return 0;
}

void display_metadata(const Metadata *meta) {
    printf("\nMetadata Details:\n");
    printf("Title: %s\n", meta->title);
    printf("Author: %s\n", meta->author);
    printf("Date: %s\n", meta->date);
    printf("Comments: %s\n", meta->comments);
}