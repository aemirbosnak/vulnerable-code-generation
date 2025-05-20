//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board size
#define BOARD_SIZE 10

// Define the player's starting position
#define PLAYER_START_X 0
#define PLAYER_START_Y 0

// Define the goal position
#define GOAL_X 9
#define GOAL_Y 9

// Define the obstacle character
#define OBSTACLE '#'

// Define the player character
#define PLAYER '@'

// Define the goal character
#define GOAL 'G'

// Define the empty space character
#define EMPTY ' '

// Create the game board
char board[BOARD_SIZE][BOARD_SIZE];

// Create the player's position
int player_x = PLAYER_START_X;
int player_y = PLAYER_START_Y;

// Create the goal's position
int goal_x = GOAL_X;
int goal_y = GOAL_Y;

// Create the obstacles' positions
int obstacles[10][2] = {
    {2, 2},
    {4, 4},
    {6, 6},
    {8, 8},
    {1, 5},
    {3, 7},
    {5, 1},
    {7, 3},
    {9, 5},
    {1, 9}
};

// Initialize the game board
void init_board() {
    // Set all spaces to empty
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Set the player's position
    board[player_x][player_y] = PLAYER;

    // Set the goal's position
    board[goal_x][goal_y] = GOAL;

    // Set the obstacles' positions
    for (int i = 0; i < 10; i++) {
        board[obstacles[i][0]][obstacles[i][1]] = OBSTACLE;
    }
}

// Print the game board
void print_board() {
    // Print the top border
    printf("+");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("-");
    }
    printf("+\n");

    // Print each row of the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("|\n");
    }

    // Print the bottom border
    printf("+");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("-");
    }
    printf("+\n");
}

// Move the player
void move_player(int dx, int dy) {
    // Check if the player is moving into a valid space
    if (board[player_x + dx][player_y + dy] != OBSTACLE) {
        // Move the player
        board[player_x][player_y] = EMPTY;
        player_x += dx;
        player_y += dy;
        board[player_x][player_y] = PLAYER;
    }
}

// Check if the player has reached the goal
int check_win() {
    return player_x == goal_x && player_y == goal_y;
}

// Main game loop
int main() {
    // Initialize the game board
    init_board();

    // Print the game board
    print_board();

    // Get the player's input
    char input;
    while ((input = getchar()) != 'q') {
        // Move the player based on the input
        switch (input) {
            case 'w':
                move_player(-1, 0);
                break;
            case 'a':
                move_player(0, -1);
                break;
            case 's':
                move_player(1, 0);
                break;
            case 'd':
                move_player(0, 1);
                break;
        }

        // Print the game board
        print_board();

        // Check if the player has reached the goal
        if (check_win()) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}