//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("\nWelcome to the Terminal Maze Game!\n");
    printf("You have been trapped in a maze and you have to find your way out.\n");
    printf("You can move up, down, left, right using 'w', 's', 'a', 'd' respectively.\n");
    printf("Good luck!\n\n");

    // initialize maze
    char maze[10][10] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', '#'},
        {'#', '#', '#', ' ', '#', '#', ' ', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', '#'},
        {'#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', '#'},
        {'#', ' ', ' ', '#', ' ', '#', ' ', '#', '#', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    // initialize player position
    int x = 1, y = 1;

    // randomize exit position
    srand(time(NULL));
    int exit_x = rand() % 8 + 1;
    int exit_y = rand() % 8 + 1;
    maze[exit_x][exit_y] = 'E';

    // start game loop
    while (1) {
        // print current maze
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == x && j == y) {
                    printf("P");
                } else {
                    printf("%c", maze[i][j]);
                }
                printf(" ");
            }
            printf("\n");
        }

        // check if player reached exit
        if (x == exit_x && y == exit_y) {
            printf("Congratulations, you found the exit!\n");
            break;
        }

        // get user input
        char input;
        printf("Enter movement direction (w, s, a, d): ");
        scanf(" %c", &input);

        // move player
        switch (input) {
            case 'w':
                if (maze[x-1][y] == ' ') {
                    x--;
                }
                break;
            case 's':
                if (maze[x+1][y] == ' ') {
                    x++;
                }
                break;
            case 'a':
                if (maze[x][y-1] == ' ') {
                    y--;
                }
                break;
            case 'd':
                if (maze[x][y+1] == ' ') {
                    y++;
                }
                break;
            default:
                printf("Invalid input, try again.\n");
        }
    }

    return 0;
}