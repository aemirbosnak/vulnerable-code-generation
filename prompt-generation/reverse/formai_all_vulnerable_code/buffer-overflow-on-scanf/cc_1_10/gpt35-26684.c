//FormAI DATASET v1.0 Category: Table Game ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print_board(char board[3][3]){
    printf("\n");
    for(int i=0;i<3;i++){
        printf("  %c | %c | %c ",board[i][0],board[i][1],board[i][2]);
        if(i!=2){
            printf("\n ---|---|---\n");
        }
    }
    printf("\n");
}

int check_win(char board[3][3]){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return 1;
        }
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return 1;
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        return 1;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        return 1;
    }
    return 0;
}

int main(){
    char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int turn=0, row, col, valid_move, result;
    char user_input;
    srand(time(NULL)); //initialize random number generator

    while(turn<9){
        print_board(board);
        valid_move=0;
        while(valid_move==0){
            printf("Enter a row (0-2) and col (0-2) separated by a space: ");
            scanf("%d%d",&row,&col);
            if(row<0 || row>2 || col<0 || col>2){
                printf("Invalid row and col values! Try again.\n");
            }
            else if(board[row][col]!=' '){
                printf("Board position already taken! Try again.\n");
            }
            else{
                board[row][col]='X';
                valid_move=1;
            }
        }
        turn++;
        result=check_win(board);
        if(result==1){
            print_board(board);
            printf("Congratulations! You win.");
            return 0;
        }
        if(turn==9){
            print_board(board);
            printf("Game over! It's a tie.");
            return 0;
        }

        printf("Computer's turn.\n");
        valid_move=0;
        while(valid_move==0){
            row=rand()%3;
            col=rand()%3;
            if(board[row][col]==' '){
                board[row][col]='O';
                valid_move=1;
            }
        }
        turn++;
        result=check_win(board);
        if(result==1){
            print_board(board);
            printf("Sorry! You lose.");
            return 0;
        }
    }
    return 0;
}