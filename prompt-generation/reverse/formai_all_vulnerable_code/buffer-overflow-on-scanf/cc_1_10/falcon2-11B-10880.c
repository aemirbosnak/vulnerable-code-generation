//Falcon2-11B DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *ascii_art;
    int width;
    int height;
} AsciiArt;

int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void convert_to_ascii(const char* text, AsciiArt* ascii_art) {
    char line[MAX_WIDTH + 1];
    char ascii_char;
    int index = 0;

    ascii_art->width = 0;
    ascii_art->height = 0;

    ascii_art->ascii_art = (char*)malloc(MAX_WIDTH * ascii_art->height * sizeof(char));

    while (text[index]!= '\0') {
        ascii_char = (rand_num(0, 255) * 2) - 128;
        ascii_art->ascii_art[ascii_art->width * ascii_art->height + 0] = (char)ascii_char;
        ascii_art->ascii_art[ascii_art->width * ascii_art->height + 1] = (char)ascii_char;
        ascii_art->ascii_art[ascii_art->width * ascii_art->height + 2] = (char)ascii_char;
        ascii_art->ascii_art[ascii_art->width * ascii_art->height + 3] = (char)ascii_char;
        ascii_art->width++;

        if (ascii_art->width > MAX_WIDTH) {
            ascii_art->width = 0;
            ascii_art->height++;
        }

        index++;
    }
}

int main() {
    AsciiArt ascii_art;

    srand(time(NULL));

    char text[MAX_WIDTH + 1];
    scanf("%s", text);

    convert_to_ascii(text, &ascii_art);

    printf("%s\n", ascii_art.ascii_art);

    free(ascii_art.ascii_art);

    return 0;
}