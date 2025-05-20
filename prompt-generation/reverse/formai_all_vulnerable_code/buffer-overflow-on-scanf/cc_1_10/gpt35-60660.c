//FormAI DATASET v1.0 Category: Poker Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int randomNumber(int min, int max){
    return rand() % (max + 1 - min) + min;
}

// Function to print a card given a number between 1 and 52
void printCard(int card){
    char faceValue;
    char suit;

    if(card % 13 == 0 || card % 13 == 11 || card % 13 == 12){
        faceValue = 'A' + card % 13 - 1;
    } else {
        faceValue = '2' + card % 13 - 2;
    }

    switch(card / 13){
        case 0:
            suit = 'S';
            break;
        case 1:
            suit = 'H';
            break;
        case 2:
            suit = 'D';
            break;
        case 3:
            suit = 'C';
            break;
        default:
            suit = '-';
    }

    printf("%c%c ", faceValue, suit);
}

int main(){

    int numPlayers = 0;
    int numCards = 0;
    int *deck = NULL;
    int **playerCards = NULL;

    printf("Welcome to the C Poker Game!\n");

    printf("How many players will be playing? ");
    scanf("%d", &numPlayers);

    printf("How many cards will each player receive? ");
    scanf("%d", &numCards);

    deck = (int*) malloc(sizeof(int) * 52);
    playerCards = (int**) malloc(sizeof(int*) * numPlayers);

    // Initialize the deck of cards
    for(int i = 0; i < 52; i++){
        deck[i] = i;
    }

    // Shuffle the deck using the Fisher-Yates algorithm
    srand((unsigned) time(NULL));

    for(int i = 51; i >= 1; i--){
        int j = randomNumber(0, i);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Initialize the playerCards array and deal the cards to each player
    for(int i = 0; i < numPlayers; i++){
        playerCards[i] = (int*) malloc(sizeof(int) * numCards);
        for(int j = 0; j < numCards; j++){
            playerCards[i][j] = deck[i * numCards + j];
        }
    }

    // Print out the cards that each player has been dealt
    for(int i = 0; i < numPlayers; i++){
        printf("Player %d has been dealt the following cards: ", i + 1);
        for(int j = 0; j < numCards; j++){
            printCard(playerCards[i][j]);
        }
        printf("\n");
    }

    // Clean up and exit the program
    free(deck);
    for(int i = 0; i < numPlayers; i++){
        free(playerCards[i]);
    }
    free(playerCards);

    return 0;
}