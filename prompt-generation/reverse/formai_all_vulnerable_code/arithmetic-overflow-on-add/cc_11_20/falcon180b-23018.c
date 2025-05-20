//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 30

// Struct to hold each word and its frequency
typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} WordFreq;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[1024];
    char word[MAX_WORD_LEN];
    int i, j, k, max_freq = 0, freq;
    WordFreq words[MAX_WORDS];

    // Open input file
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        exit(1);
    }

    // Read in words and count their frequencies
    while (fgets(line, 1024, fp)!= NULL) {
        i = 0;
        while ((word[i] = tolower(line[i]))!= '\0') {
            if (isalpha(word[i])) {
                i++;
            } else {
                word[i] = '\0';
            }
        }
        j = 0;
        while (words[j].freq!= 0 && strcmp(word, words[j].word) < 0) {
            j++;
        }
        if (j >= MAX_WORDS) {
            printf("Error: Too many unique words\n");
            exit(1);
        }
        if (words[j].freq == 0) {
            strcpy(words[j].word, word);
        }
        words[j].freq++;
        if (words[j].freq > max_freq) {
            max_freq = words[j].freq;
        }
    }

    // Sort words by frequency
    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (words[j].freq > words[i].freq) {
                WordFreq temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print out summary
    printf("Summary:\n");
    for (i = 0; i < MAX_WORDS && words[i].freq!= 0; i++) {
        k = words[i].freq * 50 / max_freq;
        printf("%-30s %d\n", words[i].word, k);
    }

    fclose(fp);
    return 0;
}