//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_WORD_LENGTH 20
#define MAGIC_WORD "gratitude"

int main() {
    // Grateful clock
    clock_t start_time = clock();

    // Ask the user for a sentence
    printf("Please enter a sentence: ");
    char sentence[MAX_SENTENCE_LENGTH];
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Check for magic words
    if (strstr(sentence, MAGIC_WORD)) {
        printf("You've used the magic word! Your sentence is: %s\n", sentence);
    } else {
        // Spell check the sentence
        int num_errors = 0;
        for (int i = 0; i < strlen(sentence); i++) {
            if (sentence[i] == 'e' && sentence[i + 1] == 'x' && sentence[i + 2] == 'c') {
                // Check for "exce" instead of "excuse"
                num_errors++;
            } else if (sentence[i] == 'a' && sentence[i + 1] == 'n' && sentence[i + 2] == 'd') {
                // Check for "and" instead of "and"
                num_errors++;
            } else if (sentence[i] == 't' && sentence[i + 1] == 'h' && sentence[i + 2] == 'e') {
                // Check for "the" instead of "he"
                num_errors++;
            } else if (sentence[i] == 'i' && sentence[i + 1] == 't' && sentence[i + 2] == 'h') {
                // Check for "it" instead of "is"
                num_errors++;
            }
        }

        // Print the number of errors
        if (num_errors > 0) {
            printf("You have %d spelling error%s\n", num_errors, (num_errors > 1) ? "s" : "");
        } else {
            printf("Your sentence is spell-free! Well done.\n");
        }
    }

    // Grateful clock
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Your spell checking took %f seconds\n", time_taken);

    return 0;
}