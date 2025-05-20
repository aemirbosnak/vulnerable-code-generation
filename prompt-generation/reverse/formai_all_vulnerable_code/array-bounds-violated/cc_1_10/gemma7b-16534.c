//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int x = 0, y = 0, map[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    system("cls");
    printf("Welcome to the Cave Exploration Game!\n");
    printf("------------------------\n");

    // Display the map
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            printf("%d ", map[x][y]);
        }
        printf("\n");
    }

    // Get the player's move
    printf("Enter your move (N, S, E, W): ");
    char move;
    scanf("%c", &move);

    // Move the player
    switch (move) {
        case 'N':
            y--;
            break;
        case 'S':
            y++;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
    }

    // Check if the player has won or lost
    if (map[x][y] == 1) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, you lost. Better luck next time.\n");
    }

    return 0;
}