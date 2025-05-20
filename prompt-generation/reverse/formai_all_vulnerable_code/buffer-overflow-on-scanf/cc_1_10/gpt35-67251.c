//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int rand_indexes[MAX_WORDS];

void generate_rand_indexes(int n) {
    for (int i = 0; i< n; ++i) {
        rand_indexes[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        int rnd_index = rand() % n;
        int temp = rand_indexes[i];
        rand_indexes[i] = rand_indexes[rnd_index];
        rand_indexes[rnd_index] = temp;
    }
}

int main() {
    srand(time(NULL));
    int num_words = 0;
    printf("Enter number of words in the typing test (minimum 10): ");
    scanf("%d", &num_words);

    if (num_words < 10) {
        printf("Invalid number of words. Try again with a minimum of 10\n");
        exit(0);
    }
    else if (num_words > MAX_WORDS) {
        printf("Maximum number of words exceeded (%d max)\n", MAX_WORDS);
        exit(0);
    }

    // read words input
    printf("Enter %d words (maximum length of %d characters) for the typing test:\n", num_words, MAX_WORD_LENGTH);
    for (int i = 0; i < num_words; ++i) {
        scanf("%s", words[i]);
    }

    // generate random indexes
    generate_rand_indexes(num_words);

    // display instructions
    printf("\nInstructions:\n1. Type the word you see on the screen.\n2. Press ENTER to start timer and see next word.\n3. Press CTRL-C (Windows) or Command-C (Mac) to stop timer and check your typing speed.\n\nReady? Press ENTER to start!\n");

    // wait for user input before starting timer
    getchar();

    // start timer
    time_t start_time = time(NULL);

    int word_num = 0;
    char input_word[MAX_WORD_LENGTH];
    while (word_num < num_words) {
        // clear input buffer
        fflush(stdin);

        // display word
        printf("%s ", words[rand_indexes[word_num]]);

        // wait for user input
        scanf("%s", input_word);

        // check if word is correct
        if (strcmp(input_word, words[rand_indexes[word_num]]) == 0) {
            ++word_num;
        }
        else {
            printf("Incorrect. Try again.\n");
        }
    }

    // stop timer and calculate typing speed
    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);
    double typing_speed = (double) num_words / elapsed_time * 60;

    // display result
    printf("\nYou completed the typing test in %.0f seconds with an average speed of %.0f words per minute.\n", elapsed_time, typing_speed);

    return 0;
}