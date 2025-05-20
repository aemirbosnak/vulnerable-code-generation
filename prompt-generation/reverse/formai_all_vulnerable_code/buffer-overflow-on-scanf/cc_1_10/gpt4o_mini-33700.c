//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 5
#define TREASURE 'T'
#define TRAP 'X'
#define EMPTY '.'
#define PLAYER 'P'

typedef struct {
    int x;
    int y;
} Position;

void initialize_board(char board[SIZE][SIZE], Position *player_position, int *treasure_count);
void print_board(char board[SIZE][SIZE], Position player_position);
bool move_player(char board[SIZE][SIZE], Position *player_position, char direction, int *treasures_found);
bool is_valid_move(Position *pos);
bool game_over(char board[SIZE][SIZE], int treasures_found, int total_treasures);

int main() {
    char board[SIZE][SIZE];
    Position player_position;
    int treasures_found = 0, total_treasures = 0;
    char move;

    initialize_board(board, &player_position, &total_treasures);

    printf("Welcome to Treasure Hunt! Find all the treasures while avoiding traps.\n");

    while (!game_over(board, treasures_found, total_treasures)) {
        print_board(board, player_position);
        printf("Enter move (WASD): ");
        scanf(" %c", &move);
        move = toupper(move);

        if (!move_player(board, &player_position, move, &treasures_found)) {
            printf("Invalid move! Try again.\n");
        }
    }

    print_board(board, player_position);
    if (treasures_found == total_treasures) {
        printf("Congratulations! You've found all the treasures!\n");
    } else {
        printf("Game Over! Better luck next time!\n");
    }

    return 0;
}

void initialize_board(char board[SIZE][SIZE], Position *player_position, int *treasure_count) {
    srand(time(NULL));
    int treasures = 0;
    int traps = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Place treasures
    while (treasures < 3) { // 3 treasures
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] == EMPTY) {
            board[x][y] = TREASURE;
            treasures++;
        }
    }

    *treasure_count = treasures;

    // Place traps
    while (traps < 2) { // 2 traps
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] == EMPTY) {
            board[x][y] = TRAP;
            traps++;
        }
    }

    // Place Player
    player_position->x = rand() % SIZE;
    player_position->y = rand() % SIZE;
    while (board[player_position->x][player_position->y] != EMPTY) {
        player_position->x = rand() % SIZE;
        player_position->y = rand() % SIZE;
    }
    board[player_position->x][player_position->y] = PLAYER;
}

void print_board(char board[SIZE][SIZE], Position player_position) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == player_position.x && j == player_position.y) {
                printf("%c ", PLAYER);
            } else {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
}

bool move_player(char board[SIZE][SIZE], Position *player_position, char direction, int *treasures_found) {
    Position new_position = *player_position;

    switch (direction) {
        case 'W': new_position.x--; break; // Move up
        case 'S': new_position.x++; break; // Move down
        case 'A': new_position.y--; break; // Move left
        case 'D': new_position.y++; break; // Move right
        default: return false; // Invalid move
    }

    if (is_valid_move(&new_position)) {
        if (board[new_position.x][new_position.y] == TREASURE) {
            (*treasures_found)++;
        }
        if (board[new_position.x][new_position.y] == TRAP) {
            board[new_position.x][new_position.y] = EMPTY; // Remove trap
            return false; // Game over, hit a trap
        }
        board[player_position->x][player_position->y] = EMPTY; // Leave old position
        *player_position = new_position;
        board[player_position->x][player_position->y] = PLAYER; // New position
        return true; // Successful move
    }
    
    return false; // Move was invalid
}

bool is_valid_move(Position *pos) {
    return (pos->x >= 0 && pos->x < SIZE && pos->y >= 0 && pos->y < SIZE);
}

bool game_over(char board[SIZE][SIZE], int treasures_found, int total_treasures) {
    return (treasures_found == total_treasures);
}