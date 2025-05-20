//FormAI DATASET v1.0 Category: Table Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototype
void print_board(int board[][3]);
int check_win(int board[][3]);

int main()
{
    // seeding random number generator
    srand(time(NULL));
    
    // declaring variables
    int player1_score = 0, player2_score = 0, draw = 0;
    int play_again = 1;
    
    printf("Welcome to Love Tic Tac Toe!\n");
    
    while(play_again)
    {
        // initializing the board
        int board[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
        
        printf("Player 1 (X) - Enter your name: ");
        char player1_name[20];
        scanf("%s", player1_name);
        
        printf("Player 2 (O) - Enter your name: ");
        char player2_name[20];
        scanf("%s", player2_name);
        
        // declaring variables
        int player_turn = rand() % 2 + 1; // randomly selecting player turn
        int turn_count = 0; // to keep track of number of turns taken
        
        printf("\n%s (X)     vs     %s (O)\n\n", player1_name, player2_name);
        
        // game loop
        while(!check_win(board) && turn_count < 9)
        {
            // clearing screen
            system("clear");
            
            // printing board
            print_board(board);
            
            // getting player move
            int row, col;
            printf("\n%s (X), enter row (1-3): ", player_turn == 1 ? player1_name : player2_name);
            scanf("%d", &row);
            printf("%s (X), enter column (1-3): ", player_turn == 1 ? player1_name : player2_name);
            scanf("%d", &col);
            
            // validating move
            if(row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != 0)
            {
                printf("Invalid move! Please try again.\n");
                continue;
            }
            
            // updating board
            board[row-1][col-1] = player_turn;
            
            // updating turn count
            turn_count++;
            
            // changing turn
            player_turn = player_turn == 1 ? 2 : 1;
        }
        
        // clearing screen
        system("clear");
        
        // printing final board
        print_board(board);
        
        // checking game result
        if(check_win(board) == 1)
        {
            printf("\nCongratulations, %s (X)! You win!\n", player1_name);
            player1_score++;
        }
        else if(check_win(board) == 2)
        {
            printf("\nCongratulations, %s (O)! You win!\n", player2_name);
            player2_score++;
        }
        else
        {
            printf("\nIt's a draw!\n");
            draw++;
        }
        
        // displaying scores
        printf("\n%s (X) : %d\n", player1_name, player1_score);
        printf("%s (O) : %d\n", player2_name, player2_score);
        printf("Draw : %d\n", draw);
        
        // asking if players want to play again
        int play_again_input;
        printf("\nDo you want to play again? (1 for yes, 0 for no): ");
        scanf("%d", &play_again_input);
        play_again = play_again_input == 1 ? 1 : 0;
    }
    
    return 0;
}

// function to print the board
void print_board(int board[][3])
{
    printf("  1 2 3\n");
    for(int i=0; i<3; i++)
    {
        printf("%d", i+1);
        for(int j=0; j<3; j++)
        {
            if(board[i][j] == 1)
                printf(" X");
            else if(board[i][j] == 2)
                printf(" O");
            else
                printf(" -");
        }
        printf("\n");
    }
}

// function to check if any player has won
int check_win(int board[][3])
{
    // checking rows
    for(int i=0; i<3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0)
            return board[i][0];
    }
    
    // checking columns
    for(int i=0; i<3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0)
            return board[0][i];
    }
    
    // checking diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
        return board[0][0];
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != 0)
        return board[0][2];
    
    // no winner yet
    return 0;
}