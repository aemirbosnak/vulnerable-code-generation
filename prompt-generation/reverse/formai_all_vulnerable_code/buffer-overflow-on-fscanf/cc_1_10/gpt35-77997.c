//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

// structure to store a word and its frequency
typedef struct word_freq {
    char* word;
    int freq;
} word_freq;

// function to increment the frequency of a word, or add it as a new word if it doesn't exist yet
void increment_word_freq(word_freq* word_list, int* num_words, char* word) {
    int i;

    // first check if the word already exists in the list
    for (i = 0; i < *num_words; i++) {
        if (strcmp(word_list[i].word, word) == 0) {
            // word already exists, so just increment its frequency
            word_list[i].freq++;
            return;
        }
    }

    // word doesn't exist yet, so add it to the list
    word_list[*num_words].word = malloc(strlen(word) + 1);
    strcpy(word_list[*num_words].word, word);
    word_list[*num_words].freq = 1;
    (*num_words)++;
}

int main() {
    char filename[100];
    char word[MAX_WORD_LENGTH];
    int num_words = 0;
    word_freq word_list[MAX_NUM_WORDS];
    FILE* fp;

    // prompt user for filename
    printf("Enter the name of the file to be processed: ");
    scanf("%s", filename);

    // open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // read file word by word, and increment their frequencies
    while (fscanf(fp, "%s", word) == 1) {
        // remove any non-alpha characters from the word
        int i, j;
        for (i = 0, j = 0; word[i] != '\0'; i++) {
            if (isalpha(word[i])) {
                word[j++] = tolower(word[i]);
            }
        }
        word[j] = '\0';

        if (strlen(word) > 0) {
            increment_word_freq(word_list, &num_words, word);
        }
    }

    // close file
    fclose(fp);

    // print out the word frequencies in descending order
    int i, j;
    word_freq temp;
    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (word_list[i].freq < word_list[j].freq) {
                temp = word_list[i];
                word_list[i] = word_list[j];
                word_list[j] = temp;
            }
        }
    }

    printf("Word frequencies in descending order:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_list[i].word, word_list[i].freq);
    }

    // free memory for dynamically allocated strings
    for (i = 0; i < num_words; i++) {
        free(word_list[i].word);
    }

    return 0;
}