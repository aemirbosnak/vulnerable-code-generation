//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
/* 
   This program is an example of a Tic Tac Toe game with AI player in C programming language.
   The player is able to choose whether to play with X or O and the AI player will choose the opposite.
   The AI player follows a simple strategy to make its moves:
   1. If it can win during the next move, it will choose that move.
   2. If it cannot win during the next move, but the opponent can win, it will block that move.
   3. Otherwise, it will choose a random available move.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int get_move(char board[BOARD_SIZE][BOARD_SIZE], char player);
int find_winning_move(char board[BOARD_SIZE][BOARD_SIZE], char player);
int find_blocking_move(char board[BOARD_SIZE][BOARD_SIZE], char player);
int random_move(char board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char player, ai_player;
    int turn = 0, move, game_status;

    // Initialize the board
    initialize_board(board);

    // Choose X or O to play with
    printf("Choose X or O (X goes first): ");
    scanf("%c", &player);
    ai_player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    printf("\n");

    // Game loop
    while (1) {
        // Alternate turns
        turn = turn == PLAYER_X ? PLAYER_O : PLAYER_X;

        // Print the board
        printf("Board:\n");
        print_board(board);

        // Get the move from the player or AI
        if (turn == player) {
            printf("%c's turn. Choose a move (1-9): ", player);
            scanf("%d", &move);
            printf("\n");

            // Convert move to row and column
            int row = (move - 1) / BOARD_SIZE;
            int col = (move - 1) % BOARD_SIZE;

            // Check if the move is valid
            if (board[row][col] != ' ') {
                printf("Invalid move. Please choose an empty cell.\n");
                continue;
            }

            // Make the move
            board[row][col] = player;
        } else {
            printf("%c's turn. Thinking...\n", ai_player);

            // AI player strategy
            move = find_winning_move(board, ai_player);
            if (move == -1) {
                move = find_blocking_move(board, player);
            }
            if (move == -1) {
                move = random_move(board);
            }

            // Convert move to row and column
            int row = (move - 1) / BOARD_SIZE;
            int col = (move - 1) % BOARD_SIZE;

            // Make the move
            board[row][col] = ai_player;
        }

        // Check if the game is over
        game_status = check_game_status(board);

        if (game_status == PLAYER_X) {
            printf("X wins!\n");
            break;
        } else if (game_status == PLAYER_O) {
            printf("O wins!\n");
            break;
        } else if (game_status == 0) {
            printf("Tie game!\n");
            break;
        }
    }

    return 0;
}

// Initialize the board to all empty cells
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("| ");
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
    }
}

// Get the move from the player
int get_move(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int move;
    printf("%c's turn. Choose a move (1-9): ", player);
    scanf("%d", &move);
    printf("\n");

    // Convert move to row and column
    int row = (move - 1) / BOARD_SIZE;
    int col = (move - 1) % BOARD_SIZE;

    // Check if the move is valid
    if (board[row][col] != ' ') {
        printf("Invalid move. Please choose an empty cell.\n");
        return get_move(board, player);
    }

    return move;
}

// Find a winning move for the given player
int find_winning_move(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int i, j;
    char other_player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        int empty_cell = -1;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                count++;
            } else if (board[i][j] == other_player) {
                count = -1;
                break;
            } else {
                empty_cell = i * BOARD_SIZE + j + 1;
            }
        }
        if (count == BOARD_SIZE - 1 && empty_cell != -1) {
            return empty_cell;
        }
    }

    // Check columns
    for (j = 0; j < BOARD_SIZE; j++) {
        int count = 0;
        int empty_cell = -1;
        for (i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j] == player) {
                count++;
            } else if (board[i][j] == other_player) {
                count = -1;
                break;
            } else {
                empty_cell = i * BOARD_SIZE + j + 1;
            }
        }
        if (count == BOARD_SIZE - 1 && empty_cell != -1) {
            return empty_cell;
        }
    }

    // Check diagonal (top-left to bottom-right)
    int count = 0;
    int empty_cell = -1;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] == player) {
            count++;
        } else if (board[i][i] == other_player) {
            count = -1;
            break;
        } else {
            empty_cell = i * BOARD_SIZE + i + 1;
        }
    }
    if (count == BOARD_SIZE - 1 && empty_cell != -1) {
        return empty_cell;
    }

    // Check diagonal (top-right to bottom-left)
    count = 0;
    empty_cell = -1;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE - i - 1] == player) {
            count++;
        } else if (board[i][BOARD_SIZE - i - 1] == other_player) {
            count = -1;
            break;
        } else {
            empty_cell = i * BOARD_SIZE + BOARD_SIZE - i;
        }
    }
    if (count == BOARD_SIZE - 1 && empty_cell != -1) {
        return empty_cell;
    }

    return -1; // No winning move found
}

// Find a blocking move for the given player
int find_blocking_move(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    char other_player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    return find_winning_move(board, other_player);
}

// Choose a random available move
int random_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    int empty_cells[BOARD_SIZE * BOARD_SIZE], num_empty_cells = 0;
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                empty_cells[num_empty_cells] = i * BOARD_SIZE + j + 1;
                num_empty_cells++;
            }
        }
    }
    if (num_empty_cells == 0) {
        return -1; // No available moves
    }
    srand(time(NULL));
    int index = rand() % num_empty_cells;
    return empty_cells[index];
}

// Check if the game is over
int check_game_status(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonal (top-left to bottom-right)
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    // Check diagonal (top-right to bottom-left)
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // Check if the board is full
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return -1; // Game is not over yet
            }
        }
    }

    return 0; // Tie game
}