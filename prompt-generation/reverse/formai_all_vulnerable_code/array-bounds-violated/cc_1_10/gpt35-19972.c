//FormAI DATASET v1.0 Category: Chess engine ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This is not your ordinary chess engine.
 * It is a unique one that can play chess while expressing its emotions!
 * Get ready for a surprise!
 */

int main() {
    char board[8][8] = { // initialize the chess board
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    
    printf("Hello, I am your chess engine! Let's play.\n");
    printf("I am feeling %s today!\n", rand() % 2 ? "happy" : "surprised");
    
    int turn = 1;
    while (1) {
        printf("Turn %d, it's my move.\n", turn);
        printf("Here's the current board:\n");
        for (int i = 0; i < 8; i++) { // print the current board
            for (int j = 0; j < 8; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        
        int from_x, from_y, to_x, to_y;
        printf("Enter your move (in format from_x from_y to_x to_y): ");
        scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);
        printf("Hmm, let me see...\n");
        
        if (board[from_x][from_y] == ' ') {
            printf("Oops, there's no piece there!\n");
        } else if (board[to_x][to_y] != ' ') {
            printf("Oh no, I captured your piece!\n");
        } else {
            board[to_x][to_y] = board[from_x][from_y];
            board[from_x][from_y] = ' ';
            
            printf("Ta-da! Here's the new board:\n");
            for (int i = 0; i < 8; i++) { // print the new board
                for (int j = 0; j < 8; j++) {
                    printf("%c ", board[i][j]);
                }
                printf("\n");
            }
        }
        
        printf("It's your turn now!\n");
        turn++;
    }
    
    return 0;
}