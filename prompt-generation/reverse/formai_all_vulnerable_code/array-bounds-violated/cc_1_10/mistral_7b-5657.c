//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 3
#define HEIGHT 3

void print_ascii_art(const unsigned char image[WIDTH][HEIGHT]) {
    const char *ascii_art[] = {
        ".-..",
        "--..",
        "....",
        "--.-.",
        ".-.-.",
        "...-",
        "....",
        "..--",
        "....",
        "....",
        ".----",
        "..---",
        "...--",
        "....-",
        "--...",
        "---..",
        "----."
    };

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (image[j][i])
                printf("%s", ascii_art[image[j][i] / 8 + (image[j][i] % 8) * 3]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

int main(void) {
    unsigned char image[WIDTH][HEIGHT];

    printf("Enter a binary image (0 or 1):-\n");
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            scanf("%1u", &image[j][i]);
        }
    }

    print_ascii_art(image);

    return EXIT_SUCCESS;
}