//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of words to be typed
#define NUM_WORDS 50

// Define the words to be typed
char *words[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "watermelon", "xylophone", "yogurt", "zebra"};

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Print the instructions
    printf("Welcome to the Ada Lovelace C Typing Speed Test!\n");
    printf("You will be typing %d words.\n", NUM_WORDS);
    printf("Press ENTER to begin.\n");
    getchar();

    // Start the timer
    clock_t start = clock();

    // Loop through the words
    for (int i = 0; i < NUM_WORDS; i++) {
        // Print the word to type
        printf("%s ", words[i]);

        // Wait for the user to type the word
        char input[50];
        scanf("%s", input);

        // Check if the user typed the word correctly
        if (strcmp(input, words[i])!= 0) {
            printf("Incorrect!\n");
        }
    }

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("\nCongratulations! You have completed the Ada Lovelace C Typing Speed Test!\n");
    printf("You typed %d words in %.2f seconds.\n", NUM_WORDS, time_taken);
    printf("Your typing speed is %.2f words per second.\n", NUM_WORDS / time_taken);

    return 0;
}