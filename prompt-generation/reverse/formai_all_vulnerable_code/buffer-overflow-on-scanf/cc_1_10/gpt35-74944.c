//FormAI DATASET v1.0 Category: Poker Game ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to return a random integer between given range
int randRange(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// function to initialize the deck of cards
void initializeDeck(int deck[]){
    int i, card, suit;
    for(i=0;i<52;i++){
        card = i % 13;
        suit = i / 13;
        deck[i] = (suit<<4) | (card+1);
    }
}

// function to shuffle the deck of cards
void shuffleDeck(int deck[]){
    int i, temp, rnd;
    for(i=0;i<52;i++){
        rnd = randRange(i, 51);
        temp = deck[i];
        deck[i] = deck[rnd];
        deck[rnd] = temp;
    }
}

// function to print the card value and suit
void printCard(int card){
    char cardValue, suit;
    switch((card>>4)&0x3){
        case 0: suit = 'C'; break;
        case 1: suit = 'D'; break;
        case 2: suit = 'H'; break;
        case 3: suit = 'S'; break;
    }

    switch(card&0xf){
        case 1: cardValue = 'A'; break;
        case 10: cardValue = 'T'; break;
        case 11: cardValue = 'J'; break;
        case 12: cardValue = 'Q'; break;
        case 13: cardValue = 'K'; break;
        default: cardValue = card&0xf+'0'; break;
    }

    printf("%c%c ", cardValue, suit);
}

// function to deal cards to players
void dealCards(int deck[], int playerCards[], int playerCount, int cardsPerPlayer){
    int i, j, cardIndex = 0;
    for(i=0;i<cardsPerPlayer;i++){
        for(j=0;j<playerCount;j++){
            playerCards[j*cardsPerPlayer+i] = deck[cardIndex++];
        }
    }
}

// function to calculate score for a hand
int calculateScore(int hand[], int handSize){
    int i, total=0, aces=0;
    for(i=0;i<handSize;i++){
        if(hand[i]&0xf == 1){
            aces++;
            total += 11;
        }else if(hand[i]&0xf > 9){
            total += 10;
        }else{
            total += hand[i]&0xf;
        }
    }
    while(total > 21 && aces > 0){
        total -= 10;
        aces--;
    }
    return total;
}

int main(){
    int deck[52], playerCount, i, j, k, score[5], maxScore=0, winner[5];
    int playerCards[20];
    srand(time(NULL));

    printf("Welcome to the Poker Game!\n\n");
    printf("Enter number of players (max 5): ");
    scanf("%d", &playerCount);

    if(playerCount < 2 || playerCount > 5){
        printf("Invalid number of players!\n");
        return 1;
    }

    initializeDeck(deck);
    shuffleDeck(deck);

    printf("\nCards dealt:\n\n");
    dealCards(deck, playerCards, playerCount, 2);

    for(i=0;i<playerCount;i++){
        printf("Player %d: ", i+1);
        printCard(playerCards[i*2]);
        printCard(playerCards[i*2+1]);
        printf("\n");
    }

    for(i=0;i<playerCount;i++){
        score[i] = calculateScore(&playerCards[i*2], 2);
        printf("Player %d score: %d\n", i+1, score[i]);
    }

    for(j=0;j<3;j++){
        printf("\nFlop: ");
        for(i=0;i<3;i++){
            printCard(deck[2+i+j*3]);
        }

        for(i=0;i<playerCount;i++){
            printCard(playerCards[i*2+j+2]);
        }

        printf("\n");

        for(i=0;i<playerCount;i++){
            score[i] = calculateScore(&playerCards[i*2], j+3);
            printf("Player %d score: %d\n", i+1, score[i]);
        }

        for(i=0;i<playerCount;i++){
            if(score[i] > maxScore && score[i] <= 21){
                maxScore = score[i];
                winner[0] = i+1;
                k = 1;
            }else if(score[i] == maxScore && score[i] <= 21){
                winner[k++] = i+1;
            }
        }
        printf("Winner(s) after flop: ");
        for(i=0;i<k;i++){
            printf("Player %d ", winner[i]);
        }
        printf("\n");
    }

    printf("\nFinal winner(s): ");
    for(i=0;i<k;i++){
            printf("Player %d ", winner[i]);
    }
    printf("\n");

    return 0;
}