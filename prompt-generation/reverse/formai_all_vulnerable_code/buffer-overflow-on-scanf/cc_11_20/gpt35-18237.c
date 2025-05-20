//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_NUM_WORDS 10000

int main(void) {
    char input_string[MAX_WORD_LEN + 1];
    char words[MAX_NUM_WORDS][MAX_WORD_LEN + 1];
    int frequencies[MAX_NUM_WORDS] = {0};
    int num_words = 0;
    int i, j;

    printf("Welcome to the Genius Word Frequency Counter!\n\n");
    printf("Enter some text:");
    while (scanf("%s", input_string) == 1) {
        if (num_words >= MAX_NUM_WORDS) {
            printf("Too many words, stopping input.\n");
            break;
        }

        // Convert input string to lowercase
        for (i = 0; i < strlen(input_string); i++) {
            input_string[i] = tolower(input_string[i]);
        }

        // Ignore any words longer than the maximum allowed length
        if (strlen(input_string) > MAX_WORD_LEN) {
            continue;
        }

        // Check if the word is already in our list of words
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i], input_string) == 0) {
                frequencies[i]++;
                break;
            }
        }

        // If the word is not already in our list, add it
        if (i == num_words) {
            strcpy(words[num_words], input_string);
            frequencies[num_words] = 1;
            num_words++;
        }
    }

    // Print out the word frequencies in descending order
    for (i = 0; i < num_words; i++) {
        int max_freq_index = i;
        for (j = i + 1; j < num_words; j++) {
            if (frequencies[j] > frequencies[max_freq_index]) {
                max_freq_index = j;
            }
        }
        // Swap the current word with the word with the highest frequency
        if (max_freq_index != i) {
            int temp_freq = frequencies[i];
            frequencies[i] = frequencies[max_freq_index];
            frequencies[max_freq_index] = temp_freq;

            char temp_word[MAX_WORD_LEN + 1];
            strcpy(temp_word, words[i]);
            strcpy(words[i], words[max_freq_index]);
            strcpy(words[max_freq_index], temp_word);
        }
        printf("%-20s : %d\n", words[i], frequencies[i]);
    }

    return 0;
}