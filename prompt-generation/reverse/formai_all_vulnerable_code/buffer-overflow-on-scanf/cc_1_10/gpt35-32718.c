//FormAI DATASET v1.0 Category: Chess engine ; Style: accurate
#include <stdio.h>

// Board structure
char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
};

// Function to print the board
void print_board() {
    printf("\n   A B C D E F G H\n");
    printf(" +----------------+\n");
    for(int i=0; i<8; i++) {
        printf("%d| ", i+1);
        for(int j=0; j<8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf(" +----------------+\n");
}

int main() {
    // Print initial board
    print_board();

    // Loop through turns
    for(int turn=0; turn<100; turn++) {
        // Get input from user
        char move[5];
        printf("Enter move: ");
        scanf("%s", move);
        int start_row = move[1] - '1';
        int start_col = move[0] - 'a';
        int end_row = move[3] - '1';
        int end_col = move[2] - 'a';

        // Move piece
        board[end_row][end_col] = board[start_row][start_col];
        board[start_row][start_col] = ' ';

        // Print new board
        print_board();
    }
    return 0;
}