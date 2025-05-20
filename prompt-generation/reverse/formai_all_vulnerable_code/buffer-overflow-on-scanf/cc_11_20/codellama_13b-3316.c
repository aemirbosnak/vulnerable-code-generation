//Code Llama-13B DATASET v1.0 Category: Procedural Space Adventure ; Style: Alan Turing
#include <stdio.h>

int main() {
    int i, j;
    char input;
    char map[10][10];

    // Initialize the map
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            map[i][j] = ' ';
        }
    }

    // Set starting position
    int x = 0, y = 0;
    map[x][y] = 'A';

    while (1) {
        // Print the map
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        // Get input from user
        printf("Enter a direction (N, S, E, W): ");
        scanf("%c", &input);

        // Move the player
        switch (input) {
            case 'N':
                if (y > 0) {
                    map[x][y] = ' ';
                    y--;
                    map[x][y] = 'A';
                }
                break;
            case 'S':
                if (y < 9) {
                    map[x][y] = ' ';
                    y++;
                    map[x][y] = 'A';
                }
                break;
            case 'E':
                if (x < 9) {
                    map[x][y] = ' ';
                    x++;
                    map[x][y] = 'A';
                }
                break;
            case 'W':
                if (x > 0) {
                    map[x][y] = ' ';
                    x--;
                    map[x][y] = 'A';
                }
                break;
            default:
                break;
        }
    }

    return 0;
}