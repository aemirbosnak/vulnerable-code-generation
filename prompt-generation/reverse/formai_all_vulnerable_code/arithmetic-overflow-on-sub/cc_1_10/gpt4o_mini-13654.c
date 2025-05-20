//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "WATERMARK" // The secret watermark
#define WATERMARK_LENGTH (sizeof(WATERMARK)/sizeof(WATERMARK[0]) - 1)

void embed_watermark(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        fclose(input_file);
        perror("Failed to create output file");
        exit(EXIT_FAILURE);
    }

    int char_counter = 0;
    int c;
    while ((c = fgetc(input_file)) != EOF) {
        // Embedding the watermark into every 10th character
        if (char_counter % 10 == 0 && char_counter / 10 < WATERMARK_LENGTH) {
            c += WATERMARK[char_counter / 10]; // Modify the ASCII value
        }
        fputc(c, output_file);
        char_counter++;
    }

    fclose(input_file);
    fclose(output_file);
    printf("Watermark embedded successfully!\n");
}

void retrieve_watermark(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int char_counter = 0;
    int c;
    char retrieved_watermark[WATERMARK_LENGTH + 1] = {0}; // Buffer for watermark

    while ((c = fgetc(file)) != EOF) {
        // Extract the watermark embedded in every 10th character
        if (char_counter % 10 == 0 && char_counter / 10 < WATERMARK_LENGTH) {
            retrieved_watermark[char_counter / 10] = c - WATERMARK[char_counter / 10];
        }
        char_counter++;
    }

    fclose(file);
    printf("Extracted Watermark: %s\n", retrieved_watermark);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    embed_watermark(argv[1], argv[2]);
    retrieve_watermark(argv[2]);

    return EXIT_SUCCESS;
}