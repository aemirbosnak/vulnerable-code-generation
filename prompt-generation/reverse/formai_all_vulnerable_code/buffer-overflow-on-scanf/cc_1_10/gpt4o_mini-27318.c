//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURE 'T'
#define TRAP 'X'
#define EMPTY ' '
#define PLAYER 'P'

void initialize_board(char board[SIZE][SIZE]);
void display_board(char board[SIZE][SIZE]);
int place_items(char board[SIZE][SIZE], char item, int count);
void move_player(char board[SIZE][SIZE], int *player_x, int *player_y, char direction);
int check_winner(int treasures_found, int total_treasures);
void play_game();

int main() {
    play_game();
    return 0;
}

void play_game() {
    char board[SIZE][SIZE];
    int player_x = SIZE / 2, player_y = SIZE / 2; // Start in the middle
    int treasures_found = 0, total_treasures = 0;

    initialize_board(board);
    total_treasures = place_items(board, TREASURE, 3); // Place 3 treasures
    place_items(board, TRAP, 5); // Place 5 traps

    board[player_x][player_y] = PLAYER; // Place player on the board

    char move;
    while (1) {
        display_board(board);
        printf("Treasures found: %d/%d\n", treasures_found, total_treasures);
        printf("Enter your move (w/a/s/d to move, q to quit): ");
        scanf(" %c", &move);

        if (move == 'q') {
            printf("Game over! You quit the game.\n");
            break;
        }

        // Move the player
        board[player_x][player_y] = EMPTY; // Remove player from current position
        move_player(board, &player_x, &player_y, move);

        // Check the current position
        if (board[player_x][player_y] == TREASURE) {
            treasures_found++;
            board[player_x][player_y] = PLAYER; // Place player on the board
            printf("You found a treasure!\n");
        } else if (board[player_x][player_y] == TRAP) {
            printf("Oh no! You hit a trap! Game over!\n");
            break;
        } else {
            board[player_x][player_y] = PLAYER; // Place player on the board
        }

        if (check_winner(treasures_found, total_treasures)) {
            printf("Congratulations! You've found all the treasures!\n");
            break;
        }
    }
}

void initialize_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void display_board(char board[SIZE][SIZE]) {
    system("clear"); // Clear the console
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int place_items(char board[SIZE][SIZE], char item, int count) {
    int placed = 0;
    while (placed < count) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] == EMPTY) {
            board[x][y] = item;
            placed++;
        }
    }
    return placed;
}

void move_player(char board[SIZE][SIZE], int *player_x, int *player_y, char direction) {
    switch (direction) {
        case 'w': // Up
            if (*player_x > 0) (*player_x)--;
            break;
        case 's': // Down
            if (*player_x < SIZE - 1) (*player_x)++;
            break;
        case 'a': // Left
            if (*player_y > 0) (*player_y)--;
            break;
        case 'd': // Right
            if (*player_y < SIZE - 1) (*player_y)++;
            break;
        default:
            printf("Invalid move. Use w/a/s/d to move.\n");
            break;
    }
}

int check_winner(int treasures_found, int total_treasures) {
    return treasures_found == total_treasures;
}