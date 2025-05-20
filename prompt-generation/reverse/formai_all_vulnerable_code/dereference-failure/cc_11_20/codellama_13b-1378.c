//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: paranoid
// Unique C Text Summarizer Program
// Paranoid Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100
#define MAX_WORD_LEN 20
#define MAX_SUMMARY_LEN 50

struct Word {
    char word[MAX_WORD_LEN];
    int count;
    struct Word *next;
};

struct Summary {
    char sentence[MAX_SUMMARY_LEN];
    int count;
    struct Summary *next;
};

int main() {
    struct Word *wordList = NULL;
    struct Summary *summaryList = NULL;
    char line[MAX_LINE_LEN];
    char word[MAX_WORD_LEN];
    char summary[MAX_SUMMARY_LEN];
    int wordCount = 0;
    int summaryCount = 0;

    // Read text from stdin
    while (fgets(line, MAX_LINE_LEN, stdin)) {
        // Parse each word in the line
        char *ptr = strtok(line, " ");
        while (ptr != NULL) {
            strcpy(word, ptr);
            ptr = strtok(NULL, " ");
            struct Word *currWord = wordList;
            struct Word *prevWord = NULL;
            // Find the word in the list
            while (currWord != NULL) {
                if (strcmp(currWord->word, word) == 0) {
                    // Word already exists, increment count
                    currWord->count++;
                    break;
                }
                prevWord = currWord;
                currWord = currWord->next;
            }
            if (currWord == NULL) {
                // New word, add it to the list
                currWord = (struct Word *)malloc(sizeof(struct Word));
                strcpy(currWord->word, word);
                currWord->count = 1;
                currWord->next = NULL;
                if (prevWord == NULL) {
                    wordList = currWord;
                } else {
                    prevWord->next = currWord;
                }
                wordCount++;
            }
        }
    }

    // Generate summary
    struct Word *currWord = wordList;
    while (currWord != NULL) {
        if (currWord->count > 1) {
            // Word is repeated, add it to the summary
            struct Summary *currSummary = summaryList;
            while (currSummary != NULL) {
                if (strcmp(currSummary->sentence, currWord->word) == 0) {
                    // Sentence already exists, increment count
                    currSummary->count++;
                    break;
                }
                currSummary = currSummary->next;
            }
            if (currSummary == NULL) {
                // New sentence, add it to the list
                currSummary = (struct Summary *)malloc(sizeof(struct Summary));
                strcpy(currSummary->sentence, currWord->word);
                currSummary->count = 1;
                currSummary->next = NULL;
                if (summaryList == NULL) {
                    summaryList = currSummary;
                } else {
                    currSummary->next = summaryList;
                }
                summaryCount++;
            }
        }
        currWord = currWord->next;
    }

    // Print summary
    struct Summary *currSummary = summaryList;
    while (currSummary != NULL) {
        printf("%s\n", currSummary->sentence);
        currSummary = currSummary->next;
    }

    // Free memory
    struct Word *currWordFree = wordList;
    while (currWordFree != NULL) {
        struct Word *nextWord = currWordFree->next;
        free(currWordFree);
        currWordFree = nextWord;
    }
    struct Summary *currSummaryFree = summaryList;
    while (currSummaryFree != NULL) {
        struct Summary *nextSummary = currSummaryFree->next;
        free(currSummaryFree);
        currSummaryFree = nextSummary;
    }

    return 0;
}