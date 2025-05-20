//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HEIGHT 10
#define WIDTH 32
#define TRUNK_LENGTH 3

typedef struct Tree {
    int x;
    int y;
    int height;
} Tree;

char *ascii_tree(int height) {
    static char tree[HEIGHT][WIDTH];

    memset(tree, ' ', sizeof(tree));

    int trunk_x = (WIDTH - TRUNK_LENGTH) / 2;
    int trunk_y = height - TRUNK_LENGTH;

    for (int i = 0; i < TRUNK_LENGTH; i++) {
        tree[trunk_y + i][trunk_x] = '|';
        tree[trunk_y + i][trunk_x + TRUNK_LENGTH / 2] = '/';
        tree[trunk_y + i][trunk_x + TRUNK_LENGTH] = '|';
    }

    int space_between_branches = (WIDTH - 2 * TRUNK_LENGTH) / (HEIGHT - TRUNK_LENGTH);

    for (int row = height - TRUNK_LENGTH; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (col >= trunk_x - space_between_branches && col <= trunk_x + space_between_branches)
                tree[row][col] = 'O';
            else if (row == height - 1)
                tree[row][col] = '#';
            else
                tree[row][col] = ' ';
        }
    }

    return (char *) tree;
}

int main() {
    int user_input;

    printf("Enter the height of the tree: ");
    scanf("%d", &user_input);

    if (user_input > 0 && user_input <= HEIGHT) {
        char *ascii_art = ascii_tree(user_input);
        printf("\n");
        puts(ascii_art);
        free(ascii_art);
    } else {
        printf("Invalid height.\n");
    }

    return 0;
}