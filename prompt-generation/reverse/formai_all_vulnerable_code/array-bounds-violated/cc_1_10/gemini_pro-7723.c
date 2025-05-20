//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// The maze.
char maze[10][10] = {
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ' },
    { ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ' },
    { ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ' },
    { ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ' },
    { ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ' },
};

// The player's position.
int player_x = 1;
int player_y = 1;

// The exit's position.
int exit_x = 8;
int exit_y = 8;

// The function to print the maze.
void print_maze() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// The function to check if the player has reached the exit.
int check_exit() {
    if (player_x == exit_x && player_y == exit_y) {
        return 1;
    } else {
        return 0;
    }
}

// The function to move the player.
void move_player(char direction) {
    switch (direction) {
        case 'w':
            if (maze[player_x - 1][player_y] != '#') {
                player_x--;
            }
            break;
        case 'a':
            if (maze[player_x][player_y - 1] != '#') {
                player_y--;
            }
            break;
        case 's':
            if (maze[player_x + 1][player_y] != '#') {
                player_x++;
            }
            break;
        case 'd':
            if (maze[player_x][player_y + 1] != '#') {
                player_y++;
            }
            break;
    }
}

// The main function.
int main() {
    // Print the maze.
    print_maze();

    // Get the player's input.
    char input;
    while ((input = getchar()) != 'q') {
        // Move the player.
        move_player(input);

        // Check if the player has reached the exit.
        if (check_exit()) {
            // Print the victory message.
            printf("Congratulations! You have escaped the maze.\n");
            break;
        }

        // Print the maze.
        print_maze();
    }

    return 0;
}