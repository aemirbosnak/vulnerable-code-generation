//FormAI DATASET v1.0 Category: Graph representation ; Style: multiplayer
#include <stdio.h>

int main()
{
    char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
    int current_player = 1, choice, row, col;

    do {
        // Display board
        printf("\n\n");
        printf("   %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
        printf("  ---+---+---\n");
        printf("   %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
        printf("  ---+---+---\n");
        printf("   %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);

        // Get player choice
        printf("\nPlayer %d, enter a choice: ", current_player);
        scanf("%d", &choice);

        // Map choice to row and column
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Update board
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("\nInvalid choice. Try again.\n");
        }
        else {
            board[row][col] = (current_player == 1) ? 'X' : 'O';
            current_player = (current_player == 1) ? 2 : 1;
        }

        // Check for winner
        if ((board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
            (board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
            (board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||
            (board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
            (board[0][1] == board[1][1] && board[1][1] == board[2][1]) ||
            (board[0][2] == board[1][2] && board[1][2] == board[2][2]) ||
            (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
            printf("\nPlayer %d wins!\n", current_player);
            return 0;
        }

        // Check for tie
        int i, j, count = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == 'X' || board[i][j] == 'O') {
                    count++;
                }
            }
        }
        if (count == 9) {
            printf("\nIt's a tie!\n");
            return 0;
        }
    } while (1);

    return 0;
}