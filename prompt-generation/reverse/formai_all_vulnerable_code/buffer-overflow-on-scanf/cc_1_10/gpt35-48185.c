//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdio.h>

// Define the size of the board
#define SIZE 3

// Function to print the board
void print_board(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("(%c)", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the board is full
int is_board_full(char board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if the game has been won
int check_win(char board[SIZE][SIZE], char player) {
    int i, j;
    
    // Check rows
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] != player) {
                break;
            }
        }
        if (j == SIZE) {
            return 1;
        }
    }
    
    // Check columns
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[j][i] != player) {
                break;
            }
        }
        if (j == SIZE) {
            return 1;
        }
    }
    
    // Check diagonals
    for (i = 0; i < SIZE; i++) {
        if (board[i][i] != player) {
            break;
        }
    }
    if (i == SIZE) {
        return 1;
    }
    
    for (i = 0; i < SIZE; i++) {
        if (board[i][SIZE-i-1] != player) {
            break;
        }
    }
    if (i == SIZE) {
        return 1;
    }
    
    return 0;
}

// Function to get the move from the player
void get_move(char board[SIZE][SIZE], char player) {
    int row, col;
    printf("Player %c's turn. \nEnter row (1-%d): ", player, SIZE);
    scanf("%d", &row);
    printf("Enter column (1-%d): ", SIZE);
    scanf("%d", &col);
    
    // Check if the move is valid
    while (board[row-1][col-1] != ' ') {
        printf("Invalid move, try again.\n");
        printf("Enter row (1-%d): ", SIZE);
        scanf("%d", &row);
        printf("Enter column (1-%d): ", SIZE);
        scanf("%d", &col);
    }
    
    board[row-1][col-1] = player;
}

// Function to get the move from the computer
void get_ai_move(char board[SIZE][SIZE], char ai_player) {
    int i, j;
    // Check if the computer can win on the next move
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = ai_player;
                if (check_win(board, ai_player)) {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Check if the player can win on the next move, and block them
    char human_player = (ai_player == 'X') ? 'O' : 'X';
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = human_player;
                if (check_win(board, human_player)) {
                    board[i][j] = ai_player;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Pick a random move
    do {
        i = rand() % SIZE;
        j = rand() % SIZE;
    } while (board[i][j] != ' ');
    board[i][j] = ai_player;
}

int main() {

    char board[SIZE][SIZE] = {{' ', ' ', ' '},
                              {' ', ' ', ' '},
                              {' ', ' ', ' '}};
    // Choose the player to go first
    char human_player, ai_player;
    printf("Do you want to play X or O? (X goes first): ");
    scanf("%c", &human_player);
    while (human_player != 'X' && human_player != 'O') {
        printf("Invalid choice, choose X or O: ");
        scanf("%c", &human_player);
    }
    ai_player = (human_player == 'X') ? 'O' : 'X';
    // Play the game
    int turn = 0;
    while (!is_board_full(board) && !check_win(board, human_player) && !check_win(board, ai_player)) {
        print_board(board);
        if (turn % 2 == 0) {
            get_move(board, human_player);
        } else {
            printf("AI's turn: \n");
            get_ai_move(board, ai_player);
        }
        turn++;
    }
    // Print the final board and the winner (or tie)
    print_board(board);
    if (check_win(board, human_player)) {
        printf("Human player %c wins!", human_player);
    } else if (check_win(board, ai_player)) {
        printf("AI player %c wins!", ai_player);
    } else {
        printf("It's a tie!");
    }
    return 0;
}