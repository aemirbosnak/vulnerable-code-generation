//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

// Function to print the ASCII art
void print_ascii_art(char *ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (ascii_art[i * WIDTH + j] == '1') {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[20];
    char ch;
    int i, j;
    char ascii_art[HEIGHT * WIDTH];

    // Get filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the image data
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%c", &ch);
            ascii_art[i * WIDTH + j] = ch;
        }
    }

    // Close the file
    fclose(fp);

    // Print the ASCII art
    print_ascii_art(ascii_art);

    return 0;
}