//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Generate random numbers from 1 to 20
void generateNumbers(int arr[]) {
    srand(time(NULL));
    for(int i=0; i<SIZE; i++) {
        arr[i] = rand() % 20 + 1;
    }
}

// Display the generated numbers
void displayNumbers(int arr[]) {
    printf("The generated numbers are:\n");
    for(int i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Search for a number in the array
int searchNumber(int arr[], int num, int *guesses) {
    for(int i=0; i<SIZE; i++) {
        (*guesses)++;
        if(arr[i] == num) {
            return i;
        }
    }
    return -1;
}

int main() {
    int secretNum, guesses = 0, foundIndex;
    int numbers[SIZE];
    printf("Welcome to the Multiplayer Searching Game!\n\n");
    generateNumbers(numbers);
    displayNumbers(numbers);
    printf("Enter your secret number (1 to 20): ");
    scanf("%d", &secretNum);
    foundIndex = searchNumber(numbers, secretNum, &guesses);
    if(foundIndex == -1) {
        printf("Sorry! Your number was not found in the array.\n");
    } else {
        printf("Congratulations! Your number was found at position %d.\n", foundIndex+1);
    }
    printf("Number of guesses taken: %d\n", guesses);
    return 0;
}