//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "%s\n", "Usage: ./word_frequency_counter <filename>");
        return 1;
    }

    // open file for reading
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        fprintf(stderr, "Unable to open file \"%s\"\n", argv[1]);
        return 2;
    }

    // create word frequency counter
    int word_count = 0;
    int unique_word_count = 0;
    int max_word_count = 0;
    char **words = malloc(10000 * sizeof(char *));
    int *word_frequencies = malloc(10000 * sizeof(int));

    // read file word by word
    char word[MAX_WORD_LENGTH];
    while(fscanf(fp, "%s", word) != EOF) {
        // clean word (remove punctuation and convert to lowercase)
        int i = 0;
        while(word[i]) {
            if(!isalpha(word[i])) {
                memmove(&word[i], &word[i + 1], strlen(word) - i);
            } else {
                word[i] = tolower(word[i]);
                i++;
            }
        }

        // check if word is already in array
        int found = 0;
        int j;
        for(j = 0; j < unique_word_count; j++) {
            if(strcmp(words[j], word) == 0) {
                found = 1;
                word_frequencies[j] += 1;
                if(word_frequencies[j] > max_word_count) {
                    max_word_count = word_frequencies[j];
                }
                break;
            }
        }

        // add word to array if not found
        if(!found) {
            words[unique_word_count] = malloc(strlen(word) * sizeof(char));
            strcpy(words[unique_word_count], word);
            word_frequencies[unique_word_count] = 1;
            unique_word_count++;
        }

        word_count++;
    }

    // print word frequency table
    printf("%-20s %-20s %-20s\n", "WORD", "FREQUENCY", "PERCENTAGE");
    printf("--------------------------------------------------------------\n");
    int k;
    for(k = 0; k < unique_word_count; k++) {
        float percentage = (float) word_frequencies[k] / word_count * 100;
        printf("%-20s %-20d %-20.2f\n", words[k], word_frequencies[k], percentage);
    }

    printf("\nTotal number of words: %d\n", word_count);
    printf("Number of unique words: %d\n", unique_word_count);
    printf("Most common word(s):");
    for(k = 0; k < unique_word_count; k++) {
        if(word_frequencies[k] == max_word_count) {
            printf(" %s", words[k]);
        }
    }

    // free memory
    for(k = 0; k < unique_word_count; k++) {
        free(words[k]);
    }
    free(words);
    free(word_frequencies);

    return 0;
}