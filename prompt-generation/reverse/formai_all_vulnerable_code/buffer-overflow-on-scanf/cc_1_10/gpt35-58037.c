//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_map(int map[][10]) {
    int i, j;
    srand(time(NULL));
    for (i=0; i<10; i++) {
        for (j=0; j<10; j++) {
            map[i][j] = rand() % 3;
        }
    }
}

int main() {
    int map[10][10];
    int player_x = 0, player_y = 0;
    generate_map(map);
    int moves = 0;
    while (1) {
        printf("Your coordinates are (%d,%d)\n", player_x, player_y);
        printf("You have made %d moves\n", moves);
        if (map[player_y][player_x] == 0) {
            printf("You're in open space\n");
        } else if (map[player_y][player_x] == 1) {
            printf("You've discovered a space station\n");
        } else {
            printf("You've encountered an alien ship\n");
        }
        printf("Enter a command (n/s/e/w): ");
        char command;
        scanf("%c", &command);
        fflush(stdin);
        switch (command) {
            case 'n':
                if (player_y > 0) {
                    player_y--;
                } else {
                    printf("You hit a wall!\n");
                }
                break;
            case 's':
                if (player_y < 9) {
                    player_y++;
                } else {
                    printf("You hit a wall!\n");
                }
                break;
            case 'e':
                if (player_x < 9) {
                    player_x++;
                } else {
                    printf("You hit a wall!\n");
                }
                break;
            case 'w':
                if (player_x > 0) {
                    player_x--;
                } else {
                    printf("You hit a wall!\n");
                }
                break;
            default:
                printf("Invalid command\n");
        }
        moves++;
        printf("\n");
    }
}