//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// All possible winning combinations
int winning_combinations[8][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7}};

// Function to check if a player has won the game
int check_win(int board[], int player) {
    int i, j;
    for(i = 0; i < 8; i++) {
        int count = 0;
        for(j = 0; j < 3; j++) {
            if(board[winning_combinations[i][j]-1] == player) {
                count++;
            }
        }
        if(count == 3) {
            return 1;
        }
    }
    return 0;
}

// Function to get the player's move
int get_player_move(int board[]) {
    int move;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    while(board[move-1] != 0) {
        printf("Invalid move. Please enter a valid move (1-9): ");
        scanf("%d", &move);
    }

    return move;
}

// Function to get the AI's move
int get_ai_move(int board[]) {
    int i, j;
    for(i = 0; i < 8; i++) {
        int count_player = 0, count_ai = 0, empty_slot = 0;
        
        for(j = 0; j < 3; j++) {
            if(board[winning_combinations[i][j]-1] == 1) {
                count_player++;
            } else if(board[winning_combinations[i][j]-1] == -1) {
                count_ai++;
            } else {
                empty_slot = winning_combinations[i][j];
            }
        }
        
        if(count_player == 2 && empty_slot != 0) {
            return empty_slot;
        } else if(count_ai == 2 && empty_slot != 0) {
            return empty_slot;
        }
    }
    
    int available_moves[9], num_moves = 0;
    for(i = 0; i < 9; i++) {
        if(board[i] == 0) {
            available_moves[num_moves] = i+1;
            num_moves++;
        }
    }
    
    if(num_moves == 0) {
        return -1;
    }
    
    srand(time(NULL));
    int random_index = rand() % num_moves;
    return available_moves[random_index];
}

int main() {
    int board[9] = {0}; // Initialize the board with empty slots
    int player_turn = 1;
    int win = 0, draw = 0;

    printf("Welcome to Tic Tac Toe!\n");
    printf("You will be playing against the AI.\n");
    printf("You are X and the AI is O.\n");
    printf("The board is numbered like this:\n");
    printf("1 | 2 | 3\n");
    printf("---------\n");
    printf("4 | 5 | 6\n");
    printf("---------\n");
    printf("7 | 8 | 9\n");
    printf("\n");

    while(!win && !draw) {
        if(player_turn == 1) {
            // Player's turn
            int move = get_player_move(board);
            board[move-1] = 1;
            player_turn = -1;
        } else {
            // AI's turn
            printf("AI is thinking...\n");
            int move = get_ai_move(board);
            if(move == -1) {
                draw = 1;
            } else {
                board[move-1] = -1;
                player_turn = 1;
            }
        }

        // Print the current state of the board
        int i;
        for(i = 0; i < 9; i++) {
            if(board[i] == 1) {
                printf("X ");
            } else if(board[i] == -1) {
                printf("O ");
            } else {
                printf("- ");
            }
            if((i+1) % 3 == 0) {
                printf("\n");
            }
        }
        printf("\n");

        // Check if there is a winner
        if(check_win(board, 1)) {
            printf("You won! Congrats!\n");
            win = 1;
        } else if(check_win(board, -1)) {
            printf("AI won! Better luck next time!\n");
            win = 1;
        }
    }

    if(draw) {
        printf("It's a draw!\n");
    }

    return 0;
}