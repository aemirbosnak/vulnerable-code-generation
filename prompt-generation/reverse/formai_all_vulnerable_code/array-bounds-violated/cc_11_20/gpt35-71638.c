//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int check_win(char board[]);
int minimax(char board[], int depth, int isMaximizing);
void display_board(char board[]);

int main() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int choice, turn = 1, result, valid_move;
    
    printf("Welcome to Tic Tac Toe AI!\n");
    printf("The AI algorithm is ready to beat you!\n");

    while(turn <= 9) {
        if(turn%2 == 1) {
            // Player's turn
            do {
                printf("Enter your choice (1-9): ");
                scanf("%d", &choice);
                if(board[choice-1] == ' ') {
                    board[choice-1] = 'X';
                    valid_move = 1;
                } else {
                    printf("Invalid move! Try again.\n");
                    valid_move = 0;
                }
            } while(valid_move == 0);
        } else {
            // AI's turn
            printf("AI is making a move...\n");
            choice = minimax(board, 0, 1);
            board[choice] = 'O';
        }
        
        display_board(board);
        result = check_win(board);

        if(result == 1) {
            printf("You won the game!\n");
            break;
        } else if(result == -1) {
            printf("AI won the game!\n");
            break;
        } else if(turn == 9) {
            printf("The game ended in a draw!\n");
            break;
        }

        turn++;
    }

    printf("Thanks for playing!\n");
    return 0;
}

int check_win(char board[]) {
    int i, j;
    for(i = 0; i < 9; i += 3) {
        if(board[i] == 'X' && board[i+1] == 'X' && board[i+2] == 'X')
            return 1;
        if(board[i] == 'O' && board[i+1] == 'O' && board[i+2] == 'O')
            return -1;
    }
    for(i = 0; i < 3; i++) {
        if(board[i] == 'X' && board[i+3] == 'X' && board[i+6] == 'X')
            return 1;
        if(board[i] == 'O' && board[i+3] == 'O' && board[i+6] == 'O')
            return -1;
    }
    if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
        return 1;
    if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
        return -1;
    if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
        return 1;
    if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
        return -1;
    return 0;
}

int minimax(char board[], int depth, int isMaximizing) {
    int i, score, best_score, best_move;

    if(check_win(board)) {
        if(check_win(board) == 1)
            return -10 + depth;
        else
            return 10 - depth;
    }
    if(depth == 4)  // Limiting the depth of the algorithm
        return 0;

    if(isMaximizing) {
        best_score = -10000;
        for(i = 0; i < 9; i++) {
            if(board[i] == ' ') {
                board[i] = 'O';
                score = minimax(board, depth+1, 0);
                board[i] = ' ';               
                if(score > best_score) {
                    best_score = score;
                    best_move = i;
                }
            }
        }
    } else {
        best_score = 10000;
        for(i = 0; i < 9; i++) {
            if(board[i] == ' ') {
                board[i] = 'X';
                score = minimax(board, depth+1, 1);
                board[i] = ' ';
                if(score < best_score) {
                    best_score = score;
                    best_move = i;
                }
            }
        }
    }

    if(depth == 0)
        return best_move;
    else
        return best_score;
}

void display_board(char board[]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}