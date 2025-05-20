//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input_file, *output_file;
    char input_filename[50], output_filename[50], watermark[50];
    int bytes_read, watermark_len, i=0;
    unsigned char buffer[4096];

    // get input file name
    printf("Enter input file name (with extension):\n");
    scanf("%s", input_filename);

    // open input file
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // get output file name
    printf("Enter output file name (with extension):\n");
    scanf("%s", output_filename);

    // open output file
    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error creating output file!\n");
        exit(1);
    }

    // get watermark
    printf("Enter watermark:\n");
    scanf("%s", watermark);

    // get length of watermark
    watermark_len = strlen(watermark);

    // write watermark length to output file
    fwrite(&watermark_len, sizeof(int), 1, output_file);

    // write watermark to output file
    fwrite(watermark, sizeof(char), watermark_len, output_file);

    // read input file in chunks of 4096 bytes
    while ((bytes_read = fread(buffer, sizeof(unsigned char), 4096, input_file)) > 0) {
        // iterate through buffer and add watermark to least significant bit of each byte
        for (i = 0; i < bytes_read; i++) {
            buffer[i] = (buffer[i] & ~1) | (watermark[i % watermark_len] & 1);
        }
        // write buffer to output file
        fwrite(buffer, sizeof(unsigned char), bytes_read, output_file);
    }

    // close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Watermarking successful!\n");

    return 0;
}