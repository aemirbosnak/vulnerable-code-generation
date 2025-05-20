//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "My Watermark"

void embed_watermark(FILE *in_file, FILE *out_file);
void extract_watermark(FILE *in_file);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    FILE *in_file = fopen(argv[1], "rb");
    if (in_file == NULL) {
        printf("Error: Cannot open the input file.\n");
        exit(EXIT_FAILURE);
    }

    FILE *out_file = fopen(argv[2], "wb");
    if (out_file == NULL) {
        printf("Error: Cannot create the output file.\n");
        exit(EXIT_FAILURE);
    }

    embed_watermark(in_file, out_file);

    fclose(in_file);
    fclose(out_file);
    
    extract_watermark(out_file);

    return 0;
}

void embed_watermark(FILE *in_file, FILE *out_file) {
    char watermark[100];
    sprintf(watermark, "%s", WATERMARK);
    int watermark_len = strlen(watermark);

    // Write the watermark length to the output file
    fwrite(&watermark_len, sizeof(watermark_len), 1, out_file);

    // Write the watermark to the output file
    fwrite(watermark, 1, watermark_len, out_file);

    // Copy the rest of the input file to the output file
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), in_file)) > 0) {
        fwrite(buffer, 1, bytes_read, out_file);
    }
}

void extract_watermark(FILE *in_file) {
    int watermark_len;
    fread(&watermark_len, sizeof(watermark_len), 1, in_file);

    char *watermark = malloc(watermark_len + 1);

    fread(watermark, 1, watermark_len, in_file);
    watermark[watermark_len] = '\0';

    printf("Extracted Watermark: %s\n", watermark);

    free(watermark);
}