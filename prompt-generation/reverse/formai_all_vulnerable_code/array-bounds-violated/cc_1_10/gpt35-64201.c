//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int board[3][3]; //initialize the game board with 0 as default value

void print_board(){ //function to print current game board
    printf("\n\t   1   2   3 \n");
    printf("\t  -------------\n");
    for(int i=0;i<3;i++){
        printf("\t%d |",i+1);
        for(int j=0;j<3;j++){
            if(board[i][j]==0)
                printf("   |");
            else if(board[i][j]==1)
                printf(" X |");
            else
                printf(" O |");
        }
        printf("\n");
        printf("\t  -------------\n");
    }
}

int check_win(){ //function to check if someone has won the game
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=0)
            return board[i][0];
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=0)
            return board[0][i];
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=0)
        return board[0][0];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=0)
        return board[0][2];
    return 0;
}

int minimax(int depth, int is_max){ //function to implement minimax algorithm
    int score;
    int best_row;
    int best_col;
    int result=check_win();
    if(result!=0) //if someone has won the game
        return result*100; //return +100 if AI wins, -100 if player wins
    if(depth==9) //if all cells are filled and game has not ended
        return 0;
    if(is_max){ //if it's AI's turn to play, maximize its score
        int best_score=-10000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0){
                    board[i][j]=2; //put AI's symbol in an empty cell
                    score=minimax(depth+1,0); //calculate score for this move
                    board[i][j]=0; //undo the move
                    if(score>best_score){ //update best score and move if score is better
                        best_score=score;
                        best_row=i;
                        best_col=j;
                    }
                }
            }
        }
        if(depth==0){ //if it's the first move, return the best move
            board[best_row][best_col]=2;
            return 0;
        }
        return best_score;
    }
    else{ //if it's player's turn to play, minimize AI's score
        int best_score=10000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0){
                    board[i][j]=1; //put player's symbol in an empty cell
                    score=minimax(depth+1,1); //calculate score for this move
                    board[i][j]=0; //undo the move
                    if(score<best_score){ //update best score and move if score is better
                        best_score=score;
                    }
                }
            }
        }
        return best_score;
    }
}

int main(){
    int player_turn=rand()%2+1; //randomly select player or AI to play first
    int player_row,player_col;
    int winner=0;
    int count=0; //count how many cells are occupied
    while(winner==0 && count<9){ //while there is no winner and there are empty cells
        if(player_turn==1){ //if it's player's turn
            printf("\nPlayer's turn\n");
            printf("Enter row number and column number to put your symbol: ");
            scanf("%d %d",&player_row,&player_col);
            while(board[player_row-1][player_col-1]!=0){ //if the selected cell is already occupied
                printf("Invalid input! Enter row number and column number again: ");
                scanf("%d %d",&player_row,&player_col);
            }
            board[player_row-1][player_col-1]=1; //put player's symbol in the selected cell
            player_turn=2; //switch turn to AI
        }
        else{ //if it's AI's turn
            printf("\nAI's turn\n");
            minimax(0,1); //AI calculates the best move using minimax algorithm
            player_turn=1; //switch turn to player
        }
        count++;
        print_board();
        winner=check_win(); //check if someone has won the game
    }
    if(winner==1) //if player wins
        printf("\nPlayer wins!\n");
    else if(winner==2) //if AI wins
        printf("\nAI wins!\n");
    else //if there is a tie
        printf("\nIt's a tie!\n");
    return 0;
}