//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20
#define MAX_TYPING_TIME 60

char words[MAX_WORDS][MAX_WORD_LENGTH] = {
    "apple", "banana", "cherry", "date", "elderberry",
    "fig", "grape", "honeydew", "kiwi", "lemon"
};

int main() {
    int numWords;
    int numCorrect = 0;
    int totalWords = 0;
    int wordIndex = 0;
    int i;
    int j;
    int k;
    int correct = 0;
    char input[MAX_WORD_LENGTH];
    int typingTime = MAX_TYPING_TIME;
    char *word;
    int wordLength;
    time_t startTime, endTime;
    double elapsedTime;
    int wpm;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type as many words as possible.\n", typingTime);
    printf("Press enter to begin...\n");
    getchar();

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of words to type
    printf("How many words would you like to type? ");
    scanf("%d", &numWords);

    // Generate random words
    for (i = 0; i < numWords; i++) {
        wordIndex = rand() % MAX_WORDS;
        word = words[wordIndex];
        wordLength = strlen(word);
        for (j = 0; j < wordLength; j++) {
            input[j] = word[j];
        }
        input[wordLength] = '\0';
    }

    // Start the timer
    startTime = time(NULL);

    // Begin the test
    for (i = 0; i < numWords; i++) {
        printf("%s\n", input);
        fflush(stdout);
        if (scanf("%s", input) == 1) {
            correct++;
        }
        totalWords++;
    }

    // Stop the timer
    endTime = time(NULL);
    elapsedTime = difftime(endTime, startTime);

    // Calculate words per minute
    wpm = (int) (totalWords / (elapsedTime / 60.0));

    // Display the results
    printf("\nYou typed %d words correctly out of %d total words.\n", correct, totalWords);
    printf("Your typing speed is %d words per minute.\n", wpm);

    return 0;
}