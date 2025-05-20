//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int frequency[MAX_WORDS];
    int total_words = 0;

    printf("Enter some text (max length %d characters):\n", MAX_WORDS*MAX_WORD_LENGTH);

    // Read the whole text
    char ch;
    int word_length = 0, current_word = 0;
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            if (word_length < MAX_WORD_LENGTH) {
                words[current_word][word_length] = ch;
                word_length++;
            }
        } else if (word_length > 0) {
            words[current_word][word_length] = '\0';
            frequency[current_word]++;
            total_words++;
            current_word++;
            word_length = 0;
        }
        if (current_word >= MAX_WORDS) break;
    }

    // Sort the words by frequency
    for (int i=0; i<current_word-1; i++) {
        for (int j=i+1; j<current_word; j++) {
            if (frequency[i] < frequency[j]) {
                char temp_word[MAX_WORD_LENGTH];
                strcpy(temp_word, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp_word);
                int temp_frequency = frequency[i];
                frequency[i] = frequency[j];
                frequency[j] = temp_frequency;
            }
        }
    }

    // Print the results
    printf("\nWord frequency:\n");
    for (int i=0; i<current_word; i++) {
        printf("%s: %d (%.2f%%)\n", words[i], frequency[i], frequency[i]*100.0/total_words);
    }

    return 0;
}