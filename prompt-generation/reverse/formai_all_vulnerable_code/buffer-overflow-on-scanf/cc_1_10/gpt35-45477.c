//FormAI DATASET v1.0 Category: Poker Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A function to generate a random card value between 2 and 14 (Ace)
int generateCardValue(){
    return rand() % 13 + 2;
}

// A function to generate a random card suit (S, C, H, D)
char generateCardSuit(){
    int num = rand() % 4;
    if(num == 0) return 'S';
    if(num == 1) return 'C';
    if(num == 2) return 'H';
    return 'D';
}

// A function to print the name of the card value (2-10, Jack, Queen, King, Ace), given its value
void printCardValue(int value){
    switch(value){
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
        case 4:
            printf("4");
            break;
        case 5:
            printf("5");
            break;
        case 6:
            printf("6");
            break;
        case 7:
            printf("7");
            break;
        case 8:
            printf("8");
            break;
        case 9:
            printf("9");
            break;
        case 10:
            printf("10");
            break;
        case 11:
            printf("Jack");
            break;
        case 12:
            printf("Queen");
            break;
        case 13:
            printf("King");
            break;
        case 14:
            printf("Ace");
            break;
    }
}

// A function to print a card (e.g. "Jack of Hearts")
void printCard(int value, char suit){
    printCardValue(value);
    printf(" of %c\n", suit);
}

// A function to determine the winner of a hand
int determineWinner(int* playerHand, int* computerHand){
    int playerScore = 0;
    for(int i=0; i<5; i++){
        playerScore += playerHand[i];
    }

    int computerScore = 0;
    for(int i=0; i<5; i++){
        computerScore += computerHand[i];
    }

    if(playerScore > computerScore) return 1;
    if(computerScore > playerScore) return 2;
    return 0;
}

// The main function
int main(){
    srand(time(NULL)); // Seed the random number generator with the current time
    
    printf("Welcome to the Poker Game!\n");
    
    int playerHand[5];
    int computerHand[5];

    // Deal the cards
    for(int i=0; i<5; i++){
        playerHand[i] = generateCardValue();
        computerHand[i] = generateCardValue();
    }

    // Print out the player's hand
    printf("Your hand:\n");
    for(int i=0; i<5; i++){
        printCard(playerHand[i], generateCardSuit());
    }

    // Ask the player if they want to switch any cards
    int numSwitches = 0;
    while(numSwitches < 3){
        printf("Do you want to switch any cards? (y/n)\n");
        char response;
        scanf(" %c", &response);
        if(response == 'n') break;

        printf("Enter the index of the card you want to switch (1-5):\n");
        int index;
        scanf("%d", &index);

        // Make sure the input is valid
        if(index < 1 || index > 5){
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Switch the card
        playerHand[index-1] = generateCardValue();
        numSwitches++;
    }

    // Print out the player's final hand
    printf("Your final hand:\n");
    for(int i=0; i<5; i++){
        printCard(playerHand[i], generateCardSuit());
    }

    // Print out the computer's hand
    printf("Computer's hand:\n");
    for(int i=0; i<5; i++){
        printCard(computerHand[i], generateCardSuit());
    }

    // Determine the winner and print the result
    int winner = determineWinner(playerHand, computerHand);
    if(winner == 1){
        printf("Congratulations! You win!\n");
    } else if(winner == 2) {
        printf("Sorry, you lose. Better luck next time.\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}