#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50
#define SUMMARY_LENGTH 200

void summarizeText(const char* text, int maxSummaryLength) {
    int wordCount[MAX_WORDS] = {0};
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int uniqueWords = 0;
    int totalChars = 0;

    // Tokenize the text into words
    char* token = strtok((char*)text, " ");
    while (token != NULL && uniqueWords < MAX_WORDS) {
        strcpy(words[uniqueWords], token);
        wordCount[uniqueWords]++;
        uniqueWords++;
        token = strtok(NULL, " ");
    }

    // Sort words by frequency
    for (int i = 0; i < uniqueWords - 1; i++) {
        for (int j = i + 1; j < uniqueWords; j++) {
            if (wordCount[i] < wordCount[j]) {
                int tempCount = wordCount[i];
                char tempWord[MAX_WORD_LENGTH];
                strcpy(tempWord, words[i]);
                wordCount[i] = wordCount[j];
                strcpy(words[i], words[j]);
                wordCount[j] = tempCount;
                strcpy(words[j], tempWord);
            }
        }
    }

    // Generate summary
    printf("Summary: ");
    for (int i = 0; i < uniqueWords && totalChars < maxSummaryLength; i++) {
        int len = strlen(words[i]);
        if (totalChars + len > maxSummaryLength) break;
        printf("%s ", words[i]);
        totalChars += len + 1;
    }
    printf("\n");
}

int main() {
    const char* text = "This is a sample text for summarization. This text will be summarized by selecting the most frequent words.";
    int maxSummaryLength = 100;
    summarizeText(text, maxSummaryLength);
    return 0;
}
