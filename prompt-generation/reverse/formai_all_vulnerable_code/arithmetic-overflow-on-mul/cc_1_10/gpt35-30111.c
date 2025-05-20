//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if file argument is provided
    if (argc != 2) {
        printf("Please provide an image file as an argument.\n");
        return 1;
    }

    // Open file
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Could not open file %s.\n", argv[1]);
        return 1;
    }

    // Read header
    char header[54];
    fread(header, sizeof(char), 54, fp);

    // Get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate image size
    int size = width * height * 3;
    unsigned char *data = malloc(size);

    // Read image data
    fread(data, sizeof(char), size, fp);

    // Close file
    fclose(fp);

    // Convert image data to ASCII art
    char *ascii = malloc((size/3) + height + 1);
    int k = 0;
    for (int i = 0; i < size; i += 3) {
        int intensity = (data[i] + data[i+1] + data[i+2]) / 3;
        ascii[k++] = " .:-=+*#%@"[intensity / 25];
        if ((i+3) % (width*3) == 0) { // New line
            ascii[k++] = '\n';
        }
    }
    ascii[k] = '\0';

    // Write ASCII art to file
    char *filename = malloc(strlen(argv[1]) + 5);
    strcpy(filename, argv[1]);
    strcat(filename, ".txt");
    fp = fopen(filename, "w");
    if (!fp) {
        printf("Could not write ASCII art to file.\n");
        return 1;
    }
    fputs(ascii, fp);
    fclose(fp);

    // Free memory
    free(data);
    free(ascii);
    free(filename);

    printf("Conversion complete! Check %s.txt for the ASCII art.\n", argv[1]);

    return 0;
}