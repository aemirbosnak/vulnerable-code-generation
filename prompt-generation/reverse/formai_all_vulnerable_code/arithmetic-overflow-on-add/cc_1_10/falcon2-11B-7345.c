//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_ART_SET "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

// Read the image file line by line and store each line in an array
char** readImage(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    int numLines = 0;
    fscanf(file, "%d", &numLines);

    char** lines = malloc(numLines * sizeof(char*));
    for (int i = 0; i < numLines; i++) {
        lines[i] = malloc((numLines + 1) * sizeof(char));
        fscanf(file, "%s", lines[i]);
        lines[i][numLines] = '\0';
    }

    fclose(file);
    return lines;
}

// Convert a line of ASCII art
void convertLine(const char* line) {
    for (int i = 0; i < strlen(line); i++) {
        char c = line[i];
        if (isalpha(c)) {
            c = c - 'A' + '1';
        }

        printf("%s", ASCII_ART_SET + c);
    }
}

// Convert an image to ASCII art
void convertImage(const char* filename) {
    char** lines = readImage(filename);

    for (int i = 0; i < strlen(lines); i++) {
        convertLine(lines[i]);
        printf("\n");
    }

    free(lines);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }

    convertImage(argv[1]);

    return 0;
}