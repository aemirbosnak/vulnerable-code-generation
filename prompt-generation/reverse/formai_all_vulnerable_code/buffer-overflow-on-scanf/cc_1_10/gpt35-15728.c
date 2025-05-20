//FormAI DATASET v1.0 Category: Checkers Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Define the different colors for the checkers
#define BLACK 'B'
#define WHITE 'W'

// Define the different types of pieces that can be on the board
#define EMPTY '-'
#define MAN_SYM 'm'
#define KING_SYM 'k'

// Define the different directions of the board
#define UP_LEFT -1
#define UP_RIGHT -2
#define DOWN_LEFT 1
#define DOWN_RIGHT 2

// Define player turns
#define P1_TURN '1'
#define P2_TURN '2'

// Define colors for output
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET_COLOR "\033[0m"

// Function prototypes
char get_user_input(void);
void init_board(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
int is_valid_move(char board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y, char player_turn);
int is_valid_capture(char board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y, char player_turn);
int make_move(char board[][BOARD_SIZE], char player_turn);
int check_end_game(char board[][BOARD_SIZE], char player_turn);

// Game main function
int main(int argc, char const *argv[]) {
    char player_turn = P1_TURN;
    char board[BOARD_SIZE][BOARD_SIZE];

    init_board(board);

    while (!check_end_game(board, player_turn)) {
        print_board(board);

        int is_made_move = make_move(board, player_turn);

        // Switch player turn if move is made
        if (is_made_move) {
            player_turn = (player_turn == P1_TURN ? P2_TURN : P1_TURN);
        }
    }

    printf("%s\n", "Game over");

    return 0;
}

// Get user input for move
char get_user_input(void) {
    char input;
    scanf(" %c", &input);

    return input;
}

// Initialize the checkers board
void init_board(char board[][BOARD_SIZE]) {
    // Initialize empty board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Add black pieces
    for (int i = 0; i < BOARD_SIZE / 3; i++) {
        for (int j = (i + 1) % 2; j < BOARD_SIZE; j += 2) {
            board[i][j] = BLACK;
        }
    }

    // Add white pieces
    for (int i = BOARD_SIZE / 3 * 2; i < BOARD_SIZE; i++) {
        for (int j = (i + 1) % 2; j < BOARD_SIZE; j += 2) {
            board[i][j] = WHITE;
        }
    }
}

// Print the current board state
void print_board(char board[][BOARD_SIZE]) {
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf("%c ", board[i][j]);
            } else {
                // Set color based on piece color
                if (board[i][j] == BLACK) {
                    printf("%s%c%s ", RED, board[i][j], RESET_COLOR);
                } else {
                    printf("%s%c%s ", GREEN, board[i][j], RESET_COLOR);
                }
            }
        }

        printf("\n");
    }

    printf("\n");
}

// Check if a move is valid
int is_valid_move(char board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y, char player_turn) {
    char player_color = (player_turn == P1_TURN ? BLACK : WHITE);
    
    // Check if move is out of bounds
    if (to_x < 0 || to_x > BOARD_SIZE - 1 || to_y < 0 || to_y > BOARD_SIZE - 1) {
        return 0;
    }

    // Check if player is trying to move empty location
    if (board[from_x][from_y] == EMPTY) {
        return 0;
    }

    // Check if player is trying to move opponent's piece
    if (board[from_x][from_y] != player_color) {
        return 0;
    }

    // Check if move direction is correct
    if (player_color == BLACK && to_x >= from_x) {
        return 0;
    }

    if (player_color == WHITE && to_x <= from_x) {
        return 0;
    }

    // Check if move is diagonal
    if (abs(from_x - to_x) != abs(from_y - to_y)) {
        return 0;
    }

    // Check if piece is trying to move more than one space diagonally
    if (abs(from_x - to_x) > 2) {
        return 0;
    }

    // Check if move is not more than one space diagonally unless it's a capture
    if (abs(from_x - to_x) == 2 && !is_valid_capture(board, from_x, from_y, to_x, to_y, player_turn)) {
        return 0;
    }

    return 1;
}

// Check if a capture move is valid
int is_valid_capture(char board[][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y, char player_turn) {
    char player_color = (player_turn == P1_TURN ? BLACK : WHITE);
    char opposing_color = (player_turn == P1_TURN ? WHITE : BLACK);

    int x_dir = from_x - to_x > 0 ? -1 : 1;
    int y_dir = from_y - to_y > 0 ? -1 : 1;
    int middle_x = (from_x + to_x) / 2;
    int middle_y = (from_y + to_y) / 2;

    // Check if there is a piece in between source and destination
    if (board[middle_x][middle_y] != opposing_color) {
        return 0;
    }

    // Check if there is no piece to capture at destination
    if (board[to_x][to_y] != EMPTY) {
        return 0;
    }

    return 1;
}

// Make a move for the current player
int make_move(char board[][BOARD_SIZE], char player_turn) {
    char player_color = (player_turn == P1_TURN ? BLACK : WHITE);

    printf("Player %c's turn: enter move (eg. a1 b2): ", player_turn);

    int from_x, from_y, to_x, to_y;
    scanf(" %c%d %c%d", &from_y, &from_x, &to_y, &to_x);
    from_x--;
    from_y -= 'a';
    to_x--;
    to_y -= 'a';

    // Check if move is valid
    if (!is_valid_move(board, from_x, from_y, to_x, to_y, player_turn)) {
        printf("%sInvalid move. Try again.%s\n", RED, RESET_COLOR);
        return 0;
    }

    // Move piece
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = EMPTY;

    // Check if piece has been promoted to a king
    if (to_x == 0 && player_color == BLACK) {
        board[to_x][to_y] = KING_SYM;
    }

    if (to_x == BOARD_SIZE - 1 && player_color == WHITE) {
        board[to_x][to_y] = KING_SYM;
    }

    // Check if capture move has been made
    if (abs(from_x - to_x) == 2) {
        int x_dir = from_x - to_x > 0 ? -1 : 1;
        int y_dir = from_y - to_y > 0 ? -1 : 1;
        int middle_x = (from_x + to_x) / 2;
        int middle_y = (from_y + to_y) / 2;

        board[middle_x][middle_y] = EMPTY;
    }

    return 1;
}

// Check if game has ended
int check_end_game(char board[][BOARD_SIZE], char player_turn) {
    char player_color = (player_turn == P1_TURN ? BLACK : WHITE);
    int has_won = 1;

    // Check if any pieces of current player remain
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player_color || board[i][j] == KING_SYM) {
                has_won = 0;
            }
        }
    }

    // Print result if game has ended
    if (has_won) {
        printf("%sPlayer %c has won the game!%s\n", GREEN, player_turn, RESET_COLOR);
        return 1;
    }

    return 0;
}