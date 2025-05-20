//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the memory cards
void shuffle(int *arr, int n){
    // Use a random seed to shuffle the array everytime the program runs
    srand(time(NULL));
    for(int i = n-1; i > 0; i--){
        int j = rand()%(i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to display the memory cards
void display(int *arr, int n){
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    printf("\nWelcome to the Memory Game, my love!\n");

    // Memory cards with romantic words
    int cards[16] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};

    // Shuffle the cards
    shuffle(cards, 16);

    // Display the cards face down
    printf("\nHere are your cards, face down...\n");
    display(cards, 16);

    // Player's turn
    int choice1, choice2;
    printf("\nMy darling, please enter the numbers of two cards to flip them over:\n");
    scanf("%d %d", &choice1, &choice2);

    // Flip the chosen cards and display the updated deck
    cards[choice1-1] = cards[choice1-1] * -1;
    cards[choice2-1] = cards[choice2-1] * -1;
    printf("\nHere are your cards, my love...\n");
    display(cards, 16);

    // Check if the chosen cards match
    if(cards[choice1-1] == cards[choice2-1]){
        printf("\nMy dearest, those cards match! How clever you are!\n");
    } else {
        printf("\nOh no, my precious, those cards do not match. Keep trying!\n");
    }

    return 0;
}