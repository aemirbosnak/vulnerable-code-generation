//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Welcome to the World's Silliest Search Algorithm!

void print_array(int arr[], int size) {
    printf("Here's the array that we're going to search through:\n[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int silly_search(int arr[], int size, int target) {
    printf("So you're looking for the number %d, huh? Let's play a little game...\n", target);
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Found it! 🎉 Number %d is hiding at index: %d!\n", target, i);
            return i;  // Target found, return the index
        }
        
        // Let's just pretend we're super serious about searching
        printf("Checking index %d... Nope! It's just a %d. 🤔\n", i, arr[i]);
    }
    
    printf("Alas, %d is lost in the abyss of numbers! 😢\n", target);
    return -1;  // Target not found
}

int main() {
    srand(time(0));  // Seed the random number generator
    int size = 10;
    int arr[size];
    
    // Fill the array with silly random numbers between 1 and 50
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50 + 1; // Numbers from 1 to 50
    }
    
    print_array(arr, size);
    
    int target;
    printf("Enter a number between 1 and 50 to search for: ");
    scanf("%d", &target);
    
    // If the user puts in an outlandish number, we’ll just let them know.
    if (target < 1 || target > 50) {
        printf("Well... that's awkward. Please choose a number between 1 and 50 next time! 😅\n");
        return 0;
    }
    
    // Let the silliness begin!
    int result = silly_search(arr, size, target);
    
    if (result == -1) {
        printf("You know what? %d must be in another universe! 👽\n", target);
    } else {
        printf("Success! %d found at index %d. Give yourself a pat on the back! 👏\n", target, result);
    }
    
    // Exit with a bang, not a whimper!
    printf("Hope you had fun with this silly search! Bye-bye now! 🚀\n");
    return 0;  
}