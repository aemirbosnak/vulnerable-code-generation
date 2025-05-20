//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board
void init_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to print the board
void print_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
int game_over() {
    int i, j;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return 1;
    }

    // Game is not over yet
    return 0;
}

// Function to make a move
void make_move(int row, int col, char symbol) {
    board[row][col] = symbol;
}

// Function to get the move from the user
void get_move(char symbol) {
    int row, col;
    printf("\n");
    printf("Enter row and column for %c: ", symbol);
    scanf("%d %d", &row, &col);
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        printf("Invalid move, please try again.\n");
        get_move(symbol);
    } else if (board[row][col] != '-') {
        printf("That position is already taken, please try again.\n");
        get_move(symbol);
    } else {
        make_move(row, col, symbol);
    }
}

// Function to get the AI move
void get_ai_move(char symbol) {
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != '-');
    make_move(row, col, symbol);
}

// Function to play the game
void play_game() {
    char player_symbol = 'X';
    char ai_symbol = 'O';
    int turn = 1;

    init_board();
    print_board();

    while (!game_over()) {
        if (turn == 1) {
            get_move(player_symbol);
        } else {
            get_ai_move(ai_symbol);
        }
        print_board();
        turn = !turn;
    }

    printf("\n");
    if (turn == 1) {
        printf("Congratulations! You Won!\n");
    } else {
        printf("Sorry, You Lost!\n");
    }
}

int main() {
    play_game();
    return 0;
}