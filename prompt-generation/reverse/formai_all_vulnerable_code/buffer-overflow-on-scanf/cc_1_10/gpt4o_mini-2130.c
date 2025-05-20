//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int arr[], int size) {
    printf("Current Array: [ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            printf("Comparing %d and %d...\n", arr[j], arr[j+1]);
            if (arr[j] > arr[j+1]) {
                printf("Swapping %d and %d!\n", arr[j], arr[j+1]);
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            print_array(arr, n);
        }
    }
}

int guess_the_number(int sorted[], int n) {
    int guess, index = 0;
    printf("\nCan you guess the next number to be sorted? (0 to exit) ");
    while (index < n) {
        scanf("%d", &guess);
        if (guess == 0) break;
        if (guess == sorted[index]) {
            printf("Correct! %d is indeed the next number.\n", guess);
            index++;
        } else {
            printf("Oops! %d is not the next number. Try again!\n", guess);
        }
    }
    return index;
}

int main() {
    srand(time(NULL));
    int size, rounds;
    
    printf("Welcome to the Sorting Adventure Game!\n");
    printf("How many numbers would you like to sort? (Enter a number between 5 and 20): ");
    scanf("%d", &size);

    if (size < 5 || size > 20) {
        printf("Invalid size! Exiting game.\n");
        return 1;
    }

    int arr[size];
    printf("Generating %d random numbers...\n", size);
    
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Generates numbers from 0 to 99
    }

    print_array(arr, size);
    printf("Let the sorting begin!\n");

    // Sorting
    bubble_sort(arr, size);
    
    printf("Sorting complete!\n");
    print_array(arr, size);
    
    printf("\nIt's time to guess the sorted numbers!\n");
    rounds = guess_the_number(arr, size);
    
    if (rounds == size) {
        printf("Congratulations! You guessed all numbers correctly!\n");
    } else {
        printf("You guessed %d out of %d correctly. Good try!\n", rounds, size);
    }

    return 0;
}