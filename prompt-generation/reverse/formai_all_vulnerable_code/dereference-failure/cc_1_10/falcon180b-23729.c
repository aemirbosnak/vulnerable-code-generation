//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Maximum width of the image
#define MAX_WIDTH 80

// Available characters for ASCII art
char *ascii_chars = "@%#*+=-:. ";

// Function to print the ASCII art
void print_ascii_art(char *text, int width) {
    int len = strlen(text);
    int i, j;

    for (i = 0; i < len; i++) {
        char c = tolower(text[i]);
        if (c >= 'a' && c <= 'z') {
            j = c - 'a';
            printf("%c", ascii_chars[j % strlen(ascii_chars)]);
        } else {
            printf("%c", c);
        }
    }

    for (i = 0; i < width - len; i++) {
        printf(" ");
    }

    printf("\n");
}

// Function to generate the ASCII art
void generate_ascii_art(char *text) {
    int len = strlen(text);
    int width = (len + MAX_WIDTH - 1) / MAX_WIDTH * MAX_WIDTH;

    printf("Generating ASCII art...\n");

    for (int i = 0; i < width; i++) {
        char *substr = malloc(MAX_WIDTH + 1);
        strncpy(substr, text + i, MAX_WIDTH);
        substr[MAX_WIDTH] = '\0';
        print_ascii_art(substr, MAX_WIDTH);
    }

    printf("ASCII art generated successfully!\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    generate_ascii_art(text);

    return 0;
}