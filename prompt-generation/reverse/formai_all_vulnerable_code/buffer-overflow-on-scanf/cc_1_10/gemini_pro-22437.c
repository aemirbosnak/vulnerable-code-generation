//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Welcome to the Neon City Metadata Extractor, runner!

// Function prototypes
int extract_metadata(char *filename);
void print_metadata(char *metadata);

int main() {
    // Set the stage
    printf("\nNeon City's skyline glitters like a thousand shards of ice, casting an ethereal glow on the towering skyscrapers that pierce the heavens.\n");
    printf("You, a skilled netrunner, navigate the labyrinthine streets, your cyberdeck humming with anticipation.\n");
    printf("Your mission tonight: extract precious metadata from a heavily encrypted file.\n\n");

    // Get the target file
    char filename[50];
    printf("Enter the target file: ");
    scanf("%s", filename);

    // Commence the extraction
    int success = extract_metadata(filename);

    // Handle success or failure
    if (success) {
        printf("\n+++ Extraction successful, chummer! +++\n");
    }
    else {
        printf("\n--- Extraction failed. Better luck next time, street rat. ---\n");
        return EXIT_FAILURE;
    }

    // Display the extracted metadata
    print_metadata(filename);

    // Fade into the night
    printf("\nThe neon lights flicker and dance, and you disappear into the shadows, your mission accomplished.\n");

    return EXIT_SUCCESS;
}

int extract_metadata(char *filename) {
    // Open the file and check it exists
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return 0;
    }

    // Seek to the end of the file to get its size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);

    // Read the entire file into a buffer
    char *buffer = malloc(size);
    fseek(file, 0, SEEK_SET);
    fread(buffer, size, 1, file);

    // Close the file
    fclose(file);

    // Simulate decryption of the buffer
    srand(time(NULL));
    for (long i = 0; i < size; i++) {
        buffer[i] ^= rand() % 256;
    }

    // Extract the metadata as a string
    char *metadata = strstr(buffer, "METADATA:");
    if (!metadata) {
        fprintf(stderr, "Could not find metadata in file %s\n", filename);
        return 0;
    }
    metadata += strlen("METADATA:");

    return 1;
}

void print_metadata(char *metadata) {
    // Print the metadata
    printf("\n--- Extracted Metadata ---\n");
    printf("%s\n", metadata);
}