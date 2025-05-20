#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

char map[ROWS][COLS] = {
    "#########",
    "#       #",
    "# P     #",
    "#       #",
    "#########"
};

void print_map(void) {
    for (int i = 0; i < ROWS; ++i) {
        printf("%s\n", map[i]);
    }
}

int main(void) {
    char input;
    int player_x = 2, player_y = 1;

    while (1) {
        print_map();
        printf("Enter direction (w, a, s, d): ");
        scanf(" %c", &input);

        switch (input) {
            case 'w':
                if (player_y > 1) --player_y;
                break;
            case 'a':
                if (player_x > 1) --player_x;
                break;
            case 's':
                if (player_y < ROWS - 2) ++player_y;
                break;
            case 'd':
                if (player_x < COLS - 2) ++player_x;
                break;
            default:
                printf("Invalid input. Please enter w, a, s, or d.\n");
        }
    }

    return 0;
}
