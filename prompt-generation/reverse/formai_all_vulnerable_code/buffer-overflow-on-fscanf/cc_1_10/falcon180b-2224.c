//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wordA = (const WordCount*)a;
    const WordCount* wordB = (const WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

int isSpam(char* emailContent) {
    FILE* spamWordsFile = fopen("spam_words.txt", "r");
    if (spamWordsFile == NULL) {
        printf("Error opening spam_words.txt\n");
        return -1;
    }

    WordCount spamWords[MAX_WORDS];
    int numSpamWords = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(spamWordsFile, "%s", word)!= EOF) {
        if (numSpamWords >= MAX_WORDS) {
            printf("Too many spam words\n");
            fclose(spamWordsFile);
            return -1;
        }

        spamWords[numSpamWords].word[0] = tolower(word[0]);
        strncpy(spamWords[numSpamWords].word + 1, word + 1, MAX_WORD_LENGTH - 1);
        spamWords[numSpamWords].count = 0;
        numSpamWords++;
    }

    fclose(spamWordsFile);

    char* tokens = strtok(emailContent, " ");
    while (tokens!= NULL) {
        int i;
        for (i = 0; i < numSpamWords; i++) {
            if (strcmp(tokens, spamWords[i].word) == 0) {
                spamWords[i].count++;
                break;
            }
        }

        tokens = strtok(NULL, " ");
    }

    qsort(spamWords, numSpamWords, sizeof(WordCount), compareWords);

    int totalSpamWords = 0;
    for (int i = 0; i < numSpamWords; i++) {
        totalSpamWords += spamWords[i].count;
    }

    if (totalSpamWords >= 5) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char emailContent[10000];
    printf("Enter email content: ");
    fgets(emailContent, sizeof(emailContent), stdin);

    int isSpamResult = isSpam(emailContent);

    if (isSpamResult == -1) {
        printf("Error detecting spam\n");
    } else if (isSpamResult == 1) {
        printf("Email is spam\n");
    } else {
        printf("Email is not spam\n");
    }

    return 0;
}