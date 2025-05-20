//FormAI DATASET v1.0 Category: Game ; Style: systematic
#include <stdio.h>

/* Function to print the game board */
void print_board(char board[3][3])
{
    printf("\n");
    printf("%c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---------\n");
    printf("%c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---------\n");
    printf("%c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

/* Function to check if player has won */
int check_win(char board[3][3], char player)
{
    /* Check rows */
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && 
           board[i][1] == player && 
           board[i][2] == player) {
            return 1;
        }
    }
    
    /* Check columns */
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == player && 
           board[1][i] == player && 
           board[2][i] == player) {
            return 1;
        }
    }
    
    /* Check diagonal 1 */
    if(board[0][0] == player && 
       board[1][1] == player && 
       board[2][2] == player) {
        return 1;
    }
    
    /* Check diagonal 2 */
    if(board[0][2] == player && 
       board[1][1] == player && 
       board[2][0] == player) {
        return 1;
    }
    
    /* Player has not won */
    return 0;
}

int main()
{
    char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
    char player1 = 'X';
    char player2 = 'O';
    char *current_player = &player1;
    int move_count = 0;
    
    /* Print initial board */
    print_board(board);
    
    /* Loop while game is not over */
    while(move_count < 9) {
        int row, col;
        
        /* Get current player's move */
        printf("Player %c, enter row (1,2,3): ", *current_player);
        scanf("%d", &row);
        printf("Player %c, enter column (1,2,3): ", *current_player);
        scanf("%d", &col);
        
        /* Update board with current player's move */
        if(board[row-1][col-1] != 'X' && board[row-1][col-1] != 'O') {
            board[row-1][col-1] = *current_player;
            move_count++;
        } else {
            printf("Invalid move!\n");
            continue;
        }
        
        /* Print updated board */
        print_board(board);
        
        /* Check if current player has won */
        if(check_win(board, *current_player)) {
            printf("Player %c has won the game!\n", *current_player);
            return 0;
        }
        
        /* Switch to other player */
        if(current_player == &player1) {
            current_player = &player2;
        } else {
            current_player = &player1;
        }
    }
    
    /* Game is a draw */
    printf("Game is a draw!\n");
    
    return 0;
}