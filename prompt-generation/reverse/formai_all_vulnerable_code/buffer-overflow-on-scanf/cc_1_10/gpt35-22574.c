//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"dog", "cat", "bird", "laptop", "phone", "table", "chair", "book", "pen", "paper" };
    int random_index, word_count = 0, correct_words = 0, incorrect_words = 0;
    char input_word[MAX_WORD_LENGTH];
    clock_t start_time, end_time;
    double time_used;

    printf("Welcome to the Typing Test!\n");
    printf("Type as many words as possible in 30 seconds.\n");
    printf("---------------------------------------------\n");

    while (1) {
        random_index = rand() % MAX_WORDS;  // generate a random index to pick a word from the array of words
        printf("%s\n", words[random_index]);
        scanf("%s", input_word);
        word_count++;  // increment the word count

        // check if the input word matches the displayed word
        if (strcmp(words[random_index], input_word) == 0) {
            printf("Correct!\n");
            correct_words++;
        } else {
            printf("Incorrect!\n");
            incorrect_words++;
        }

        // end the typing test after 30 seconds
        if (word_count == 1) {
            start_time = clock();  // start the timer
        } else if (word_count == 31) {
            end_time = clock();  // end the timer
            time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

            printf("---------------------------------------------\n");
            printf("Results:\n");
            printf("Time used: %.2f seconds\n", time_used);
            printf("Number of correct words: %d\n", correct_words);
            printf("Number of incorrect words: %d\n", incorrect_words);
            printf("Words per minute (wpm): %.2f\n", (double) correct_words / time_used * 60);
            printf("---------------------------------------------\n");

            break;
        }
    }

    return 0;
}