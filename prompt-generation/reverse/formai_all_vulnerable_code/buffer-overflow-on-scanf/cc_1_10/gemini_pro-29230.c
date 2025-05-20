//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the maze
char maze[10][10] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Define the player's position
int player_x = 1;
int player_y = 1;

// Define the goal position
int goal_x = 8;
int goal_y = 8;

// Function to print the maze
void print_maze() {
    // Print the top border
    printf("####################\n");

    // Print each row of the maze
    for (int i = 0; i < 10; i++) {
        printf("#");
        for (int j = 0; j < 10; j++) {
            printf("%c", maze[i][j]);
        }
        printf("#\n");
    }

    // Print the bottom border
    printf("####################\n");
}

// Function to move the player
void move_player(char direction) {
    // Check if the player is trying to move out of the maze
    if (direction == 'w' && player_y == 0) {
        return;
    } else if (direction == 's' && player_y == 9) {
        return;
    } else if (direction == 'a' && player_x == 0) {
        return;
    } else if (direction == 'd' && player_x == 9) {
        return;
    }

    // Check if the player is trying to move into a wall
    if (maze[player_y][player_x] == '#') {
        return;
    }

    // Move the player in the specified direction
    if (direction == 'w') {
        player_y--;
    } else if (direction == 's') {
        player_y++;
    } else if (direction == 'a') {
        player_x--;
    } else if (direction == 'd') {
        player_x++;
    }
}

// Function to check if the player has reached the goal
int check_goal() {
    if (player_x == goal_x && player_y == goal_y) {
        return 1;
    } else {
        return 0;
    }
}

// Function to play the game
void play_game() {
    // Print the maze
    print_maze();

    // Get the player's input
    char input;
    printf("Enter a direction (w, s, a, d): ");
    scanf(" %c", &input);

    // Move the player
    move_player(input);

    // Check if the player has reached the goal
    if (check_goal()) {
        // Print a message saying that the player has won
        printf("You win!\n");
    } else {
        // Play the game again
        play_game();
    }
}

int main() {
    // Play the game
    play_game();

    return 0;
}