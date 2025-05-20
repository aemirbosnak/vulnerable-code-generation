//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* function prototype */
int typingSpeedTest();

int main() {
    int totalTime;

    /* seed random number generator */
    srand((unsigned) time(NULL));

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have 60 seconds to type as many words as you can.\n");
    printf("Are you ready? Press ENTER to start...");
    getchar();

    /* start timer */
    clock_t start = clock();

    /* run typing speed test */
    typingSpeedTest();

    /* stop timer */
    clock_t stop = clock();

    /* calculate time elapsed */
    double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    totalTime = (int) elapsed / 60;
    printf("\nTime taken: %d minutes %.0f seconds\n", totalTime, elapsed - totalTime * 60);

    printf("Thank you for taking the Typing Speed Test!\n");

    return 0;
}

int typingSpeedTest() {
    char *words[] = {"artistic", "brother", "cat", "destiny", "elephant", "fancy", "gold", "happiness", "indigo", "jazz",
                     "kangaroo", "lemon", "mountain", "naughty", "orange", "purple", "quality", "rocket", "strawberry",
                     "turtle", "umbrella", "victory", "watermelon", "xylophone", "yellow", "zebra"};

    int i, len, numWords, numCorrect, numIncorrect;
    char input[50], *word;

    /* initialize counts and select random number of words */
    numWords = 0;
    numCorrect = 0;
    numIncorrect = 0;
    numWords = rand() % 51 + 50;

    /* display number of words to be typed */
    printf("\nNumber of words to type: %d\n\n", numWords);

    /* loop through random words */
    for (i = 0; i < numWords; i++) {
        /* select random word */
        word = words[rand() % 26];

        /* display word to be typed */
        printf("%s ", word);

        /* get user input */
        fgets(input, 50, stdin);

        /* remove newline character from input */
        len = strlen(input);
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        /* compare input to word */
        if (strcmp(input, word) == 0) {
            numCorrect++;
        } else {
            numIncorrect++;
        }
    }

    /* display results */
    printf("\n\nResults:\n");
    printf("Number of words typed correctly: %d\n", numCorrect);
    printf("Number of words typed incorrectly: %d\n", numIncorrect);

    /* calculate and display accuracy percentage */
    printf("Accuracy: %.2f%%\n", ((double)numCorrect / numWords) * 100);

    /* calculate and display typing speed in words per minute */
    printf("Typing speed: %d words per minute\n", (int)((double)numWords / ((double)clock() / CLOCKS_PER_SEC / 60)));

    return 0;
}