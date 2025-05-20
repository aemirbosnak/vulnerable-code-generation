//FormAI DATASET v1.0 Category: Spell checking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_NUM_WORDS 1000

// Structure for storing the words and their frequencies
typedef struct word_freq {
    char word[MAX_WORD_LEN];
    int frequency;
} WordFreq;

// Function to search for a word in the given array of words
int search_word(char *word, WordFreq *wordList, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to process the text and count the frequency of each word
int process_text(char *text, WordFreq *wordList, int *numWords) {
    char *word;
    int pos;

    word = strtok(text, " ,.?!()\n");
    while (word != NULL) {
        pos = search_word(word, wordList, *numWords);
        if (pos >= 0) {
            wordList[pos].frequency++;
        } else {
            strcpy(wordList[*numWords].word, word);
            wordList[*numWords].frequency = 1;
            (*numWords)++;
        }
        word = strtok(NULL, " ,.?!()\n");
    }
    return 0;
}

// Function to sort the words by frequency in descending order
int sort_words(WordFreq *wordList, int numWords) {
    int i, j;
    WordFreq temp;

    for (i = 0; i < numWords-1; i++) {
        for (j = i+1; j < numWords; j++) {
            if (wordList[i].frequency < wordList[j].frequency) {
                temp = wordList[i];
                wordList[i] = wordList[j];
                wordList[j] = temp;
            }
        }
    }
    return 0;
}

// Function to print the top N most frequent words
int print_top_words(WordFreq *wordList, int numWords, int n) {
    int i;
    printf("Top %d most frequent words:\n", n);
    for (i = 0; i < n && i < numWords; i++) {
        printf("%s (%d)\n", wordList[i].word, wordList[i].frequency);
    }
    return 0;
}

int main() {
    char text[10000];
    WordFreq wordList[MAX_NUM_WORDS];
    int numWords = 0, n;

    // Read the text from the user
    printf("Enter the text:\n");
    fgets(text, 10000, stdin);

    // Process the text and count the frequency of each word
    process_text(text, wordList, &numWords);

    // Sort the words by frequency in descending order
    sort_words(wordList, numWords);

    // Ask the user for the number of most frequent words to display
    printf("How many of the most frequent words do you want to display?\n");
    scanf("%d", &n);

    // Print the top N most frequent words
    print_top_words(wordList, numWords, n);

    return 0;
}