//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // welcome message
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a random phrase to type and your typing speed will be calculated.\nAre you ready?\n");

    // get user input to start test
    char start[10];
    scanf("%s", start);

    // check if user input is valid
    if (strcmp(start, "yes") == 0 || strcmp(start, "Yes") == 0 || strcmp(start, "YES") == 0) {
        // generate random phrase
        char phrase[] = "The quick brown fox jumps over the lazy dog.";

        // calculate length of phrase for accuracy scoring
        int length = strlen(phrase);

        // display phrase for user input
        printf("Type the following phrase as fast as you can:\n%s\n", phrase);

        // start timer
        clock_t start_time = clock();

        // get user input
        char input[100];
        scanf(" %[^\n]s", input);

        // stop timer
        clock_t stop_time = clock();

        // calculate typing speed in words per minute (wpm)
        int time_elapsed = (stop_time - start_time) / CLOCKS_PER_SEC;
        int words_typed = length / 5; // average word length is 5 characters
        int wpm = words_typed / time_elapsed * 60;

        // display results
        printf("You typed %d words in %d seconds.\n", words_typed, time_elapsed);
        printf("Your typing speed is %d wpm!\n", wpm);

        // farewell message
        printf("Thank you for taking the Typing Speed Test!\n");
    } else {
        // user did not input "yes" to start test
        printf("Okay, maybe next time. Goodbye!\n");
    }

    return 0;
}