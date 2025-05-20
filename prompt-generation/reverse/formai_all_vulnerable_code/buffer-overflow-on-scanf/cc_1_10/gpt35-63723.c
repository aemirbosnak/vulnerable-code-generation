//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define EMPTY_CELL '.'
#define PLAYER_CELL 'P'
#define ENEMY_CELL 'E'
#define TREASURE_CELL 'T'

int player_row, player_col;
int treasure_row, treasure_col;
int num_enemies;
int enemy_rows[BOARD_SIZE], enemy_cols[BOARD_SIZE];

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    
    // Set all cells to empty
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_CELL;
        }
    }

    // Set player cell
    player_row = rand() % BOARD_SIZE;
    player_col = rand() % BOARD_SIZE;
    board[player_row][player_col] = PLAYER_CELL;

    // Set treasure cell
    treasure_row = rand() % BOARD_SIZE;
    treasure_col = rand() % BOARD_SIZE;
    while (board[treasure_row][treasure_col] != EMPTY_CELL) {
        treasure_row = rand() % BOARD_SIZE;
        treasure_col = rand() % BOARD_SIZE;
    }
    board[treasure_row][treasure_col] = TREASURE_CELL;

    // Set enemy cells
    int count = 0;
    while (count < num_enemies) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        if (board[row][col] == EMPTY_CELL) {
            board[row][col] = ENEMY_CELL;
            enemy_rows[count] = row;
            enemy_cols[count] = col;
            count++;
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void move_player(char board[BOARD_SIZE][BOARD_SIZE], int dr, int dc) {
    int new_row = player_row + dr;
    int new_col = player_col + dc;
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) {
        printf("Invalid move!\n");
    } else if (board[new_row][new_col] == ENEMY_CELL) {
        printf("You were caught by the enemy and lost the game!\n");
        exit(0);
    } else if (board[new_row][new_col] == TREASURE_CELL) {
        printf("Congratulations, you won the game!\n");
        exit(0);
    } else {
        board[player_row][player_col] = EMPTY_CELL;
        board[new_row][new_col] = PLAYER_CELL;
        player_row = new_row;
        player_col = new_col;
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    printf("Welcome to Treasure Hunt!\n");
    printf("Enter the number of enemies: ");
    scanf("%d", &num_enemies);
    srand(time(NULL));
    initialize_board(board);
    print_board(board);
    while (1) {
        char move;
        printf("Enter a move (WASD): ");
        scanf(" %c", &move);
        switch (move) {
            case 'w':
            case 'W':
                move_player(board, -1, 0);
                break;
            case 'a':
            case 'A':
                move_player(board, 0, -1);
                break;
            case 's':
            case 'S':
                move_player(board, 1, 0);
                break;
            case 'd':
            case 'D':
                move_player(board, 0, 1);
                break;
            default:
                printf("Invalid move!\n");
        }
        print_board(board);
    }
    return 0;
}