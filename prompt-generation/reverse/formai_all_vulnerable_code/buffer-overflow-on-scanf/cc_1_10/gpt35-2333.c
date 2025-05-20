//FormAI DATASET v1.0 Category: Checkers Game ; Style: complex
#include <stdio.h>
#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
char player1_color, player2_color;
int player1_turn = 1; // Player 1 gets the first turn by default
int pieces_count[2]; // Number of pieces for each player

void initialize_board() {
    int i, j;

    // Fill the entire board with empty spaces
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Fill the first 3 rows with player 1's pieces
    for (i = 0; i < 3; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = player1_color;
                pieces_count[0]++;
            }
        }
    }

    // Fill the last 3 rows with player 2's pieces
    for (i = BOARD_SIZE - 1; i >= BOARD_SIZE - 3; i--) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = player2_color;
                pieces_count[1]++;
            }
        }
    }
}

int is_valid_move(int curr_row, int curr_col, int new_row, int new_col) {
    // Check if the new position is within the board boundaries
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE) {
        return 0;
    }

    // Check if the new position is empty
    if (board[new_row][new_col] != ' ') {
        return 0;
    }

    // Check if the new position is one step away horizontally or diagonally
    if (abs(new_row - curr_row) != 1 || abs(new_col - curr_col) != 1) {
        return 0;
    }

    // If the player is not jumping over another piece, return 1
    if (abs(new_row - curr_row) == 1 && abs(new_col - curr_col) == 1) {
        return 1;
    }

    // Check if the player is jumping over an opponent's piece
    int opponent_row = (new_row + curr_row) / 2;
    int opponent_col = (new_col + curr_col) / 2;

    if (board[opponent_row][opponent_col] != (player1_turn ? player2_color : player1_color)) {
        return 0;
    }

    return 1;
}

int perform_move(int curr_row, int curr_col, int new_row, int new_col) {
    // Check if the move is valid
    if (!is_valid_move(curr_row, curr_col, new_row, new_col)) {
        return 0;
    }

    // Move the player's piece to the new position
    board[new_row][new_col] = board[curr_row][curr_col];
    board[curr_row][curr_col] = ' ';

    // If the player is jumping over an opponent's piece, remove it from the board
    if (abs(new_row - curr_row) == 2 && abs(new_col - curr_col) == 2) {
        int opponent_row = (new_row + curr_row) / 2;
        int opponent_col = (new_col + curr_col) / 2;

        board[opponent_row][opponent_col] = ' ';

        pieces_count[player1_turn ? 1 : 0]--;
    }

    return 1;
}

int game_over() {
    // Check if any of the players have no pieces left
    if (pieces_count[player1_turn ? 1 : 0] == 0) {
        return 1;
    }

    // Check if any of the players have no valid moves left
    int i, j, curr_row, curr_col;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == (player1_turn ? player1_color : player2_color)) {
                curr_row = i;
                curr_col = j;

                if (is_valid_move(curr_row, curr_col, curr_row + 1, curr_col + 1) ||
                    is_valid_move(curr_row, curr_col, curr_row + 1, curr_col - 1) ||
                    is_valid_move(curr_row, curr_col, curr_row - 1, curr_col + 1) ||
                    is_valid_move(curr_row, curr_col, curr_row - 1, curr_col - 1)) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

void print_board() {
    int i, j;

    // Print the column numbers
    printf("  ");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", i + 1);
    }

    printf("\n");

    // Print the row numbers and the board content
    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %c ", 'A' + i);

        for (j = 0; j < BOARD_SIZE; j++) {
            printf("|%c|", board[i][j]);
        }

        printf(" %c \n", 'A' + i);
    }

    // Print the column numbers again
    printf("  ");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", i + 1);
    }

    printf("\n");
}

int main() {
    int curr_row, curr_col, new_row, new_col;

    // Get the players' colors
    printf("Enter player 1's color: ");
    scanf(" %c", &player1_color);

    printf("Enter player 2's color: ");
    scanf(" %c", &player2_color);

    // Initialize the board and print it
    initialize_board();
    print_board();

    // Play the game until it's over
    while (!game_over()) {
        // Ask the player to make a move
        printf("Player %d's turn: ", player1_turn ? 1 : 2);
        scanf(" %c%d %c%d", &curr_row, &curr_col, &new_row, &new_col);

        // Convert the input to array indices
        curr_row -= 'A';
        curr_col--;
        new_row -= 'A';
        new_col--;

        // Perform the move and print the board
        if (perform_move(curr_row, curr_col, new_row, new_col)) {
            pieces_count[player1_turn ? 0 : 1]--;
            player1_turn = !player1_turn;
            print_board();
        } else {
            printf("Invalid move!\n");
        }
    }

    // Print the winner
    printf("Player %d wins!", player1_turn ? 1 : 2);

    return 0;
}