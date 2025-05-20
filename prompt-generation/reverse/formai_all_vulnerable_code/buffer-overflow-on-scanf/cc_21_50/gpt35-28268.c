//FormAI DATASET v1.0 Category: Checkers Game ; Style: romantic
#include<stdio.h>
int main(){
    int board[8][8]={{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{2,0,2,0,2,0,2,0},{0,2,0,2,0,2,0,2},{2,0,2,0,2,0,2,0}};  //initializing the board
    int choice;
    printf("Welcome to Checkers game!!!\n");
    printf("Do you want to start the game? (1 for yes and 0 for no) \n");
    scanf("%d",&choice);
    if(choice==0){  //player chose not to start the game
        printf("Thank you for visiting\n");
        return 0;
    }
    printf("Great! You chose to play the game!!!\n");
    printf("Here is the starting board\n");
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]==0) printf("- ");
            else if(board[i][j]==1) printf("R ");  // 'R' represents red checkers
            else printf("B ");   //'B' represents black checkers
        }
        printf("\n");
    }
    int turn=1,row1,col1,row2,col2;
    while(1){
        printf("\nEnter the coordinates of the checker you want to move (row column) \n");
        scanf("%d %d",&row1,&col1);
        printf("Enter the coordinates of the position you want to move your checker to (row column) \n");
        scanf("%d %d",&row2,&col2);
        if(board[row1][col1]==0){
            printf("Invalid move \n");
            continue;
        }
        if(turn==1 && board[row1][col1]!=1){
            printf("You can only move red checkers\n");
            continue;
        }
        if(turn==2 && board[row1][col1]!=2){
            printf("You can only move black checkers \n");
            continue;
        }
        if(row2<0 || row2>7 || col2<0 || col2>7){
            printf("Invalid move, out of the board \n");
            continue;
        }
        if(board[row2][col2]!=0){
            printf("Invalid move, the position is already taken \n");
            continue;
        }
        int rowdiff= row2-row1;
        int coldiff= col2-col1;
        if(rowdiff==turn || rowdiff==-turn){  // normal move for a checker is 1 direction
            if(coldiff==1 || coldiff==-1){   // side move
                board[row2][col2]=turn;
                board[row1][col1]=0;
                turn=3-turn; // 1 turns to 2 and vice versa
                printf("\n");
                for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        if(board[i][j]==0) printf("- ");
                        else if(board[i][j]==1) printf("R ");
                        else printf("B ");
                    }
                    printf("\n");
                }
                int red_checkers=0,black_checkers=0;
                for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        if(board[i][j]==1) red_checkers++;
                        if(board[i][j]==2) black_checkers++;
                    }
                }
                if(red_checkers==0){
                    printf("Black won the game!!!\n");
                    return 0;
                }
                if(black_checkers==0){
                    printf("Red won the game!!!\n");
                    return 0;
                }
            }
            else{
                printf("Invalid move \n");
                continue;
            }
        }
        else{   //when a checker jumps over another checker and removes it from board
            int rowjump, coljump;
            rowjump=row1+(row2-row1)/2;
            coljump=col1+(col2-col1)/2;
            if(board[rowjump][coljump]==0 || board[rowjump][coljump]==turn){
                printf("Invalid move, you can only jump over opponent's checkers \n");
                continue;
            }
            board[rowjump][coljump]=0;
            board[row2][col2]=turn;
            board[row1][col1]=0;
            turn=3-turn;
            printf("\n");
                for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        if(board[i][j]==0) printf("- ");
                        else if(board[i][j]==1) printf("R ");
                        else printf("B ");
                    }
                    printf("\n");
                }
            int red_checkers=0,black_checkers=0;
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(board[i][j]==1) red_checkers++;
                    if(board[i][j]==2) black_checkers++;
                }
            }
            if(red_checkers==0){
                    printf("Black won the game!!!\n");
                    return 0;
            }
            if(black_checkers==0){
                    printf("Red won the game!!!\n");
                    return 0;
            }
        }
        
    }    
    printf("Hope you enjoyed the game!!!\n");
    return 0;
}