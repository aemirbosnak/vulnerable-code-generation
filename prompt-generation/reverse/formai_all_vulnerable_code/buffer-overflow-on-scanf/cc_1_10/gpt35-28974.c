//FormAI DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to shuffle an array of integers
void shuffle(int *arr, int size) {
    srand(time(NULL));
    for(int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

//Function to print the array
void printArray(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    //Initialize an array of integers
    int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    //Shuffle the array
    shuffle(arr, size);

    //Initialize variables for game play
    int guesses = 0;
    int prevIndex = -1;
    int currIndex = -1;
    int prevGuess = -1;
    int currGuess = -1;

    //Game loop
    while(guesses < 8) {
        //Print current game board
        printArray(arr, size);

        //Get first guess from user
        printf("Enter first guess: ");
        scanf("%d", &currGuess);

        currIndex = -1;

        //Find index of current guess in array
        for(int i = 0; i < size; i++) {
            if(arr[i] == currGuess) {
                currIndex = i;
                break;
            }
        }

        //If current guess is not in array, start over
        if(currIndex == -1) {
            printf("Invalid guess. Try again.\n");
            continue;
        }

        //If this is the first guess, store it and move on
        if(prevIndex == -1) {
            prevIndex = currIndex;
            prevGuess = currGuess;
            continue;
        }

        //If the current and previous guesses match, remove them from the board
        if(currGuess == prevGuess && currIndex != prevIndex) {
            arr[currIndex] = 0;
            arr[prevIndex] = 0;
            printf("Match found!\n");
            guesses++;
        } else {
            printf("No match.\n");
        }

        //Reset variables for next guess
        prevIndex = -1;
        currIndex = -1;
        prevGuess = -1;
        currGuess = -1;
    }

    printf("Congratulations! You won in %d guesses!\n", guesses);

    return 0;
}