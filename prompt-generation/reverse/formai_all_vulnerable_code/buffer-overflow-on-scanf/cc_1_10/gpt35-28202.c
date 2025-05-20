//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

int read_words(char words[][MAX_WORD_LEN]);
int word_frequency(char words[][MAX_WORD_LEN], int count, char word[]);

int main() {
    char words[MAX_WORDS][MAX_WORD_LEN];
    char search_word[MAX_WORD_LEN];
    int count, freq;

    printf("Enter a list of words separated by spaces: ");
    count = read_words(words);

    printf("\nEnter the word to search for: ");
    scanf("%s", search_word);

    freq = word_frequency(words, count, search_word);

    printf("\nThe word '%s' appears %d times.", search_word, freq);

    return 0;
}

int read_words(char words[][MAX_WORD_LEN]) {
    int i = 0;

    while(scanf("%s", words[i]) == 1) {
        i++;
    }

    return i;
}

int word_frequency(char words[][MAX_WORD_LEN], int count, char word[]) {
    int i;
    int freq = 0;

    for(i = 0; i < count; i++) {
        if(strcmp(words[i], word) == 0) {
            freq++;
        }
    }

    return freq;
}