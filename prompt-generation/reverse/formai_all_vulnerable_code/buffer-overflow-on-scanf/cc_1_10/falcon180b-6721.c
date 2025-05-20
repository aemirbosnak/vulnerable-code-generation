//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define the range of numbers to search in
    int min = 1;
    int max = 100;

    // Generate a random number to search for
    int target = rand_num(min, max);

    // Prompt the user for the search method
    printf("Welcome to the silly search game!\n");
    printf("We've hidden a number between %d and %d.\n", min, max);
    printf("Can you find it?\n");
    int choice;
    printf("Enter 1 for linear search or 2 for binary search: ");
    scanf("%d", &choice);

    // Perform the chosen search method
    int found = 0;
    if (choice == 1) {
        printf("Performing linear search...\n");
        for (int i = min; i <= max; i++) {
            if (i == target) {
                found = 1;
                printf("Congratulations! You found the number %d!\n", target);
                break;
            }
        }
    } else if (choice == 2) {
        printf("Performing binary search...\n");
        int left = min;
        int right = max;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid == target) {
                found = 1;
                printf("Congratulations! You found the number %d!\n", target);
                break;
            } else if (mid < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    // Check if the number was found
    if (!found) {
        printf("Sorry, you didn't find the number %d.\n", target);
    }

    return 0;
}