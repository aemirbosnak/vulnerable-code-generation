//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PARTICIPANTS 20

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        // Flag to check if any swapping happened
        int swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element found is greater than the next element
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped by the inner loop, break
        if (swapped == 0)
            break;
    }
}

// Function to display array
void displayScores(int arr[], int n) {
    printf("Scores: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function for generating random scores
void generateRandomScores(int arr[], int n) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Scores between 0 and 99
    }
}

int main() {
    int scores[MAX_PARTICIPANTS];
    int numParticipants;

    printf("Welcome to the Bubble Sort Competition!\n");
    printf("Enter the number of participants (1 to %d): ", MAX_PARTICIPANTS);
    scanf("%d", &numParticipants);

    // Validate number of participants
    if (numParticipants < 1 || numParticipants > MAX_PARTICIPANTS) {
        printf("Invalid number of participants! Exiting program.\n");
        return 1;
    }

    // Generate random scores
    generateRandomScores(scores, numParticipants);
    printf("Randomly generated scores for participants:\n");
    displayScores(scores, numParticipants);

    // Sorting scores using bubble sort
    printf("Sorting scores...\n");
    bubbleSort(scores, numParticipants);
    
    // Display sorted scores
    printf("Scores after sorting:\n");
    displayScores(scores, numParticipants);
    
    printf("Thank you for participating in the Bubble Sort Competition!\n");
    return 0;
}