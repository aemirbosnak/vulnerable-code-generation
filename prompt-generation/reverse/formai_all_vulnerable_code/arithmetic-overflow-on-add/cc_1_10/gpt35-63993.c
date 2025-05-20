//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: dynamic
/*
Dynamic digital watermarking program in C
by John Doe

This program takes in a text file and inserts a digital watermark
by incrementing every ASCII code point by a certain value. The watermark
value is determined based on the sum of ASCII codes in the original text file.

Example usage:
./watermark file.txt

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("Usage: %s file.txt\n", argv[0]);
        return 1;
    }
    
    char *filename = argv[1];
    FILE *file = fopen(filename, "r+");
    
    if (!file) {
        printf("Error: cannot open file %s\n", filename);
        return 1;
    }
    
    // Get original file size to calculate watermark
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    
    // Calculate watermark
    int watermark = 0;
    for (int i = 0; i < size; i++) {
        watermark += fgetc(file);
    }
    
    // Create dynamic watermark based on original file size and watermark
    int dynamic_watermark = size * watermark % 128;
    
    // Reset file pointer to beginning
    rewind(file);
    
    // Apply dynamic watermark to file
    int c;
    while ((c = fgetc(file)) != EOF) {
        int watermark_value = ((c + dynamic_watermark) % 128) - c;
        fputc(c + watermark_value, file);
    }
    
    printf("Digital watermark '%d' added to file '%s'\n", dynamic_watermark, filename);
    
    fclose(file);
    
    return 0;
}