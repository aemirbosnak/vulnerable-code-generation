//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 6
#define COL 16
#define WINSCORE 10

struct Player {
    char name[20];
    int score;
};

// Display the game board
void displayBoard(char board[][COL+1], struct Player p1, struct Player p2) {
    system("clear");

    printf("Score: %s = %d\t%s = %d\n", p1.name, p1.score, p2.name, p2.score);
    printf("  1 2 3 4 5 6 7 8 9 1011121314 15 16\n");
    printf(" +--------------------------------+\n");
    for(int i = 0; i < ROW; i++) {
        printf("%d|", i+1);
        for(int j = 0; j < COL; j++) {
            printf("%c", board[i][j]);
        }
        printf("|\n");
    }
    printf(" +--------------------------------+\n");
}

// Returns 1 if the move is valid
int isValidMove(char board[][COL+1], int row, int col) {
    if(board[row][col] == ' ') {
        if(row == ROW-1) {
            return 1; // Valid move
        } else if(board[row+1][col] != ' ') {
            return 1; // Valid move
        }
    }
    return 0; // Invalid move
}

// Adds the player character in the given column for the given player
void makeMove(char board[][COL+1], int col, char c) {
    for(int i = ROW-1; i >= 0; i--) {
        if(board[i][col] == ' ') {
            board[i][col] = c;
            break;
        }
    }
}

// Returns 1 if the player with the given character wins
int checkWin(char board[][COL+1], char c) {
    // Check horizontal
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL-3; j++) {
            if(board[i][j] == c &&
                board[i][j+1] == c &&
                board[i][j+2] == c &&
                board[i][j+3] == c) {
                return 1; // Win
            }
        }
    }

    // Check vertical
    for(int j = 0; j < COL; j++) {
        for(int i = 0; i < ROW-3; i++) {
            if(board[i][j] == c &&
                board[i+1][j] == c &&
                board[i+2][j] == c &&
                board[i+3][j] == c) {
                return 1; // Win
            }
        }
    }

    // Check diagonal down-right
    for(int i = 0; i < ROW-3; i++) {
        for(int j = 0; j < COL-3; j++) {
            if(board[i][j] == c &&
                board[i+1][j+1] == c &&
                board[i+2][j+2] == c &&
                board[i+3][j+3] == c) {
                return 1; // Win
            }
        }
    }

    // Check diagonal up-right
    for(int i = 3; i < ROW; i++) {
        for(int j = 0; j < COL-3; j++) {
            if(board[i][j] == c &&
                board[i-1][j+1] == c &&
                board[i-2][j+2] == c &&
                board[i-3][j+3] == c) {
                return 1; // Win
            }
        }
    }

    // No win
    return 0;
}

// Play the game
void playGame() {
    struct Player p1, p2;
    char board[ROW][COL+1];
    int col;
    char c;
    int player = 1; // Player 1 starts

    system("clear");
    printf("Welcome to Connect Four!\n\n");
    printf("Player 1, enter your name: ");
    scanf("%s", p1.name);
    printf("Player 2, enter your name: ");
    scanf("%s", p2.name);

    p1.score = p2.score = 0;

    while(1) {
        // Initialize the board
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                board[i][j] = ' ';
            }
            board[i][COL] = '\0';
        }

        // Play until there is a winner or the board is full
        while(1) {
            displayBoard(board, p1, p2);
            if(player == 1) {
                printf("%s's turn (O): ", p1.name);
                c = 'O';
            } else {
                printf("%s's turn (X): ", p2.name);
                c = 'X';
            }
            scanf("%d", &col);
            col--; // Convert to 0-based index

            if(col >= 0 && col < COL && isValidMove(board, 0, col)) {
                makeMove(board, col, c);
                if(checkWin(board, c)) {
                    displayBoard(board, p1, p2);
                    printf("Congratulations %s, you win!\n", (player == 1) ? p1.name : p2.name);
                    if(player == 1) {
                        p1.score++;
                    } else {
                        p2.score++;
                    }
                    break; // Exit the game
                }
                player = (player == 1) ? 2 : 1; // Switch player
            } else {
                printf("Invalid move, try again.\n");
            }

            // Check for a tie
            int tie = 1;
            for(int j = 0; j < COL; j++) {
                if(isValidMove(board, 0, j)) {
                    tie = 0;
                    break;
                }
            }
            if(tie) {
                displayBoard(board, p1, p2);
                printf("It's a tie!\n");
                break; // Exit the game
            }
        }

        // Check for a winner
        if(p1.score == WINSCORE) {
            printf("\nCongratulations %s, you are the Connect Four Champion!\n", p1.name);
            break; // Exit the tournament
        } else if(p2.score == WINSCORE) {
            printf("\nCongratulations %s, you are the Connect Four Champion!\n", p2.name);
            break; // Exit the tournament
        }

        // Play again?
        char ans;
        printf("\nDo you want to play again? [y/n]: ");
        scanf(" %c", &ans);
        if(ans == 'y' || ans == 'Y') {
            player = (player == 1) ? 2 : 1; // Switch player
        } else {
            break; // Exit the tournament
        }
    }

    printf("\nThanks for playing Connect Four!\n\n");
}

int main() {
    srand(time(NULL));

    while(1) {
        playGame();

        // Play again?
        char ans;
        printf("Do you want to play again? [y/n]: ");
        scanf(" %c", &ans);
        if(ans == 'n' || ans == 'N') {
            break;
        }
    }

    return 0;
}