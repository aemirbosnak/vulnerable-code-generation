//GEMINI-pro DATASET v1.0 Category: Game ; Style: interoperable
#include <stdio.h>

// Define the board size
#define BOARD_SIZE 3

// Define the player symbols
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define the game state
enum GameState {
    GAME_IN_PROGRESS,
    PLAYER_X_WINS,
    PLAYER_O_WINS,
    TIE
};

// Define the board type
typedef char Board[BOARD_SIZE][BOARD_SIZE];

// Check if a player has won
int check_win(Board board, char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Check if the game is a tie
int check_tie(Board board) {
    // Check if all cells are filled
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 1;
}

// Print the board
void print_board(Board board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Get the player's move
int get_move(Board board, char player) {
    int row, col;

    printf("Player %c, enter your move (row, column): ", player);
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        printf("Invalid move. Please try again.\n");
        return -1;
    }

    return 0;
}

// Play the game
int play_game() {
    // Create the board
    Board board;

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Set the current player to player X
    char current_player = PLAYER_X;

    // Play the game until someone wins or there is a tie
    while (1) {
        // Get the player's move
        if (get_move(board, current_player) == -1) {
            continue;
        }

        // Place the player's symbol on the board
        int row, col;
        scanf("%d %d", &row, &col);
        board[row][col] = current_player;

        // Print the board
        print_board(board);

        // Check if the player has won
        if (check_win(board, current_player)) {
            printf("Player %c wins!\n", current_player);
            return 0;
        }

        // Check if the game is a tie
        if (check_tie(board)) {
            printf("Tie game!\n");
            return 0;
        }

        // Switch the current player
        current_player = current_player == PLAYER_X ? PLAYER_O : PLAYER_X;
    }

    return 0;
}

int main() {
    play_game();
    return 0;
}