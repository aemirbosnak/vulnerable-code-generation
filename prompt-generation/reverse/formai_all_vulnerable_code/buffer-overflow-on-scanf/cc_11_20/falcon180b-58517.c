//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 1000
#define MIN_WORD_LENGTH 3
#define MAX_SPAM_THRESHOLD 0.5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char inputText[100000];
    char word[MAX_WORD_LENGTH];
    int i, j, wordCount, isSpam;
    WordCount wordList[MAX_WORD_COUNT];
    double spamThreshold;

    printf("Enter the path to the text file: ");
    scanf("%s", inputText);

    file = fopen(inputText, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    wordCount = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LENGTH) {
            for (i = 0; i < wordCount; i++) {
                if (strcmp(wordList[i].word, word) == 0) {
                    wordList[i].count++;
                    break;
                }
            }
            if (i == wordCount) {
                strcpy(wordList[wordCount].word, word);
                wordList[wordCount].count = 1;
                wordCount++;
            }
        }
    }
    fclose(file);

    printf("Enter the spam threshold (0.0 - 1.0): ");
    scanf("%lf", &spamThreshold);

    isSpam = 0;
    for (i = 0; i < wordCount; i++) {
        if (wordList[i].count >= MAX_WORD_COUNT) {
            isSpam = 1;
            break;
        }
    }

    if (isSpam == 0) {
        for (i = 0; i < wordCount; i++) {
            spamThreshold -= wordList[i].count / (double)MAX_WORD_COUNT;
        }
        if (spamThreshold > 0) {
            isSpam = 1;
        }
    }

    if (isSpam) {
        printf("The text is likely spam.\n");
    } else {
        printf("The text is likely not spam.\n");
    }

    return 0;
}