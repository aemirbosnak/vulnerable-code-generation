//FormAI DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>

char board[8][8] = { // initial position of checkers board
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'b', '_', 'b', '_', 'b', '_', 'b', '_'},
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'w', '_', 'w', '_', 'w', '_', 'w', '_'},
    {'_', 'w', '_', 'w', '_', 'w', '_', 'w'},
    {'w', '_', 'w', '_', 'w', '_', 'w', '_'}
};

void displayBoard() { // display the current board state
    int i, j;
    printf("  0 1 2 3 4 5 6 7 \n"); // the x axis
    for (i = 0; i < 8; i++) {
        printf("%d ", i); // the y axis
        for (j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    displayBoard(); // display the initial board

    char player = 'w'; // white player move first
    int fromX, fromY, toX, toY;
    while (1) {
        printf("Player %c's turn\n", player);
        printf("Enter from position (x,y): ");
        scanf("%d %d", &fromX, &fromY);
        printf("Enter to position (x,y): ");
        scanf("%d %d", &toX, &toY);
        
        if (fromX < 0 || fromX > 7 || fromY < 0 || fromY > 7 || toX < 0 || toX > 7 || toY < 0 || toY > 7) { // out of board range
            printf("Invalid move, position out of board range.\n");
            continue;
        }
        if (board[fromX][fromY] != player && board[fromX][fromY] != player - 32) { // not the player's checker piece
            printf("Invalid move, not your checker piece.\n");
            continue;
        }
        if (board[toX][toY] != '_') { // destination position already occupied
            printf("Invalid move, destination position already occupied.\n");
            continue;
        }
        if (player == 'w') { // white player's move
            if (fromY == toY && toX == fromX - 1 && board[toX][toY] == '_') { // simple move
                board[toX][toY] = 'w';
                board[fromX][fromY] = '_';
            } else if (fromY == toY + 1 && toX == fromX - 1 && board[toX][toY] == 'b' || fromY == toY - 1 && toX == fromX - 1 && board[toX][toY] == 'b') { // capture move
                board[toX][toY] = 'w';
                board[fromX][fromY] = '_';
                board[(fromX + toX) / 2][(fromY + toY) / 2] = '_';
            } else {
                printf("Invalid move, please try again.\n");
                continue;
            }
            if (toX == 0) { // white player wins the game
                printf("Player %c wins!\n", player);
                break;
            }
            player = 'b'; // switch player
        } else { // black player's move
            if (fromY == toY && toX == fromX + 1 && board[toX][toY] == '_') { // simple move
                board[toX][toY] = 'b';
                board[fromX][fromY] = '_';
            } else if (fromY == toY + 1 && toX == fromX + 1 && board[toX][toY] == 'w' || fromY == toY - 1 && toX == fromX + 1 && board[toX][toY] == 'w') { // capture move
                board[toX][toY] = 'b';
                board[fromX][fromY] = '_';
                board[(fromX + toX) / 2][(fromY + toY) / 2] = '_';
            } else {
                printf("Invalid move, please try again.\n");
                continue;
            }
            if (toX == 7) { // black player wins the game
                printf("Player %c wins!\n", player);
                break;
            }
            player = 'w'; // switch player
        }
        displayBoard(); // display the current board state
    }
    return 0;
}