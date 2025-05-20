//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Welcome to my Sorting Circus! 🎪
#define MAX_NUMBERS 100

// Function to print an array in a jolly way
void printArray(int arr[], int n) {
    printf("Here's an array of numbers dancing in a line:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Swap function to change places, like a clown juggling
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Bubble Sort, or as we like to call it: Baby Bubbles Sorting
void bubbleSort(int arr[], int n) {
    printf("Bubble Sort is starting! 🎈\n");
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                printf("Swapping %d and %d - It's a swap party! 🎊\n", arr[j], arr[j+1]);
                swap(&arr[j], &arr[j+1]);
            }
        }
        printf("Round %d done! Current array status:\n", i+1);
        printArray(arr, n);
    }
    printf("Bubble Sort completed! All sorted, just like clowns in a tidy row! 🤹\n");
}

// Function to fill our array with random numbers, like a piñata bursting! 🎉
void fillArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Filling with numbers from 0 to 999 
    }
    printf("Filled the array with random numbers, ready to party! 🥳\n");
}

// Start of the main show!
int main() {
    int arr[MAX_NUMBERS];
    int n;

    // How many numbers shall we sort today? 🤔
    printf("Welcome to the Sorting Circus! How many numbers do you want to sort (up to %d)? ", MAX_NUMBERS);
    scanf("%d", &n);

    while (n < 1 || n > MAX_NUMBERS) {
        printf("Oh dear! That's not a valid number! Please pick a number between 1 and %d:\n", MAX_NUMBERS);
        scanf("%d", &n);
    }

    fillArray(arr, n);
    printf("Original array before all the fun begins:\n");
    printArray(arr, n);

    bubbleSort(arr, n);
    
    printf("Array after Bubble Sort (or shall we say, after the circus performance):\n");
    printArray(arr, n);

    printf("Thanks for coming to the Sorting Circus! 🎡 Until next time, goodbye! 👋\n");
    return 0;
}