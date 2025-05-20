//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the most exciting game programming experience!\n");
    printf("It's time to play a game called 'Maze Runner'!\n");
    printf("You have to navigate through a maze to find the treasure before your time runs out.\n");
    
    // create the maze
    char maze[10][10] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#'},
        {'#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
    
    int x = 1, y = 1; // starting position
    int treasure_x = 8, treasure_y = 8; // treasure location
    int time = 30; // time limit
    
    // game loop
    while (time > 0) {
        // print maze
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (x == i && y == j) {
                    printf("P ");
                } else {
                    printf("%c ", maze[i][j]);
                }
            }
            printf("\n");
        }
        
        // check if player found the treasure
        if (x == treasure_x && y == treasure_y) {
            printf("Congratulations, you found the treasure!\n");
            printf("You win!\n");
            return 0;
        }
        
        // get user input
        char input;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &input);
        
        // move player
        switch (input) {
            case 'w':
                if (maze[x-1][y] != '#') {
                    x--;
                }
                break;
            case 'a':
                if (maze[x][y-1] != '#') {
                    y--;
                }
                break;
            case 's':
                if (maze[x+1][y] != '#') {
                    x++;
                }
                break;
            case 'd':
                if (maze[x][y+1] != '#') {
                    y++;
                }
                break;
        }
        
        // decrease time
        time--;
    }
    
    printf("Sorry, time's up!\n");
    printf("Game over!\n");
    return 0;
}