//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE]; // Game board
char currentPlayer;     // Current player
char computerPlayer;    // Computer's player character

// Function prototypes
void initializeBoard();
void printBoard();
bool isWinner(char player);
bool isBoardFull();
void playerMove();
void computerMove();
void playGame();
void chooseCharacter();

int main() {
    chooseCharacter();
    playGame();
    return 0;
}

void chooseCharacter() {
    printf("Welcome to the enchanted Tic Tac Toe realm!\n");
    printf("Choose your character (X or O): ");
    while (true) {
        currentPlayer = getchar();
        if (currentPlayer == 'X' || currentPlayer == 'O') {
            computerPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            printf("You chose '%c'. The computer will play '%c'.\n", currentPlayer, computerPlayer);
            break;
        } else {
            printf("Invalid choice. Please choose either 'X' or 'O': ");
            while(getchar() != '\n'); // Clear the input buffer
        }
    }
    getchar(); // Consume the newline character
}

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
}

bool isWinner(char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playerMove() {
    int row, col;
    while (true) {
        printf("Your turn! Enter row (0-2) and column (0-2): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void computerMove() {
    printf("The wise computer is making its move...\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = computerPlayer;
                if (isWinner(computerPlayer)) {
                    return; // Take winning move
                }
                board[i][j] = ' '; // Reset after checking
            }
        }
    }
    // Otherwise, pick a random available position
    while (true) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (board[row][col] == ' ') {
            board[row][col] = computerPlayer;
            break;
        }
    }
}

void playGame() {
    initializeBoard();
    printBoard();
    
    while (true) {
        playerMove();
        printBoard();
        if (isWinner(currentPlayer)) {
            printf("Congratulations! You've conquered the computer!\n");
            break;
        }
        if (isBoardFull()) {
            printf("It's a tie! The board is full.\n");
            break;
        }
        
        computerMove();
        printBoard();
        if (isWinner(computerPlayer)) {
            printf("Oh no! The computer has outsmarted you!\n");
            break;
        }
        if (isBoardFull()) {
            printf("It's a tie! The board is full.\n");
            break;
        }
    }
}