//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10

int main(){
    int size,i,j,flag=0,count=0;
    int board[MAX_SIZE][MAX_SIZE];
    int choice;
    int player=1;
    int start_pos;
    int end_pos;
    int pos;
    int value;
    char play_again;
    srand(time(0));
    printf("Welcome to Memory Game\n");
    printf("Enter the board size (1-10): ");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            board[i][j]=0;
        }
    }
    for(i=0;i<size*size/2;i++){
        do{
            start_pos=rand()%size;
            end_pos=rand()%size;
        }while(board[start_pos][end_pos]!=0);
        board[start_pos][end_pos]=i+1;
        board[end_pos][start_pos]=i+1;
    }
    do{
        system("clear");
        printf("Player 1's Turn\n");
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                if(board[i][j]!=0){
                    printf("* ");
                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("Enter your choice: ");
        scanf("%d",&choice);
        pos=choice-1;
        start_pos=pos/size;
        end_pos=pos%size;
        if(board[start_pos][end_pos]!=0){
            if(board[start_pos][end_pos]==board[start_pos][end_pos+1]){
                count++;
                board[start_pos][end_pos]=0;
                board[start_pos][end_pos+1]=0;
            }else{
                board[start_pos][end_pos]=0;
            }
        }else{
            board[start_pos][end_pos]=-1;
        }
        if(count==size*size/2){
            printf("Player 1 wins!\n");
            break;
        }
        player=2;
        count=0;
    }while(1);
    return 0;
}