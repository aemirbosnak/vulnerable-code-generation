//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

// A struct to represent a word and its frequency
typedef struct WordFrequency {
    char word[MAX_WORD_LEN];
    int frequency;
} WordFrequency;

int main() {
    char text[MAX_WORDS][MAX_WORD_LEN];
    int freq[MAX_WORDS], i, j, total_words = 0;
    WordFrequency wordFrequencyList[MAX_WORDS];

    printf("Enter text: \n");

    // Read input text
    while (scanf("%s", &text[total_words]) != EOF) {
        total_words++;
    }

    // Count frequency of each word
    for(i=0; i<total_words; i++) {
        freq[i] = 1;
        for(j=i+1; j<total_words; j++) {
            if(strcmp(text[i], text[j]) == 0) {
                freq[i]++;
                // mark the word as counted so it won't be counted again
                strcpy(text[j], "0");
            }
        }
    }

    // Create a sorted list of word frequencies
    int count = 0;
    for (i = 0; i < total_words; i++) {
        if (strcmp(text[i], "0") != 0) {
            strcpy(wordFrequencyList[count].word, text[i]);
            wordFrequencyList[count].frequency = freq[i];
            count++;
        }
    }
    total_words = count;

    // Sort the list of word frequencies from highest to lowest
    for(i=0; i<total_words; i++) {
        for(j=i+1; j<total_words; j++) {
            if(wordFrequencyList[i].frequency < wordFrequencyList[j].frequency) {
                WordFrequency temp = wordFrequencyList[i];
                wordFrequencyList[i] = wordFrequencyList[j];
                wordFrequencyList[j] = temp;
            }
        }
    }

    // Print the list of word frequencies
    printf("\nWord\t\tFrequency\n"); 
    for(i=0; i<total_words; i++) {
        printf("%-15s %d\n", wordFrequencyList[i].word, wordFrequencyList[i].frequency);
    }

    return 0;
}