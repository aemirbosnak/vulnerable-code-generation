//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: genious
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
int user_score = 0, computer_score = 0;

// Function to initialize the game board
void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to draw the game board
void draw_board() {
    int i, j;
    printf("-------------\n");
    for (i = 0; i < 3; i++) {
        printf("| ");
        for (j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

// Function to check if the move is valid
int is_valid_move(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return 0;
    }
    else if (board[row][col] != ' ') {
        return 0;
    }
    else {
        return 1;
    }
}

// Function to check if the game is over
int is_game_over() {
    int i, j;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                user_score++;
            }
            else if (board[i][0] == 'O') {
                computer_score++;
            }
            return 1;
        }
    }
    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X') {
                user_score++;
            }
            else if (board[0][j] == 'O') {
                computer_score++;
            }
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            user_score++;
        }
        else if (board[0][0] == 'O') {
            computer_score++;
        }
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            user_score++;
        }
        else if (board[0][2] == 'O') {
            computer_score++;
        }
        return 1;
    }
    // Check if board is full
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 2;
}

// Function to let user make a move
void user_move() {
    int row, col;
    printf("Enter row and column (0-2): ");
    scanf("%d %d", &row, &col);
    if (is_valid_move(row, col)) {
        board[row][col] = 'X';
    }
    else {
        printf("Invalid move. Try again.\n");
        user_move();
    }
}

// Function to let computer make a move
void computer_move() {
    int i, j, row, col;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                if (is_game_over() == 1) {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                if (is_game_over() == 1) {
                    board[i][j] = 'O';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!is_valid_move(row, col));
    board[row][col] = 'O';
}

int main() {
    int choice;
    printf("Welcome to Tic Tac Toe!\n");
    printf("-----------------------\n");
    printf("1. Start Game\n");
    printf("2. Exit Game\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        initialize_board();
        do {
            draw_board();
            user_move();
            if (is_game_over() == 1) {
                draw_board();
                printf("Game over. You win!\n");
                printf("Your score: %d\n", user_score);
                printf("Computer score: %d\n", computer_score);
                printf("-----------------------\n");
                printf("1. Play Again\n");
                printf("2. Exit Game\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    initialize_board();
                    user_score = 0;
                    computer_score = 0;
                }
            }
            else if (is_game_over() == 2) {
                draw_board();
                printf("Game over. It's a tie!\n");
                printf("Your score: %d\n", user_score);
                printf("Computer score: %d\n", computer_score);
                printf("-----------------------\n");
                printf("1. Play Again\n");
                printf("2. Exit Game\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    initialize_board();
                    user_score = 0;
                    computer_score = 0;
                }
            }
            else {
                computer_move();
                if (is_game_over() == 1) {
                    draw_board();
                    printf("Game over. Computer wins!\n");
                    printf("Your score: %d\n", user_score);
                    printf("Computer score: %d\n", computer_score);
                    printf("-----------------------\n");
                    printf("1. Play Again\n");
                    printf("2. Exit Game\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    if (choice == 1) {
                        initialize_board();
                        user_score = 0;
                        computer_score = 0;
                    }
                }
            }
        } while (choice != 2);
    }
    return 0;
}