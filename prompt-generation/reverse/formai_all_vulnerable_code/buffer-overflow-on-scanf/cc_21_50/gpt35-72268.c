//FormAI DATASET v1.0 Category: Poker Game ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int playerCards[2], dealerCards[2], playerScore = 0, dealerScore = 0, i, j, x;
    char cards[13][3] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    char suits[4][9] = {"Hearts","Diamonds","Clubs","Spades"};
    srand(time(0));
    printf("********** Welcome to the Poker Table **********\n");
    printf("\nYou are being dealt your cards...\n\n");
    for(i = 0; i < 2; i++){
        playerCards[i] = rand()%13;
    }
    for(j = 0; j < 2; j++){
        dealerCards[j] = rand()%13;
    }
    printf("Your Cards:\n");
    for(i = 0; i < 2; i++){
        printf("%s of %s\n",cards[playerCards[i]],suits[rand()%4]);
        if(playerCards[i] >= 9 && playerCards[i] != 12){
            playerScore += 10;
        }
        else if(playerCards[i] == 12){
            playerScore += 11;
        }
        else{
            playerScore += playerCards[i]+2;
        }
        if(playerScore > 21 && playerCards[i] == 12){
            playerScore -= 10;
        }
    }
    printf("\nDealer's cards:\n%s of %s\n?\n",cards[dealerCards[0]],suits[rand()%4]);
    while(dealerScore < 17){
        x = rand()%13;
        if(x >= 9 && x != 12){
            dealerScore += 10;
        }
        else if(x == 12){
            dealerScore += 11;
        }
        else{
            dealerScore += x+2;
        }
        if(dealerScore > 21 && x == 12){
            dealerScore -= 10;
        }
        if(dealerScore > 21){
            printf("\nDealer's score: %d\n",dealerScore);
            printf("\nDealer busts! You win!\n");
            exit(0);
        }
    }
    printf("\nYour current score: %d\n",playerScore);
    printf("\nWould you like to hit or stand? (h/s)\n");
    char choice;
    scanf(" %c",&choice);
    while(choice != 's'){
        if(choice == 'h'){
            x = rand()%13;
            printf("\nCard dealt: %s of %s\n",cards[x],suits[rand()%4]);
            if(x >= 9 && x != 12){
                playerScore += 10;
            }
            else if(x == 12){
                playerScore += 11;
            }
            else{
                playerScore += x+2;
            }
            if(playerScore > 21 && x == 12){
                playerScore -= 10;
            }
            if(playerScore > 21){
                printf("\nYour current score: %d\n",playerScore);
                printf("\nYou bust! Dealer wins!\n");
                exit(0);
            }
            printf("\nYour current score: %d\n",playerScore);
            printf("\nWould you like to hit or stand? (h/s)\n");
            scanf(" %c",&choice);
        }
        else{
            printf("\nInvalid choice! Try again.\n");
            printf("\nWould you like to hit or stand? (h/s)\n");
            scanf(" %c",&choice);
        }
    }
    printf("\nDealer's cards:\n");
    for(j = 0; j < 2; j++){
        printf("%s of %s\n",cards[dealerCards[j]],suits[rand()%4]);
        if(dealerCards[j] >= 9 && dealerCards[j] != 12){
            dealerScore += 10;
        }
        else if(dealerCards[j] == 12){
            dealerScore += 11;
        }
        else{
            dealerScore += dealerCards[j]+2;
        }
        if(dealerScore > 21 && dealerCards[j] == 12){
            dealerScore -= 10;
        }
    }
    if(dealerScore > 21){
        printf("\nDealer's score: %d\n",dealerScore);
        printf("\nDealer busts! You win!\n");
        exit(0);
    }
    printf("\nDealer's score: %d\n",dealerScore);
    while(dealerScore < 17){
        x = rand()%13;
        if(x >= 9 && x != 12){
            dealerScore += 10;
        }
        else if(x == 12){
            dealerScore += 11;
        }
        else{
            dealerScore += x+2;
        }
        if(dealerScore > 21 && x == 12){
            dealerScore -= 10;
        }
        printf("\nDealer's cards:\n%s of %s\n",cards[dealerCards[0]],suits[rand()%4]);
        for(j = 1; j < 2; j++){
            printf("%s of %s\n",cards[dealerCards[j]],suits[rand()%4]);
            if(dealerCards[j] >= 9 && dealerCards[j] != 12){
                dealerScore += 10;
            }
            else if(dealerCards[j] == 12){
                dealerScore += 11;
            }
            else{
                dealerScore += dealerCards[j]+2;
            }
            if(dealerScore > 21 && dealerCards[j] == 12){
                dealerScore -= 10;
            }
        }
    }
    printf("\nDealer's score: %d\n",dealerScore);
    if(dealerScore > 21){
        printf("\nDealer busts! You win!\n");
    }
    else if(playerScore > dealerScore){
        printf("\nYou win!\n");
    }
    else if(playerScore < dealerScore){
        printf("\nDealer wins!\n");
    }
    else{
        printf("\nIt's a tie!\n");
    }
    printf("\n********** Thanks for playing! **********\n");
    return 0;
}