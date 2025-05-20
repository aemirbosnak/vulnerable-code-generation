//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define SPAM_THRESHOLD 0.8

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int isSpam(const char *email) {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int totalWords = 0, spamWords = 0;
    WordCount words[MAX_WORDS];

    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening spam_words.txt\n");
        return 0;
    }

    while (fscanf(fp, "%s", line)!= EOF) {
        strcpy(word, line);
        tolower(word);
        totalWords++;
    }

    fclose(fp);

    fp = fopen(email, "r");
    if (fp == NULL) {
        printf("Error opening email\n");
        return 0;
    }

    while (fscanf(fp, "%s", line)!= EOF) {
        strcpy(word, line);
        tolower(word);

        if (strlen(word) > MAX_WORD_LENGTH) {
            continue;
        }

        int found = 0;
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[totalWords].word, word);
            words[totalWords].count = 1;
            totalWords++;
        }
    }

    fclose(fp);

    qsort(words, totalWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < totalWords; i++) {
        if (words[i].count > (totalWords * SPAM_THRESHOLD)) {
            spamWords++;
        }
    }

    return spamWords > 0;
}

int main() {
    char email[MAX_WORD_LENGTH];
    printf("Enter email: ");
    scanf("%s", email);

    if (isSpam(email)) {
        printf("Spam\n");
    } else {
        printf("Not spam\n");
    }

    return 0;
}