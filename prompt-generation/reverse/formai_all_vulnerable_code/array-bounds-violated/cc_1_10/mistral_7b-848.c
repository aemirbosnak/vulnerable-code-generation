//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 10
#define SHIFT 5

void print_ascii_art(char text[WIDTH]);
void caesar_cipher(char *str, int shift);
void generate_ascii_art(char text[WIDTH]);

int main(void) {
    char text[WIDTH];
    printf("Enter a text to generate ASCII art:\n");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0'; // remove newline character
    caesar_cipher(text, SHIFT);
    generate_ascii_art(text);
    return 0;
}

void print_ascii_art(char text[WIDTH]) {
    int i, j;
    char ascii_art[HEIGHT][WIDTH];

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            ascii_art[i][j] = text[j] > ' ' && text[j] < 'Z' ? text[j] + i : text[j];
            if (ascii_art[i][j] > '~') ascii_art[i][j] -= 32;
        }
        ascii_art[i][WIDTH - 1] = '\0';
        printf("%s\n", ascii_art[i]);
    }
}

void caesar_cipher(char *str, int shift) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i]))
                str[i] = (char)(((int)str[i] - 65 + shift) % 26 + 65);
            else
                str[i] = (char)(((int)str[i] - 97 + shift) % 26 + 97);
        }
    }
}

void generate_ascii_art(char text[WIDTH]) {
    int i;
    char *tokens[5];
    char *token = strtok(text, " ");
    int index = 0;

    while (token != NULL) {
        tokens[index++] = token;
        token = strtok(NULL, " ");
    }

    printf("\n");

    for (i = 0; i < index; i++) {
        print_ascii_art(tokens[i]);
        printf("\n");
    }
}