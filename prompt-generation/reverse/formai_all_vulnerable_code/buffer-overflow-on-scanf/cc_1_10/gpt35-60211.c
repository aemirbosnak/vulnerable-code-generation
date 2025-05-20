//FormAI DATASET v1.0 Category: Memory Game ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to shuffle the cards
void shuffle(int arr[], int n){
    srand(time(NULL));
    for(int i=n-1; i>=0; i--){
        int j = rand()%(i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main(){
    int cards[12] = {1,1,2,2,3,3,4,4,5,5,6,6}; //12 cards with 6 distinct numbers
    int guessedCards[12] = {0}; //to keep track of which cards are already guessed
    int pairsFound = 0; //to keep track of number of pairs found
    int firstCardIndex, secondCardIndex;
    shuffle(cards, 12); //shuffle the cards before starting the game
    
    //the game loop
    while(pairsFound < 6){
        printf("\n");
        //print the current state of the game
        for(int i=0; i<12; i++){
            if(guessedCards[i]){
                printf("%3d", cards[i]); //if the card is already guessed, print its value
            }else{
                printf("%3d", i+1); //if the card is not guessed, print its index
            }
        }
        printf("\nChoose two cards to flip (1-12): ");
        scanf("%d %d", &firstCardIndex, &secondCardIndex); //take input from user
        
        //check if the indices are valid
        if(firstCardIndex<1 || firstCardIndex>12 || secondCardIndex<1 || secondCardIndex>12){
            printf("Invalid indices, try again!\n");
            continue;
        }
        
        //check if the cards are already guessed
        if(guessedCards[firstCardIndex-1] || guessedCards[secondCardIndex-1]){
            printf("One or both cards are already guessed, try again!\n");
            continue;
        }
        
        //check if the cards are a pair or not
        if(cards[firstCardIndex-1] == cards[secondCardIndex-1]){
            printf("\n************ You found a pair! ************\n");
            guessedCards[firstCardIndex-1] = 1;
            guessedCards[secondCardIndex-1] = 1;
            pairsFound++;
        }else{
            printf("\nOops! The cards are not a pair. Try again.\n");
        }
    }
    
    printf("\n************ Congratulations! You won the game! ************\n");
    
    return 0;
}