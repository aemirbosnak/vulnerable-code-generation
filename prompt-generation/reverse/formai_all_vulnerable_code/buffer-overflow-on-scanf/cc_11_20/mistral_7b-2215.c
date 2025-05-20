//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10

void print_ascii_art(char c) {
    switch (c) {
        case 'A':
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    if (i < 2 || i > 7 || j < 12 || j > 16)
                        putchar(' ');
                    else
                        putchar('*');
                }
                putchar('\n');
            }
            break;
        case 'B':
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    if (i < 2 || i > 4 || (j > 1 && j < 11) || (j > 15 && j < WIDTH))
                        putchar(' ');
                    else
                        putchar('o');
                }
                putchar('\n');
            }
            break;
        case 'C':
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
                        putchar('*');
                    else
                        putchar(' ');
                }
                putchar('\n');
            }
            break;
        default:
            putchar('Input should be A, B or C\n');
            exit(1);
    }
}

int main() {
    char input;
    scanf("%c", &input);
    print_ascii_art(input);
    return 0;
}