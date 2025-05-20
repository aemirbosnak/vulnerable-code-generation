//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int numberOfPlayers, boardSize, turn, winner, flag=0;
    printf("Welcome to the game of Bingo in Verona!\n");
    printf("How many players are playing today?\n");
    scanf("%d", &numberOfPlayers);
    printf("What size should the board be? (e.g. enter 5 for a 5x5 board)\n");
    scanf("%d", &boardSize);
    int boards[numberOfPlayers][boardSize][boardSize], numbers[boardSize*boardSize];
    for(int i=0; i<numberOfPlayers; i++){
        for(int j=0; j<boardSize; j++){
            for(int k=0; k<boardSize; k++){
                boards[i][j][k] = -1;
            }
        }
    }
    for(int i=0; i<boardSize*boardSize; i++){
        numbers[i] = i+1;
    }
    for(int i=0; i<boardSize*boardSize; i++){
        int temp = numbers[i];
        int randomIndex = rand() % (boardSize*boardSize);
        numbers[i] = numbers[randomIndex];
        numbers[randomIndex] = temp;
    }
    printf("Alright, let's begin the game!\n");
    turn = 0;
    while(winner == -1){
        printf("It's player %d's turn\n", turn+1);
        printf("Here is your board:\n");
        for(int i=0; i<boardSize; i++){
            for(int j=0; j<boardSize; j++){
                printf("%d  ", boards[turn][i][j]);
            }
            printf("\n");
        }
        printf("Press enter to draw a number\n");
        getchar();
        printf("The number is: %d\n", numbers[flag]);
        for(int i=0; i<numberOfPlayers; i++){
            for(int j=0; j<boardSize; j++){
                for(int k=0; k<boardSize; k++){
                    if(boards[i][j][k] == numbers[flag]){
                        boards[i][j][k] = -1;
                    }
                }
            }
        }
        flag++;
        turn++;
        if(turn == numberOfPlayers){
            turn = 0;
        }
        winner = -2;
        for(int i=0; i<numberOfPlayers; i++){
            int count = 0;
            for(int j=0; j<boardSize; j++){
                for(int k=0; k<boardSize; k++){
                    if(boards[i][j][k] == -1){
                        count++;
                    }
                }
                if(count == boardSize){
                    printf("Player %d wins! Congratulations!\n", i+1);
                    winner = i;
                    break;
                }
            }
            if(winner != -2){
                break;
            }
        }
    }
    return 0;
}