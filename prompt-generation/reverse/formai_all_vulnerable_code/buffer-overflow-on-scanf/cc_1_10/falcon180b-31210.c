//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    char **lines;
} AsciiArt;

void print_ascii_art(AsciiArt *art) {
    for (int y = 0; y < art->height; y++) {
        printf("%s\n", art->lines[y]);
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char ch;
    int count = 0;
    AsciiArt art;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    art.width = 0;
    art.height = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            art.height++;
            art.lines = (char **) realloc(art.lines, art.height * sizeof(char *));
            art.lines[art.height - 1] = (char *) malloc(MAX_WIDTH * sizeof(char));
            count = 0;
        } else if (ch == '\r') {
            continue;
        } else if (ch >= 'a' && ch <= 'z') {
            art.lines[art.height - 1][count++] = tolower(ch);
        }
    }

    fclose(fp);

    art.width = count;

    printf("ASCII art:\n");
    print_ascii_art(&art);

    return 0;
}