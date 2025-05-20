//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_LENGTH 20

char* words[MAX_WORDS] = {
    "apple",
    "banana",
    "cherry",
    "orange",
    "pineapple",
    "grapefruit",
    "strawberry",
    "blueberry",
    "raspberry",
    "pomegranate"
};

int main() {
    srand(time(NULL)); // seed random number generator with the current time
    int i, j;
    int score = 0;
    int total_time = 0;
    char input[MAX_LENGTH];

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be shown a series of words and you must type them as quickly as possible.\n");
    printf("Press enter to begin.\n");
    getchar(); // pause until enter is pressed

    for (i = 0; i < MAX_WORDS; i++) {
        // randomly select a word from the list
        int rand_index = rand() % MAX_WORDS;
        char* word = words[rand_index];
        int length = strlen(word);
        int errors = 0;

        // show the word
        printf("Word %d: %s\n", i+1, word);

        // get user input
        clock_t start_time = clock();
        scanf("%s", input);
        clock_t end_time = clock();
        total_time += end_time - start_time;

        // check the input
        for (j = 0; j < length; j++) {
            if (word[j] != input[j]) {
                errors++;
            }
        }

        if (errors == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect, %d errors.\n", errors);
        }
    }

    printf("You scored %d out of %d.\n", score, MAX_WORDS);
    printf("Total time: %d seconds.\n", (int)(total_time / CLOCKS_PER_SEC));

    return 0;
}