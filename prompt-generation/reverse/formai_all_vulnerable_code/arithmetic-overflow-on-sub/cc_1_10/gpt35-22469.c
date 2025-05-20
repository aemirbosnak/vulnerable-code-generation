//FormAI DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>

// Declare a 3x3 integer array to represent the game board
int board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

// Declare a function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch (board[i][j]) {
                case 0:
                    printf("   ");
                    break;
                case 1:
                    printf(" X ");
                    break;
                case 2:
                    printf(" O ");
                    break;
            }
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Declare a function to check if a player has won the game
int check_win(int player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        return 1;
    }
    return 0;
}

int main() {
    // Declare variables to keep track of the current player and the number of turns taken
    int player = 1;
    int turn = 0;
    
    // Print the initial game board
    print_board();
    
    // Enter the main game loop
    while (1) {
        // Increment the turn counter
        turn++;
        
        // Get the player's move
        int row, col;
        printf("Player %d's turn. Enter row (1-3): ", player);
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        
        // Check if the move is valid (i.e. the chosen cell is empty)
        if (board[row-1][col-1] != 0) {
            printf("That cell is not empty. Please choose a different cell.\n");
            continue;
        }
        
        // Update the game board with the player's move
        board[row-1][col-1] = player;
        
        // Print the updated game board
        print_board();
        
        // Check if the player has won the game
        if (check_win(player)) {
            printf("Player %d wins!\n", player);
            break;
        }
        
        // Check if the game has ended in a tie (all cells are filled)
        if (turn == 9) {
            printf("The game has ended in a tie.\n");
            break;
        }
        
        // Switch to the other player's turn
        player = (player == 1) ? 2 : 1;
    }
    
    return 0;
}