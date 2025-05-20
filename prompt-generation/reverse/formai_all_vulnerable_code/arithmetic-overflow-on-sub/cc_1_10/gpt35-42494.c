//FormAI DATASET v1.0 Category: Chess engine ; Style: complex
#include <stdio.h>

// Initialize the board
char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// Get the input from the user
void get_input(int* x, int* y) {
    printf("Enter the coordinates of the piece to move (x,y): ");
    scanf("%d%d", x, y);
}

// Print the board
void print_board() {
    printf("\n   a b c d e f g h\n");
    printf("  +-----------------+\n");
    for(int i = 0; i < 8; i++) {
        printf("%d | ", i + 1);
        for(int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("| %d\n", i + 1);
    }
    printf("  +-----------------+\n");
    printf("   a b c d e f g h\n\n");
}

// Move the piece
void move_piece(int x1, int y1, int x2, int y2) {
    char temp = board[x1][y1];
    board[x1][y1] = ' ';
    board[x2][y2] = temp;
}

// Main function
int main() {
    int x1, y1, x2, y2;
    print_board();
    get_input(&x1, &y1);
    printf("Enter the coordinates of the square to move to (x,y): ");
    scanf("%d%d", &x2, &y2);
    move_piece(x1-1, y1-1, x2-1, y2-1);
    print_board();
    return 0;
}