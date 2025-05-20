//FormAI DATASET v1.0 Category: Table Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to check if the game is over */
int game_over(int board[10][10], int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(board[i][j] == 0) return 0;
        }
    }
    return 1;
}

/* Function to print the board */
void print_board(int board[10][10], int n) {
    int i, j;
    printf("\n");
    for(i=0; i<n; i++) {
        printf("\t");
        for(j=0; j<n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j, r, c, player1 = 0, player2 = 0, turn = 1;
    printf("Enter the size of the board (minimum 3) : ");
    scanf("%d", &n);
    int board[n][n];
    srand(time(NULL));
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            board[i][j] = rand()%9 + 1; /* Fill each cell with a random number between 1 and 9 */
        }
    }
    /* Game loop */
    while(!game_over(board, n)) {
        printf("Player %d's turn :\n", turn);
        print_board(board, n);
        printf("Enter the cell position (row column) : ");
        scanf("%d%d", &r, &c);
        while(r<0 || r>=n || c<0 || c>=n || board[r][c]==0) { /* Check if the cell is valid and empty */
            printf("Invalid cell position, please enter again : ");
            scanf("%d%d", &r, &c);
        }
        if(turn == 1) player1 += board[r][c];
        else player2 += board[r][c];
        board[r][c] = 0; /* Mark the cell as empty */
        turn = turn%2 + 1; /* Switch turns */
    }
    printf("Game over!\n");
    printf("Player 1 score : %d\n", player1);
    printf("Player 2 score : %d\n", player2);
    if(player1 > player2) printf("Player 1 wins!\n");
    else if(player2 > player1) printf("Player 2 wins!\n");
    else printf("It's a tie!\n");
    return 0;
}