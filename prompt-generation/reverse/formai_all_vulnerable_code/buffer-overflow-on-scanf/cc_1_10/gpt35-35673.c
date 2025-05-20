//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the tic tac toe board
void print_board(char* board) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

// Function to check if the game has ended
int check_end(char* board) {
    // Check if any row is completed by the same player
    if (board[0] == board[1] && board[1] == board[2])
        return 1;
    if (board[3] == board[4] && board[4] == board[5])
        return 1;
    if (board[6] == board[7] && board[7] == board[8])
        return 1;
    // Check if any column is completed by the same player
    if (board[0] == board[3] && board[3] == board[6])
        return 1;
    if (board[1] == board[4] && board[4] == board[7])
        return 1;
    if (board[2] == board[5] && board[5] == board[8])
        return 1;
    // Check if any diagonal is completed by the same player
    if (board[0] == board[4] && board[4] == board[8])
        return 1;
    if (board[2] == board[4] && board[4] == board[6])
        return 1;
    // Check if the board is full
    for (int i=0; i<9; i++) {
        if (board[i] == ' ')
            return 0;
    }
    return 2; // Game is tied
}

// Function to make a move
void make_move(char* board, int pos, char sym) {
    board[pos] = sym;
}

// Function to get the user's move
int user_move(char* board, char sym) {
    int pos;
    // Repeat until a valid move is given
    do {
        printf("Enter your move (0-8): ");
        scanf("%d", &pos);
    } while (pos < 0 || pos > 8 || board[pos] != ' ');
    make_move(board, pos, sym);
    return check_end(board);
}

// Function to get the AI's move (simple random move)
int ai_move_simple(char* board, char sym) {
    int pos;
    srand(time(NULL)); // Set random seed based on time
    do {
        pos = rand() % 9;
    } while (board[pos] != ' ');
    printf("AI chose position %d\n", pos);
    make_move(board, pos, sym);
    return check_end(board);
}

// Function to get the AI's move (smart moves)
int ai_move_smart(char* board, char sym, char opp_sym) {
    // Check for winning move
    for (int i=0; i<9; i++) {
        if (board[i] == ' ') {
            board[i] = sym;
            if (check_end(board) == 1) {
                printf("AI chose position %d\n", i);
                return 1;
            }
            board[i] = ' ';
        }
    }
    // Check for blocking move
    for (int i=0; i<9; i++) {
        if (board[i] == ' ') {
            board[i] = opp_sym;
            if (check_end(board) == 1) {
                board[i] = sym;
                printf("AI chose position %d\n", i);
                return 1;
            }
            board[i] = ' ';
        }
    }
    // Make random move
    return ai_move_simple(board, sym);
}

int main() {
    char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int turn = 0; // 0 for user turn, 1 for AI turn
    char user_sym, ai_sym;
    int result;

    // Get user symbol
    do {
        printf("Enter your symbol (X/O): ");
        scanf(" %c", &user_sym);
    } while (user_sym != 'X' && user_sym != 'O');
    ai_sym = (user_sym == 'X') ? 'O' : 'X';

    // Print starting board
    print_board(board);

    // Game loop
    while (1) {
        if (turn == 0) {
            result = user_move(board, user_sym);
        } else {
            result = ai_move_smart(board, ai_sym, user_sym);
        }
        // Display current board
        print_board(board);
        if (result != 0) {
            if (result == 1) {
                printf("You win!\n");
            } else if (result == 2) {
                printf("Tie game!\n");
            } else {
                printf("AI wins!\n");
            }
            break;
        }
        turn = (turn + 1) % 2; // Switch turns
    }

    return 0;
}