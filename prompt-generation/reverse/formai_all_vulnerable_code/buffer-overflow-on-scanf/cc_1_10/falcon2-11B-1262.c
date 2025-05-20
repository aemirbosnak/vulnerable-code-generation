//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include <stdio.h>
#include <time.h>

int main() {
    // Initializing variables
    char *text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    int words = 0, sentences = 0, correct = 0, errors = 0, time = 0;
    int start_time, end_time;

    // Getting user input
    printf("Welcome to the Typing Speed Test!\n");
    printf("Please type the following text as fast as you can:\n");
    printf("%s\n", text);
    printf("Press any key to start...");
    getchar();
    printf("\n");

    // Measuring time
    start_time = clock();

    // Typing test
    while (1) {
        // Getting user input
        printf("Enter the next word: ");
        fflush(stdin);
        char word[100];
        scanf("%s", word);

        // Checking if the word is correct
        if (strcmp(word, text) == 0) {
            correct++;
        } else {
            errors++;
        }

        // Checking if the user has finished typing
        if (strcmp(word, "The End") == 0) {
            break;
        }
    }

    // Ending time
    end_time = clock();

    // Calculating time
    time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Printing results
    printf("You typed %d words, %d sentences, and %d errors.\n", words, sentences, errors);
    printf("Your typing speed was %.2f words per minute.\n", words / (time / 60.0));
    printf("Congratulations! You completed the test in %.2f seconds.\n", time);

    return 0;
}