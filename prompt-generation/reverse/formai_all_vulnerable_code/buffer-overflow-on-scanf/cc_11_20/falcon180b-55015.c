//Falcon-180B DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPlayers;
    int playerScore[10];
    int computerScore = 0;
    int choice;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;

    srand(time(0));

    printf("Welcome to the Table Game!\n");

    printf("How many players? ");
    scanf("%d", &numPlayers);

    for(i=0; i<numPlayers; i++) {
        playerScore[i] = 0;
    }

    while(computerScore < 100 && numPlayers > 0) {
        printf("\n");
        printf("Player %d's turn.\n", numPlayers);
        printf("Choose a number between 1 and 6: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You rolled a 1!\n");
                break;
            case 2:
                printf("You rolled a 2!\n");
                break;
            case 3:
                printf("You rolled a 3!\n");
                break;
            case 4:
                printf("You rolled a 4!\n");
                break;
            case 5:
                printf("You rolled a 5!\n");
                break;
            case 6:
                printf("You rolled a 6!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6) {
            playerScore[numPlayers-1] += choice;
            printf("Your score is now %d.\n", playerScore[numPlayers-1]);

            if(playerScore[numPlayers-1] >= 100) {
                printf("Player %d wins!\n", numPlayers);
                return 0;
            }
        }

        computerScore += rand() % 6 + 1;
        printf("Computer's score is now %d.\n", computerScore);

        if(computerScore >= 100) {
            printf("Computer wins!\n");
            return 0;
        }

        numPlayers--;
    }

    return 0;
}