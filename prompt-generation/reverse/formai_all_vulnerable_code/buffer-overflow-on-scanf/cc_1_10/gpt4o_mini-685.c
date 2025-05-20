//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a funny search algorithm called 'SillySearch'
// This algorithm acts like a detective who is very forgetful!

#define SIZE 100

// Function prototypes
void generateRandomArray(int arr[], int size);
int sillySearch(int arr[], int size, int target);
void putOnDetectiveHat();

int main() {
    int arr[SIZE];
    int target;
    int index;

    // Calling the function to generate a random array
    generateRandomArray(arr, SIZE);

    // Putting on our imaginary detective hat!
    putOnDetectiveHat();

    // Asking the user for a target number
    printf("Hello! I'm Detective SillySearch! What number are we hunting for today? ");
    scanf("%d", &target);
    
    // Time to go searching!
    index = sillySearch(arr, SIZE, target);

    // Did we find our prize?
    if (index != -1) {
        printf("Hooray! I found the number %d at index %d! \n", target, index);
    } else {
        printf("Alas! The number %d eluded me this time! 😢\n", target);
    }

    return 0;
}

// This function generates an array with random numbers between 1 and 100
void generateRandomArray(int arr[], int size) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1; // Random number from 1 to 100
    }
}

// This is our silly search algorithm
int sillySearch(int arr[], int size, int target) {
    printf("Setting off on my search mission to find %d...\n", target);
    for (int i = 0; i < size; i++) {
        printf("Looking at index %d, which holds the number %d...\n", i, arr[i]);
        if (arr[i] == target) {
            printf("Oops! I almost forgot — I found it at index %d! 🎉\n", i);
            return i; // Number found at index i
        } else {
            printf("Nope! Not the one! Let's keep hunting...\n");
        }
    }
    return -1; // Target not found, sad detective
}

// A function to represent our silly detective putting on his hat
void putOnDetectiveHat() {
    printf("🎩 Putting on my detective hat...\n");
    printf("🔍 Adjusting my magnifying glass...\n");
    printf("🤔 Getting into the detective mood...\n");
    printf("Are you ready for some silly search adventures? Let's go!\n");
}