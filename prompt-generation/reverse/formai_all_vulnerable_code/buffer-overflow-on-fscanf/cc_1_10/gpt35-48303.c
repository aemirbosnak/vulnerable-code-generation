//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
/* 
 * C Word Frequency Counter
 * Written by [Your Name Here]
 * 
 * This program counts the frequency of each word in a given text file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

int main(int argc, char *argv[]) {
    char *filename;
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_WORDS];
    int i, j;
    int uniqueWords = 0;
    int totalWords = 0;

    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    filename = argv[1];
    file = fopen(filename, "r");

    if(file == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    while(fscanf(file, "%s", word) == 1) {
        totalWords++;

        for(i = 0; i < wordCount; i++) {
            if(strcmp(words[i], word) == 0) {
                freq[i]++;
                break;
            }
        }

        if(i == wordCount) {
            strcpy(words[wordCount], word);
            freq[wordCount] = 1;
            wordCount++;
            uniqueWords++;
        }
    }

    printf("Total words: %d\n", totalWords);
    printf("Unique words: %d\n", uniqueWords);

    printf("\nWord\tFrequency\n");

    for(i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", words[i], freq[i]);
    }

    fclose(file);
    return 0;
}