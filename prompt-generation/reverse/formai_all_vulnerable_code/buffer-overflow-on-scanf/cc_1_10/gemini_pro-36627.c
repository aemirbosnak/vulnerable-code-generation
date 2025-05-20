//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
#define BOARD_SIZE 10
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player's position
int player_x, player_y;

// Define the goal position
int goal_x, goal_y;

// Define the number of moves
int moves;

// Initialize the game board
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

// Place the player on the board
void place_player() {
    player_x = rand() % BOARD_SIZE;
    player_y = rand() % BOARD_SIZE;
    board[player_x][player_y] = 'P';
}

// Place the goal on the board
void place_goal() {
    goal_x = rand() % BOARD_SIZE;
    goal_y = rand() % BOARD_SIZE;
    board[goal_x][goal_y] = 'G';
}

// Print the game board
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Check if the player has won
int check_win() {
    return player_x == goal_x && player_y == goal_y;
}

// Get the player's move
char get_move() {
    char move;
    printf("Enter your move (w, a, s, d): ");
    scanf(" %c", &move);
    return move;
}

// Move the player
void move_player(char move) {
    switch (move) {
        case 'w':
            if (player_x > 0) {
                board[player_x][player_y] = '.';
                player_x--;
                board[player_x][player_y] = 'P';
            }
            break;
        case 'a':
            if (player_y > 0) {
                board[player_x][player_y] = '.';
                player_y--;
                board[player_x][player_y] = 'P';
            }
            break;
        case 's':
            if (player_x < BOARD_SIZE - 1) {
                board[player_x][player_y] = '.';
                player_x++;
                board[player_x][player_y] = 'P';
            }
            break;
        case 'd':
            if (player_y < BOARD_SIZE - 1) {
                board[player_x][player_y] = '.';
                player_y++;
                board[player_x][player_y] = 'P';
            }
            break;
    }
}

// Play the game
void play_game() {
    init_board();
    place_player();
    place_goal();

    while (!check_win()) {
        print_board();
        char move = get_move();
        move_player(move);
        moves++;
    }

    print_board();
    printf("You win!\n");
    printf("Number of moves: %d\n", moves);
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}