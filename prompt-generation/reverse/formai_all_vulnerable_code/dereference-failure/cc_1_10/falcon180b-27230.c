//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert image to ASCII art
void image_to_ascii(char *filename, int width, int height) {
    FILE *fp;
    int i, j, k, l, m, n;
    char ch;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned char *data;

    // Open input file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    // Read image data
    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);
    data = (unsigned char *) malloc(filesize);
    read = fread(data, 1, filesize, fp);
    if (read!= filesize) {
        printf("Error: Unable to read file %s\n", filename);
        exit(1);
    }

    // Convert image data to ASCII art
    int max_value = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            k = i * width + j;
            if (data[k] > max_value) {
                max_value = data[k];
            }
        }
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            k = i * width + j;
            n = data[k] * max_value / 255;
            m = n * 6;

            if (m == 0) {
                printf("  ");
            } else if (m == 1) {
                printf(". ");
            } else if (m == 2) {
                printf(": ");
            } else if (m == 3) {
                printf("- ");
            } else if (m == 4) {
                printf("= ");
            } else {
                printf("+ ");
            }
        }
        printf("\n");
    }

    // Free memory
    free(data);
    fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    image_to_ascii(filename, width, height);

    return 0;
}