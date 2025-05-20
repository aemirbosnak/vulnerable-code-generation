//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS 10000

int main() {
    char text[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int word_count[MAX_NUM_WORDS] = {0};
    char word[MAX_WORD_LENGTH];
    int num_words = 0;
    int i, j;

    printf("Enter some text:\n");

    // read in words
    while (scanf("%s", word) != EOF) {
        // convert word to lowercase
        for (i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // remove any punctuation from the end of the word
        if (ispunct(word[strlen(word)-1])) {
            word[strlen(word)-1] = '\0';
        }

        // add word to text[] if it isn't already in the array
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, text[i]) == 0) {
                word_count[i]++;
                break;
            }
        }
        if (i == num_words) {
            strcpy(text[num_words], word);
            word_count[num_words]++;
            num_words++;
        }
    }

    // print out word frequencies
    printf("\nWord\t\tFrequency\n");
    printf("------------------------\n");
    for (i = 0; i < num_words; i++) {
        printf("%-20s%d\n", text[i], word_count[i]);
    }

    // print out some statistics
    int total_words = 0, unique_words = 0, max_count = 0;
    char most_common_word[MAX_WORD_LENGTH];
    for (i = 0; i < num_words; i++) {
        total_words += word_count[i];
        unique_words++;
        if (word_count[i] > max_count) {
            max_count = word_count[i];
            strcpy(most_common_word, text[i]);
        }
    }
    printf("\nStatistics:\n");
    printf("Total number of words: %d\n", total_words);
    printf("Number of unique words: %d\n", unique_words);
    printf("Most common word: %s (appears %d times)\n", most_common_word, max_count);

    return 0;
}