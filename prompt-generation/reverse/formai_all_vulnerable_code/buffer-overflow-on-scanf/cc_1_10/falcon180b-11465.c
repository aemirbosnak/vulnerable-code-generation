//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define ASCII_ART_FILE "ascii_art.txt"

typedef struct {
    char *text;
    int font;
    int bg_color;
    int fg_color;
} AsciiArt;

void generate_ascii_art(AsciiArt *ascii_art, int width, int height) {
    FILE *file;
    char line[MAX_WIDTH+1];
    int x, y;
    file = fopen(ASCII_ART_FILE, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", ASCII_ART_FILE);
        exit(1);
    }
    for (y = 0; y < height; y++) {
        fgets(line, MAX_WIDTH+1, file);
        for (x = 0; x < width; x++) {
            if (line[x]!= '\n') {
                printf("%c", line[x]);
            }
        }
        printf("\n");
    }
    fclose(file);
}

int main() {
    AsciiArt ascii_art;
    char input[MAX_WIDTH+1];
    int width, height;

    printf("Enter the width of the ASCII art (1-80): ");
    scanf("%d", &width);
    printf("Enter the height of the ASCII art (1-25): ");
    scanf("%d", &height);

    printf("Enter the text for the ASCII art:\n");
    fgets(input, MAX_WIDTH+1, stdin);
    ascii_art.text = strdup(input);

    printf("Enter the font for the ASCII art (1-9): ");
    scanf("%d", &ascii_art.font);

    printf("Enter the background color for the ASCII art (30-37): ");
    scanf("%d", &ascii_art.bg_color);

    printf("Enter the foreground color for the ASCII art (30-37): ");
    scanf("%d", &ascii_art.fg_color);

    generate_ascii_art(&ascii_art, width, height);

    return 0;
}