//FormAI DATASET v1.0 Category: Memory Game ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 4
#define COL 4

char board[ROW][COL] = {{'A', 'B', 'C', 'D'},
                        {'E', 'F', 'G', 'H'},
                        {'I', 'J', 'K', 'L'},
                        {'M', 'N', 'O', 'P'}};

char answer_board[ROW][COL] = {{'0', '0', '0', '0'},
                               {'0', '0', '0', '0'},
                               {'0', '0', '0', '0'},
                               {'0', '0', '0', '0'}};

//Function to print the board
void print_board()
{
    printf("   1 2 3 4\n");
    printf("  ________\n");
    for(int i=0;i<ROW;++i)
    {
        printf("%c ", 'A' + i);
        for(int j=0;j<COL;++j)
        {
            printf("|%c", answer_board[i][j]);
        }
        printf("|\n");
        printf("  ________\n");
    }
}

//Function to update the answer board
void update_answer_board(int row1, int col1, int row2, int col2)
{
    answer_board[row1][col1] = board[row1][col1];
    answer_board[row2][col2] = board[row2][col2];
}

int main()
{
    srand(time(NULL)); //Seed the random number generator
    //Randomly shuffle the board
    for(int i=ROW-1;i>0;--i)
    {
        for(int j=COL-1;j>0;--j)
        {
            int random_row = rand() % (i+1);
            int random_col = rand() % (j+1);
            
            //Swap the contents of the two locations
            char temp = board[i][j];
            board[i][j] = board[random_row][random_col];
            board[random_row][random_col] = temp;
        }
    }
    
    print_board();
    
    int r1, c1, r2, c2;
    do
    {
        printf("Enter the location of first card: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter the location of second card: ");
        scanf("%d %d", &r2, &c2);
        
        //Check if the locations entered are valid
        if(r1<0 || r1>=ROW || c1<0 || c1>=COL || r2<0 || r2>=ROW || c2<0 || c2>=COL)
        {
            printf("Invalid location. Please try again.\n");
            continue;
        }
        
        //Check if the two cards selected match
        if(board[r1][c1] == board[r2][c2])
        {
            printf("\nYou found a matching pair!\n\n");
            update_answer_board(r1, c1, r2, c2);
        }
        else
        {
            printf("\nSorry, the cards do not match.\n\n");
        }
        
        print_board();
    }while(board[r1][c1] != board[r2][c2] || answer_board[r1][c1] == '0' || answer_board[r2][c2] == '0');
    
    printf("Congratulations, you won the game!\n");
    
    return 0;
}