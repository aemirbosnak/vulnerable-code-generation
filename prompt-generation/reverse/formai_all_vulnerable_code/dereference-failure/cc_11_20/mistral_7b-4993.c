//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 30
#define HEIGHT 10

void generate_ascii_art(char text[], char ascii[][WIDTH]) {
    int len = strlen(text);
    int i, j;

    for (i = 0; i < len && i < WIDTH; i++) {
        switch (tolower(text[i])) {
            case 'a':
                for (j = 0; j < HEIGHT; j++)
                    ascii[i / 2][j] = '*';
                break;
            case 'e':
                for (j = 0; j < HEIGHT; j++)
                    ascii[i / 3 + i % 3][j] = 'o';
                break;
            case 'i':
                for (j = 0; j < HEIGHT; j++)
                    ascii[i][j] = 'o';
                break;
            case 'o':
                for (j = 0; j < HEIGHT; j++)
                    ascii[i][j] = 'o';
                break;
            case 'u':
                for (j = 0; j < HEIGHT; j++)
                    ascii[i][j] = '\\';
                for (j = 1; j < HEIGHT; j++)
                    ascii[i][j] = '/';
                break;
            case ' ':
                for (j = 0; j < HEIGHT; j++)
                    ascii[i][j] = ' ';
                break;
            default:
                for (j = 0; j < HEIGHT; j++)
                    ascii[i][j] = text[i];
        }
    }

    for (i = len; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++)
            ascii[i][j] = ' ';
    }
}

int main() {
    char text[100], ascii[WIDTH][HEIGHT];

    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    generate_ascii_art(text, ascii);

    printf("\nYour ASCII art:\n");
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++)
            putchar(ascii[i][j]);
        putchar('\n');
    }

    return 0;
}