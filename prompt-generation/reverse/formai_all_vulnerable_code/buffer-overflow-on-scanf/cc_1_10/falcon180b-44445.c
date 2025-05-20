//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

// Function to print the ASCII art
void print_ascii_art(char *art, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", art[i * width + j]);
        }
        printf("\n");
    }
}

// Function to generate a random ASCII art
void generate_ascii_art(char *art, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            art[i * width + j] = rand() % 94 + 33; // 33 is the ASCII code for '!'
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int width, height;
    printf("Enter the width of the ASCII art: ");
    scanf("%d", &width);
    printf("Enter the height of the ASCII art: ");
    scanf("%d", &height);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Width and height must be less than or equal to %d and %d respectively.\n", MAX_WIDTH, MAX_HEIGHT);
        return 1;
    }

    char art[height * width];
    generate_ascii_art(art, width, height);
    print_ascii_art(art, width, height);

    return 0;
}