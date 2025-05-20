//FormAI DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to shuffle an array using Fisher-Yates algorithm
void shuffle(int arr[], int n){
    srand(time(NULL));  // Seed random number generator

    // Start from the last element and swap one by one
    for(int i=n-1; i>=1; i--){
        // Generate a random number between 0 and i (inclusive)
        int j = rand() % (i+1);

        // Swap arr[i] with the randomly selected element
        swap(&arr[i], &arr[j]);
    }
}

int main(){
    int arr[4] = {1, 2, 3, 4};  // Array to be shuffled
    int guess[4];  // Array to store player's guess

    // Shuffle the array
    shuffle(arr, 4);

    printf("The shuffled array is: ");
    for(int i=0; i<4; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Get player's guess
    printf("Enter your guess (4 distinct numbers between 1 and 4): ");
    for(int i=0; i<4; i++){
        scanf("%d", &guess[i]);
    }

    // Check the guess
    int correct = 0;
    for(int i=0; i<4; i++){
        if(arr[i] == guess[i]){
            correct++;
        }
    }

    if(correct == 4){
        printf("Congratulations, you win!\n");
    } else {
        printf("Sorry, you lose. The correct answer was: ");
        for(int i=0; i<4; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}