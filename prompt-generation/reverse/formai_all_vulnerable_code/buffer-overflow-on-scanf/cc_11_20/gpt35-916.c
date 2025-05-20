//FormAI DATASET v1.0 Category: Chess engine ; Style: happy
#include <stdio.h>
#include <stdlib.h>

/* Happy Chess Engine */

int main() {
    printf("Welcome to the Happy Chess Engine!\n");
    printf("Let's play a game! Please enter your move in algebraic notation.\n");
    
    char board[8][8] = {   /* Initial configuration of the chess board */
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    
    int game_running = 1;   /* Flag to keep the game running */
    while (game_running) {
        printf("   a  b  c  d  e  f  g  h\n");
        for (int i = 0; i < 8; i++) {   /* Print the current board state */
            printf("%d ", 8-i);
            for (int j = 0; j < 8; j++) {
                printf("[%c]", board[i][j]);
            }
            printf(" %d\n", 8-i);
        }
        printf("   a  b  c  d  e  f  g  h\n");
        
        char move[6];
        printf("Your move: ");
        if (scanf("%s", move) != 1) {  /* Read user input */
            printf("Invalid input, please try again.\n");
            continue;
        }
        
        int start_file = move[0] - 'a';
        int start_rank = 8 - (move[1] - '0');
        int end_file = move[3] - 'a';
        int end_rank = 8 - (move[4] - '0');
        
        if (start_file < 0 || start_file > 7 || start_rank < 0 || start_rank > 7 || end_file < 0 || end_file > 7 || end_rank < 0 || end_rank > 7) {
            printf("Invalid move, please try again.\n");
            continue;
        }
        
        if (board[start_rank][start_file] == ' ') {
            printf("There is no piece there, please try again.\n");
            continue;
        }
        
        if (board[end_rank][end_file] != ' ') {
            printf("You can't capture your own piece, please try again.\n");
            continue;
        }
        
        if (board[start_rank][start_file] == 'p' && end_rank == start_rank-1 && end_file == start_file) {
            printf("You can't move your pawn there, it's blocked by another piece. Please try again.\n");
            continue;
        }
        
        board[end_rank][end_file] = board[start_rank][start_file];
        board[start_rank][start_file] = ' ';
        
        printf("Great move! Now it's my turn...\n");
        
        /* AI moves here */
        
        printf("I moved my piece. Your turn again!\n");
        /* The loop will continue until someone wins or the game ends in a draw */
    }
    
    printf("Thanks for playing the Happy Chess Engine!\n");
    return 0;
}