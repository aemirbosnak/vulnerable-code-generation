//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HEIGHT 5
#define WIDTH 11

char ascii_art[HEIGHT][WIDTH];

void init_ascii_art() {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            ascii_art[i][j] = '\0';
        }
    }

    for (i = 0; i < HEIGHT; i++) {
        ascii_art[i][0] = (i == 0) ? '+' : '|';
        ascii_art[i][WIDTH - 1] = (i == HEIGHT - 1) ? '+' : '|';
    }

    for (i = 1; i < HEIGHT - 1; i++) {
        ascii_art[i][0] = '|';
        ascii_art[i][WIDTH - 1] = '|';
    }

    ascii_art[0][1] = '-';
    ascii_art[HEIGHT - 1][1] = '-';

    for (i = 1; i < HEIGHT - 1; i++) {
        ascii_art[i][1] = ' ';
        ascii_art[i][WIDTH - 2] = ' ';
    }
}

void print_ascii_art(char text[100]) {
    int text_len = strlen(text);
    int i, j, k;

    if (text_len > WIDTH - 2) {
        printf("Error: Text length exceeds the width of the ASCII art.\n");
        return;
    }

    init_ascii_art();

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            putchar(ascii_art[i][j]);
        }
        putchar('\n');
    }

    for (i = 0; i < text_len; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (j < i) {
                k = text[i];
                if (k >= 'A' && k <= 'Z') {
                    k += 32;
                }
                if (j < (int)k - 65) {
                    putchar(ascii_art[i + 1][j + 1]);
                } else {
                    putchar(ascii_art[i][j]);
                }
            } else {
                putchar(text[i]);
            }
        }
        putchar('\n');
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            putchar(ascii_art[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    char text[100];

    printf("Enter your text: ");
    scanf("%s", text);

    print_ascii_art(text);

    return 0;
}