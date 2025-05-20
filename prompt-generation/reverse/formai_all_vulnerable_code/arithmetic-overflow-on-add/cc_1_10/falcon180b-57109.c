//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 10000

// Recursive function to count the frequency of a word in a sentence
int count_word_frequency(char *sentence, char *word, int *frequency) {
    // Base case: word not found
    if (strstr(sentence, word) == NULL) {
        return 0;
    }

    // Recursive case: word found
    int count = 1;
    char *p = strstr(sentence, word);
    while (p!= NULL) {
        count++;
        p = strstr(p + 1, word);
    }
    *frequency += count;
    return count;
}

// Function to remove punctuation from a string
void remove_punctuation(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isalnum(str[i])) {
            continue;
        }
        str[j++] = tolower(str[i]);
    }
    str[j] = '\0';
}

int main() {
    char sentence[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int frequency;

    // Read input sentence
    printf("Enter a sentence: ");
    fgets(sentence, MAX_WORD_LENGTH, stdin);
    remove_punctuation(sentence);

    // Read input word
    printf("Enter a word: ");
    fgets(word, MAX_WORD_LENGTH, stdin);
    remove_punctuation(word);

    // Count frequency of word in sentence
    count_word_frequency(sentence, word, &frequency);

    // Print result
    printf("The word '%s' appears %d times in the sentence '%s'.\n", word, frequency, sentence);

    return 0;
}