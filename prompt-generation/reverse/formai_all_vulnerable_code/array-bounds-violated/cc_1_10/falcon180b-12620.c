//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_galaxy(int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", rand() % 2? '.' : '*');
        }
        printf("\n");
    }
}

void explore_galaxy(char galaxy[100][100], int player_x, int player_y) {
    int i, j;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            if (galaxy[i][j] == '*') {
                printf("You've discovered a new star system at (%d, %d)!\n", i, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int width, height, player_x, player_y;
    printf("Enter the width and height of the galaxy (1-100): ");
    scanf("%d %d", &width, &height);
    char galaxy[100][100];
    generate_galaxy(width, height);
    printf("You are at position (0, 0).\n");
    while (1) {
        printf("Enter your move (w/a/s/d): ");
        char move;
        scanf("%c", &move);
        switch (move) {
            case 'w':
                if (player_y > 0 && galaxy[player_y - 1][player_x]!= '#') {
                    player_y--;
                }
                break;
            case 'a':
                if (player_x > 0 && galaxy[player_y][player_x - 1]!= '#') {
                    player_x--;
                }
                break;
            case's':
                if (player_y < height - 1 && galaxy[player_y + 1][player_x]!= '#') {
                    player_y++;
                }
                break;
            case 'd':
                if (player_x < width - 1 && galaxy[player_y][player_x + 1]!= '#') {
                    player_x++;
                }
                break;
            default:
                printf("Invalid move.\n");
        }
        if (galaxy[player_y][player_x] == '*') {
            printf("You've discovered a new star system at (%d, %d)!\n", player_y, player_x);
        }
    }
    return 0;
}