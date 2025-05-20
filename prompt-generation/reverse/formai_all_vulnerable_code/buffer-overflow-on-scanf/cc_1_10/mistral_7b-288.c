//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 50
#define HEIGHT 10
#define TREE_HEIGHT 3
#define TREE_BRANCH_LENGTH 2
#define TREE_BRANCH_WIDTH 2
#define TREE_TRUNK_WIDTH 3

typedef struct {
    int x, y;
} point;

void generate_tree(int x, int y) {
    int i, j;

    printf("\033[%d;%dH", y, x);
    for (i = 0; i < TREE_TRUNK_WIDTH; i++) {
        putchar('#');
    }
    printf("\033[%d;%dH", y + TREE_HEIGHT, x);
    for (i = 0; i < TREE_BRANCH_LENGTH; i++) {
        for (j = 0; j <= i; j++) {
            putchar(' ');
        }
        putchar('/');
    }
    for (i = TREE_BRANCH_LENGTH; i > 0; i--) {
        for (j = 0; j <= i; j++) {
            putchar(' ');
        }
        putchar('\\');
    }
}

void text_to_ascii_forest(char *text) {
    int i, j, len, x, y;
    char c;

    len = strlen(text);

    for (i = 0; i < len; i++) {
        c = toupper(text[i]);

        switch (c) {
            case 'A':
                x = i % WIDTH;
                y = i / WIDTH;
                generate_tree(x * 3 + 1, y * HEIGHT + 1);
                break;
            case 'S':
                x = i % WIDTH;
                y = i / WIDTH;
                generate_tree(x * 3, y * HEIGHT + 1);
                break;
            case 'O':
                x = i % WIDTH;
                y = i / WIDTH;
                generate_tree(x * 3 + 1, y * HEIGHT);
                generate_tree(x * 3 + 1, y * HEIGHT + HEIGHT - TREE_HEIGHT);
                break;
            case 'G':
                x = i % WIDTH;
                y = i / WIDTH;
                generate_tree(x * 3, y * HEIGHT + HEIGHT / 2);
                break;
            default:
                break;
        }
    }
}

int main() {
    char text[100];

    printf("\033[H\033[2J"); // Clear the terminal

    printf("Enter a text: ");
    scanf("%s", text);

    text_to_ascii_forest(text);

    return 0;
}