//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_COUNT 10 // Number of words to type
#define WORD_LENGTH 10 // Length of each word
#define MAX_ATTEMPTS 3 // Maximum number of attempts before failing
#define DELAY 100000 // Delay between each character (in microseconds)

int main() {
    int i, j, k, attempts, score = 0;
    char word[WORD_LENGTH+1];
    struct timespec delay;

    srand(time(NULL)); // Seed the random number generator

    // Generate random words
    for (i = 0; i < WORD_COUNT; i++) {
        for (j = 0; j < WORD_LENGTH; j++) {
            word[j] = rand() % 26 + 'a'; // Generate a random lowercase letter
        }
        word[WORD_LENGTH] = '\0'; // Terminate the string
    }

    // Test the user's typing speed
    for (i = 0; i < WORD_COUNT; i++) {
        printf("Word %d: ", i+1);
        fflush(stdout);

        for (j = 0; j < WORD_LENGTH; j++) {
            printf("%c", word[j]);
            fflush(stdout);
            usleep(DELAY); // Delay between each character
        }

        printf("\n");
        fflush(stdout);

        attempts = 0;
        while (attempts < MAX_ATTEMPTS) {
            scanf("%s", word);

            if (strcmp(word, word) == 0) { // Check if the input matches the expected word
                score++;
                break;
            }

            printf("Incorrect. Please try again.\n");
            fflush(stdout);
            attempts++;
        }

        if (attempts == MAX_ATTEMPTS) {
            printf("Sorry, you have reached the maximum number of attempts for this word.\n");
        }
    }

    // Display the user's score
    printf("Your final score is: %d/%d\n", score, WORD_COUNT);

    return 0;
}