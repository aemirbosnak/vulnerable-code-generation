//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BOARD_SIZE 8
#define EMPTY '-'
#define PLAYER_X 'X'
#define PLAYER_O 'O'

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return 0;
    }
    return board[row][col] == EMPTY;
}

void make_move(int row, int col, char player) {
    if (is_valid_move(row, col)) {
        board[row][col] = player;
    }
}

void mock_ai_move(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                make_move(i, j, player);
                return;
            }
        }
    }
}

void ai_process(char player) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Child process
        printf("AI Process for player %c is thinking...\n", player);
        sleep(2); // Simulate thinking time
        mock_ai_move(player);
        exit(0);
    }
    wait(NULL); // Parent waits for child to finish
}

int main() {
    initialize_board();
    char current_player = PLAYER_X;

    while (1) {
        printf("Current Board:\n");
        print_board();

        if (current_player == PLAYER_X) {
            int row, col;
            printf("Player X turn! Enter row and column (0-7): ");
            scanf("%d %d", &row, &col);
            make_move(row, col, current_player);
        } else {
            printf("AI is making a move for Player O...\n");
            ai_process(PLAYER_O);
        }

        // Switch players
        current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;

        // Simple check for a draw (if all spaces filled)
        int draw = 1;
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++)
                if (board[i][j] == EMPTY)
                    draw = 0;
        if (draw) {
            printf("The game is a draw!\n");
            break;
        }
    }

    printf("Final Board:\n");
    print_board();
    return 0;
}