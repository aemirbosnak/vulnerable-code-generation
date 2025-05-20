//FormAI DATASET v1.0 Category: Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to shuffle an array
void shuffle(int* arr, int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

int main() {
    printf("Welcome to the Donald Knuth Shuffle Game!\n\n");
    printf("In this game, you will be given a list of numbers and ");
    printf("your task is to shuffle them in a specific way.\n\n");
    printf("Are you ready to play? (y/n): ");

    char response[5];
    fgets(response, 5, stdin);
    if (response[0] == 'y' || response[0] == 'Y') {
        printf("\nGreat! Let's get started.\n\n");

        // Create an array of numbers
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int n = sizeof(arr) / sizeof(arr[0]);

        // Shuffle the array
        shuffle(arr, n);

        // Print the shuffled array
        printf("Here is the shuffled array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");

        // Ask the player to shuffle the array
        printf("Now, it's your turn to shuffle the array.\n");
        printf("Try to shuffle it using the Donald Knuth Shuffle algorithm.\n\n");

        int moves = 0;
        while (1) {
            printf("Enter two indexes to swap (separated by a space): ");
            int index1, index2;
            scanf("%d %d", &index1, &index2);

            // Check if the indexes are valid
            if (index1 < 0 || index1 >= n || index2 < 0 || index2 >= n) {
                printf("Invalid indexes! Please try again.\n\n");
                continue;
            }

            // Check if the indexes are the same
            if (index1 == index2) {
                printf("The two indexes are the same! Please try again.\n\n");
                continue;
            }

            // Swap the elements
            swap(&arr[index1], &arr[index2]);
            moves++;

            // Check if the array is sorted
            int sorted = 1;
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] > arr[i+1]) {
                    sorted = 0;
                    break;
                }
            }

            // If the array is sorted, congratulate the player and end the game
            if (sorted) {
                printf("\nCongratulations! You sorted the array using the Donald Knuth Shuffle algorithm in %d moves.\n", moves);
                break;
            }
            else {
                printf("\nHere is the current state of the array after %d moves: ", moves);
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n\n");
            }
        }
    }
    else {
        printf("\nMaybe next time. Goodbye!\n");
    }

    return 0;
}