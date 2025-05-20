//FormAI DATASET v1.0 Category: Chess engine ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

char board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    };

int is_valid_move(int i1, int j1, int i2, int j2)
{
    // Check if the move is valid
    char piece = board[i1][j1];
    if ((piece == 'P' && i1 - i2 == 1 && j1 == j2 && board[i2][j2] == ' ') ||
        (piece == 'p' && i2 - i1 == 1 && j1 == j2 && board[i2][j2] == ' ') ||
        (piece == 'R' && ((i1 == i2 && j1 != j2) || (i1 != i2 && j1 == j2))) ||
        (piece == 'r' && ((i1 == i2 && j1 != j2) || (i1 != i2 && j1 == j2))) ||
        (piece == 'N' && ((abs(i1 - i2) == 2 && abs(j1 - j2) == 1) || 
                          (abs(i1 - i2) == 1 && abs(j1 - j2) == 2))) ||
        (piece == 'n' && ((abs(i1 - i2) == 2 && abs(j1 - j2) == 1) || 
                          (abs(i1 - i2) == 1 && abs(j1 - j2) == 2))) ||
        (piece == 'B' && (abs(i1 - i2) == abs(j1 - j2))) ||
        (piece == 'b' && (abs(i1 - i2) == abs(j1 - j2))) ||
        (piece == 'Q' && ((i1 == i2 && j1 != j2) || 
                          (i1 != i2 && j1 == j2) || 
                          (abs(i1 - i2) == abs(j1 - j2)))) ||
        (piece == 'q' && ((i1 == i2 && j1 != j2) || 
                          (i1 != i2 && j1 == j2) || 
                          (abs(i1 - i2) == abs(j1 - j2))))) {
        return 1;
    }
    return 0;
}

void print_board()
{
    // Print the chessboard
    printf("   A B C D E F G H\n");
    for (int i = 0; i < 8; i++) {
        printf("%d  ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d", i + 1);
        printf("\n");
    }
    printf("   A B C D E F G H\n");
}

int main()
{
    int game_over = 0;
    int turn = 1; // 1 for white, 0 for black
    char move[4];
    int i1, j1, i2, j2;

    printf("Welcome to C Chess!\n");
    printf("Type 'help' for a list of commands.\n");

    while (!game_over) {
        print_board();
        if (turn == 1) {
            printf("White's turn.\n");
        } else {
            printf("Black's turn.\n");
        }
        printf("Enter your move: ");
        scanf("%s", move);

        if (strcmp(move, "help") == 0) {
            printf("Commands:\n");
            printf("help    - display this help\n");
            printf("quit    - end game\n");
            printf("EXAMPLE - make an example move\n");
            printf("a1a2    - move piece from a1 to a2\n");
            printf("Type your move and press enter.\n");
        } else if (strcmp(move, "quit") == 0) {
            game_over = 1;
        } else if (strcmp(move, "EXAMPLE") == 0) {
            printf("Making example move.\n");
            i1 = 6;
            j1 = 3;
            i2 = 4;
            j2 = 3;
        } else if (strlen(move) == 4) {
            // Convert from chess notation to array index
            j1 = move[0] - 'a';
            i1 = move[1] - '1';
            j2 = move[2] - 'a';
            i2 = move[3] - '1';
            if (is_valid_move(i1, j1, i2, j2)) {
                board[i2][j2] = board[i1][j1];
                board[i1][j1] = ' ';
                turn = !turn;
            } else {
                printf("Invalid move. Try again.\n");
            }
        } else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }
    printf("Thanks for playing C Chess!\n");

    return 0;
}