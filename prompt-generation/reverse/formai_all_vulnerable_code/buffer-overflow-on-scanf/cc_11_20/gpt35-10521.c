//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, j, n, num, flag;     // variables to be used
    char ch;
    srand(time(0));             // seeding random number generation

    printf("Welcome to the Bingo Simulator Game!\n");
    printf("This game requires at least 2 players.\n");

    do{
        printf("\nEnter the number of players: ");
        scanf("%d", &n);
    }while(n<2);
    
    int players[n][5];           // array to store the players' cards
  
    // Card generation for each player
    for(i=0; i<n; i++){
        printf("\nCard for Player %d:\n", i+1);
        for(j=0; j<5; j++){
            players[i][j] = (rand()%15)+1 + (j*15);
            printf("%d ", players[i][j]);
        }
        printf("\n");
    }

    do{
        flag = 0;           // checking if any player has won

        // Random number generation
        num = (rand()%75)+1;
        printf("\nCurrent number: %d\n", num);

        // Checking if the number is present in any player's card
        for(i=0; i<n; i++){
            for(j=0; j<5; j++){
                if(players[i][j] == num){
                    players[i][j] = 0;
                }
            }
            // Checking if the player has won
            if(players[i][0]==0 && players[i][1]==0 && players[i][2]==0 && players[i][3]==0 && players[i][4]==0){
                printf("\nPlayer %d has won!\n", i+1);
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            printf("\nNo player has won yet.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);
    }while(ch=='y' || ch=='Y');

    printf("\nThanks for playing the Bingo Simulator Game!\n");

    return 0;
}