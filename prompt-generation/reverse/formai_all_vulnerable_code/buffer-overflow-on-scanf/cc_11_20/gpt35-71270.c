//FormAI DATASET v1.0 Category: Table Game ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the board
void display_board(int board[][3], int player1_pos[], int player2_pos[]) {
    // Clear the console
    system("clear");

    // Print the board
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == 0) {
                printf("  -  ");
            } else if(board[i][j] == 1) {
                printf("  X  ");
            } else {
                printf("  O  ");
            }
        }
        printf("\n");
    }

    // Print the player positions
    printf("Player 1: (%d, %d)\n", player1_pos[0], player1_pos[1]);
    printf("Player 2: (%d, %d)\n", player2_pos[0], player2_pos[1]);
}

// Function to check if any player has won
int check_win(int board[][3], int player) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for(int i=0; i<3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    // Initialize the board
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Initialize the positions of player 1 and player 2
    int player1_pos[2] = {0, 0};
    int player2_pos[2] = {2, 2};

    // Set the random seed
    srand(time(NULL));

    // Set the starting player
    int current_player = rand() % 2 + 1;

    // Loop until someone wins or there are no more moves left
    while(1) {
        // Display the board
        display_board(board, player1_pos, player2_pos);

        // If player 1 is playing
        if(current_player == 1) {
            printf("Player 1's turn:\n");

            // Ask for the new position
            int new_pos[2];
            printf("Enter new position (row, column): ");
            scanf("%d %d", &new_pos[0], &new_pos[1]);

            // Check if the new position is valid
            while(new_pos[0]<0 || new_pos[0]>2 || new_pos[1]<0 || new_pos[1]>2 || (new_pos[0]==player2_pos[0] && new_pos[1]==player2_pos[1])) {
                printf("Invalid position. Enter new position (row, column): ");
                scanf("%d %d", &new_pos[0], &new_pos[1]);
            }

            // Update the board and player position
            board[player1_pos[0]][player1_pos[1]] = 0;
            player1_pos[0] = new_pos[0];
            player1_pos[1] = new_pos[1];
            board[player1_pos[0]][player1_pos[1]] = 1;

            // Check if player 1 has won
            if(check_win(board, 1) == 1) {
                printf("\nPlayer 1 has won!\n");
                break;
            }

            // Switch to player 2
            current_player = 2;
        } 
        // If player 2 is playing
        else {
            printf("Player 2's turn (computer):\n");

            // Generate a random position
            int new_pos[2] = {-1, -1};
            while(new_pos[0]<0 || new_pos[0]>2 || new_pos[1]<0 || new_pos[1]>2 || (new_pos[0]==player1_pos[0] && new_pos[1]==player1_pos[1])) {
                new_pos[0] = rand() % 3;
                new_pos[1] = rand() % 3;
            }

            // Update the board and player position
            board[player2_pos[0]][player2_pos[1]] = 0;
            player2_pos[0] = new_pos[0];
            player2_pos[1] = new_pos[1];
            board[player2_pos[0]][player2_pos[1]] = 2;

            // Check if player 2 has won
            if(check_win(board, 2) == 1) {
                printf("\nPlayer 2 has won!\n");
                break;
            }

            // Switch to player 1
            current_player = 1;
        }

        // Check if there are no more moves left
        int moves_left = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == 0) {
                    moves_left = 1;
                }
            }
        }

        if(moves_left == 0) {
            printf("\nNo more moves left. The game is a tie!\n");
            break;
        }
    }

    return 0;
}