//FormAI DATASET v1.0 Category: Memory Game ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int seconds){   //delay function for creating suspense
    int milli_seconds=1000*seconds;
    clock_t start_time=clock();
    while(clock()<start_time+milli_seconds);
}

int main(){
    int size;
    printf("Enter the size of the game board: ");
    scanf("%d",&size);
    int *gameBoard=(int*)malloc(size*size*sizeof(int)); //allocating dynamic memory to gameBoard
    int i,j,k;
    for(i=0;i<size*size;i+=2){    //filling up values at alternate positions
        gameBoard[i/2]=gameBoard[i/2+size*size/2]=i/2+1;
    }
    for(i=0;i<size*size;i++){   //randomly shuffling the values
        j=rand()%size*size;
        k=rand()%size*size;
        int temp=gameBoard[j];
        gameBoard[j]=gameBoard[k];
        gameBoard[k]=temp;
    }
    int moves=0,pair=0,prev=-1;
    while(pair<size*size/2){    //loop for playing the game
        system("clear");
        printf("\n\n\t\t Memory Game");
        printf("\n\t\t Moves: %d",moves);
        printf("\n\t\t Pairs Found : %d/%d",pair,size*size/2);
        printf("\n\n\t");
        for(i=0;i<size;i++){
            printf(" _____");
        }
        for(i=0;i<size;i++){
            printf("\n\t");
            for(j=0;j<size;j++){
                printf("|     ");
            }
            printf("|");
            printf("\n\t");
            for(j=0;j<size;j++){
                char c=(gameBoard[i*size+j]!=-1)?(gameBoard[i*size+j]>9)?gameBoard[i*size+j]/10+'0':' ':32;
                printf("|  %c%d ",c,gameBoard[i*size+j]);
            }
            printf("|  %d",i+1);
            printf("\n\t");
            for(j=0;j<size;j++){
                printf("|_____");
            }
        }
        int pos1,pos2;
        printf("\n\nEnter 2 positions (eg. 1 2 3 4): ");
        scanf("%d %d",&pos1,&pos2);
        pos1--;
        pos2--;
        if(pos1>=size||pos2>=size||pos1<0||pos2<0){
            printf("Invalid Input!");
            delay(1);
        }
        else if(gameBoard[pos1*size+pos2]!=-1){
            if(prev==-1){
                prev=gameBoard[pos1*size+pos2];
                gameBoard[pos1*size+pos2]=-1;
            }
            else if(prev==gameBoard[pos1*size+pos2]){
                pair++;
                moves++;
                printf("\nPair Found!");
                delay(1);
                prev=-1;
            }
            else{
                gameBoard[pos1*size+pos2]=-1;
                delay(1);
                system("clear");
                printf("\n\n\t\t Memory Game");
                printf("\n\t\t Moves: %d",++moves);
                printf("\n\t\t Pairs Found : %d/%d",pair,size*size/2);
                printf("\n\n\t");
                for(i=0;i<size;i++){
                    printf(" _____");
                }
                for(i=0;i<size;i++){
                    printf("\n\t");
                    for(j=0;j<size;j++){
                        if(gameBoard[i*size+j]==prev){
                            printf("|     ");
                        }
                        else{
                            printf("|_____");
                        }
                    }
                    printf("|");
                    printf("\n\t");
                    for(j=0;j<size;j++){
                        char c=(gameBoard[i*size+j]!=-1)?(gameBoard[i*size+j]>9)?gameBoard[i*size+j]/10+'0':' ':32;
                        printf("|  %c%d ",c,gameBoard[i*size+j]);
                    }
                    printf("|  %d",i+1);
                    printf("\n\t");
                    for(j=0;j<size;j++){
                        if(gameBoard[i*size+j]==prev){
                            printf("|_____");
                        }
                        else{
                            printf("|     ");
                        }
                    }
                }
                printf("\n\nNo Match found!");
                delay(2);
                gameBoard[pos1*size+pos2]=prev;
                gameBoard[(pos1=size/2)*(size)+pos2]=prev;
                prev=-1;
            }
        }
    }
    printf("\n\nCongratulations! You Won the Game");
    printf("\nTotal Moves: %d",moves);
    free(gameBoard);
    return 0;
}