//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define MAX_CHARS 1000

typedef struct {
    char *text;
    int width;
    int height;
    int num_chars;
    char **chars;
} TextToAsciiArt;

TextToAsciiArt *text_to_ascii_art_create(char *text, int width, int height)
{
    TextToAsciiArt *ascii_art = malloc(sizeof(TextToAsciiArt));
    ascii_art->text = text;
    ascii_art->width = width;
    ascii_art->height = height;
    ascii_art->num_chars = strlen(text);
    ascii_art->chars = malloc(sizeof(char *) * ascii_art->num_chars);
    int i;
    for (i = 0; i < ascii_art->num_chars; i++) {
        ascii_art->chars[i] = malloc(sizeof(char) * 3);
        sprintf(ascii_art->chars[i], "%c", text[i]);
    }
    return ascii_art;
}

void text_to_ascii_art_destroy(TextToAsciiArt *ascii_art)
{
    int i;
    for (i = 0; i < ascii_art->num_chars; i++) {
        free(ascii_art->chars[i]);
    }
    free(ascii_art->chars);
    free(ascii_art);
}

void text_to_ascii_art_print(TextToAsciiArt *ascii_art)
{
    int i, j;
    for (i = 0; i < ascii_art->height; i++) {
        for (j = 0; j < ascii_art->width; j++) {
            printf("%s ", ascii_art->chars[i * ascii_art->width + j]);
        }
        printf("\n");
    }
}

int main()
{
    char *text = "Hello, World!";
    int width = 80;
    int height = 24;
    TextToAsciiArt *ascii_art = text_to_ascii_art_create(text, width, height);
    text_to_ascii_art_print(ascii_art);
    text_to_ascii_art_destroy(ascii_art);
    return 0;
}