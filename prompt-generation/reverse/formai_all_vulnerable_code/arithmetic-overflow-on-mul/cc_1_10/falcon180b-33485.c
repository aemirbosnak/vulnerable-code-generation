//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Function prototypes
int read_image(char **data, int *width, int *height);
void print_ascii_art(char *data, int width, int height);

int main() {
    char *data = NULL;
    int width, height;

    // Read image data from file
    if (read_image(&data, &width, &height)!= 0) {
        fprintf(stderr, "Error reading image data.\n");
        return 1;
    }

    // Print ASCII art
    print_ascii_art(data, width, height);

    // Free memory
    free(data);

    return 0;
}

// Function to read image data from file
int read_image(char **data, int *width, int *height) {
    FILE *fp;
    int c, i, j;
    char line[MAX_WIDTH];
    char *buffer = NULL;

    // Open file
    fp = fopen("image.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    // Read first line to get image dimensions
    fgets(line, MAX_WIDTH, fp);
    sscanf(line, "%d %d", width, height);

    // Allocate memory for image data
    *data = malloc(*width * *height * sizeof(char));
    if (*data == NULL) {
        fprintf(stderr, "Error allocating memory.\n");
        return 1;
    }

    // Read image data
    i = 0;
    while ((c = fgetc(fp))!= EOF) {
        if (isspace(c)) {
            if (buffer!= NULL) {
                strcat(*data, buffer);
                free(buffer);
                buffer = NULL;
            }
        } else {
            if (buffer == NULL) {
                buffer = malloc(MAX_WIDTH * sizeof(char));
            }
            strncat(buffer, &c, 1);
        }
        i++;
        if (i == *width) {
            strcat(*data, buffer);
            free(buffer);
            buffer = NULL;
            i = 0;
        }
    }

    // Close file
    fclose(fp);

    return 0;
}

// Function to print ASCII art
void print_ascii_art(char *data, int width, int height) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (data[i * width + j] == '0') {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}