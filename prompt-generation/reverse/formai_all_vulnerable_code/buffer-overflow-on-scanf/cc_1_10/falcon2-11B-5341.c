//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_WORDS 10

int main() {
    char text[MAX_LENGTH];
    char words[MAX_WORDS][MAX_LENGTH];
    int wordCount = 0;
    int sentenceCount = 0;
    int summaryLength = 0;
    int sentenceLength = 0;

    printf("Enter text to summarize: ");
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = '\0';  // remove trailing newline

    printf("Enter number of words to summarize: ");
    scanf("%d", &wordCount);
    if (wordCount > MAX_WORDS) {
        printf("Number of words must be less than or equal to %d.\n", MAX_WORDS);
        return 0;
    }

    printf("Enter number of sentences to summarize: ");
    scanf("%d", &sentenceCount);
    if (sentenceCount > MAX_WORDS) {
        printf("Number of sentences must be less than or equal to %d.\n", MAX_WORDS);
        return 0;
    }

    printf("Enter text to summarize: ");
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = '\0';  // remove trailing newline

    printf("Enter words to summarize: ");
    for (int i = 0; i < wordCount; i++) {
        fgets(words[i], MAX_LENGTH, stdin);
        words[i][strcspn(words[i], "\n")] = '\0';  // remove trailing newline
    }

    printf("Enter sentences to summarize: ");
    for (int i = 0; i < sentenceCount; i++) {
        fgets(words[i], MAX_LENGTH, stdin);
        words[i][strcspn(words[i], "\n")] = '\0';  // remove trailing newline
    }

    for (int i = 0; i < wordCount; i++) {
        if (strstr(text, words[i])) {
            printf("Word %s found in summary.\n", words[i]);
            summaryLength++;
        }
    }

    for (int i = 0; i < sentenceCount; i++) {
        if (strstr(text, words[i])) {
            printf("Sentence %s found in summary.\n", words[i]);
            sentenceLength++;
        }
    }

    printf("Summary length: %d\n", summaryLength);
    printf("Sentence length: %d\n", sentenceLength);

    return 0;
}