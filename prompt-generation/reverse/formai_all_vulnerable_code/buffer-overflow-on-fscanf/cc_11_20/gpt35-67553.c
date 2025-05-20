//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_WORD_LENGTH 30

// Struct for the word and its frequency
struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int main () {
    struct word_frequency word_statistics[1000];
    int num_words = 0;

    // Open cyberpunk.txt file for reading
    FILE *fp = fopen("cyberpunk.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    char word[MAX_WORD_LENGTH];

    // Loop through each word in the file
    while (fscanf(fp, "%s", word) == 1) {
        // Convert to lowercase for matching
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        int word_found = 0;

        // Check if word is already in the array
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, word_statistics[i].word) == 0) {
                word_statistics[i].frequency++;
                word_found = 1;
                break;
            }
        }

        // Add new word to the array
        if (!word_found) {
            struct word_frequency new_word;
            strcpy(new_word.word, word);
            new_word.frequency = 1;
            word_statistics[num_words] = new_word;
            num_words++;
        }
    }

    // Close the file
    fclose(fp);

    // Sort the array by frequency in descending order
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = 0; j < num_words - i - 1; j++) {
            if (word_statistics[j].frequency < word_statistics[j+1].frequency) {
                struct word_frequency temp = word_statistics[j];
                word_statistics[j] = word_statistics[j+1];
                word_statistics[j+1] = temp;
            }
        }
    }
    
    // Print the word frequency statistics
    printf("Word Frequency Statistics for cyberpunk.txt:\n");
    printf("-------------------------------------------\n");
    printf("WORD\t\tFREQUENCY\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < num_words; i++) {
        printf("%-15s%d\n", word_statistics[i].word, word_statistics[i].frequency);
    }
    printf("-------------------------------------------\n");

    return 0;
}