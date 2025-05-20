//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the current state of the board
void print_board(char board[]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

// Function to check if the game has been won
bool check_win(char board[], char player) {
    // Check horizontal
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i+1] == player && board[i+2] == player) {
            return true;
        }
    }

    // Check vertical
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i+3] == player && board[i+6] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }

    return false;
}

// Function to check if the game has ended in a draw
bool check_draw(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}

// Function to get the move of the AI player
int get_ai_move(char board[], char ai_player, char human_player) {
    // Check for winning move
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = ai_player;
            if (check_win(board, ai_player)) {
                board[i] = ' ';
                return i;
            }
            board[i] = ' ';
        }
    }

    // Check for blocking move
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = human_player;
            if (check_win(board, human_player)) {
                board[i] = ' ';
                return i;
            }
            board[i] = ' ';
        }
    }

    // Play center if available
    if (board[4] == ' ') {
        return 4;
    }

    // Play a corner if available
    for (int i = 0; i < 9; i += 2) {
        if (i == 4) {
            continue;
        }
        if (board[i] == ' ') {
            return i;
        }
    }

    // Play an edge if available
    for (int i = 1; i < 9; i += 2) {
        if (board[i] == ' ') {
            return i;
        }
    }

    // This should never happen
    return -1;
}

int main() {
    // Initialize the board
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    // Initialize players and turn
    char human_player = 'X';
    char ai_player = 'O';
    bool is_human_turn = true;

    printf("Welcome to Genius Tic Tac Toe!\n");
    printf("You will be playing against the AI.\n");
    printf("You are %c and the AI is %c.\n", human_player, ai_player);
    printf("The game board looks like this:\n");
    print_board(board);

    // Main game loop
    while (!check_win(board, human_player) && !check_win(board, ai_player) && !check_draw(board)) {
        if (is_human_turn) {
            // Human player's turn
            printf("Enter the position you want to play (1-9): ");
            int position = -1;
            scanf("%d", &position);
            position--;
            if (board[position] != ' ') {
                printf("Invalid move, try again.\n");
                continue;
            }
            board[position] = human_player;
        } else {
            // AI player's turn
            printf("The AI is thinking...\n");
            int ai_position = get_ai_move(board, ai_player, human_player);
            board[ai_position] = ai_player;
            printf("The AI played at position %d.\n", ai_position+1);
        }

        // Print the updated board
        print_board(board);

        // Switch turns
        is_human_turn = !is_human_turn;
    }

    // Print the result of the game
    if (check_win(board, human_player)) {
        printf("Congratulations, you won!\n");
    } else if (check_win(board, ai_player)) {
        printf("Sorry, the AI won.\n");
    } else {
        printf("It's a draw.\n");
    }

    return 0;
}