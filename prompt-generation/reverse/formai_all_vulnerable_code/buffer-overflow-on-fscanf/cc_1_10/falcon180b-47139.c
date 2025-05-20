//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define THRESHOLD 0.8

typedef struct {
    char *word;
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

int isSpam(char *email) {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char *word;
    int count = 0;
    WordCount *wordCounts = malloc(MAX_WORDS * sizeof(WordCount));

    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening spam_words.txt\n");
        exit(1);
    }

    while (fscanf(fp, "%s", line)!= EOF) {
        word = strtok(line, " ");
        while (word!= NULL) {
            WordCount *wc = bsearch(word, wordCounts, count, sizeof(WordCount), compare);
            if (wc == NULL) {
                wc = realloc(wordCounts, sizeof(WordCount) * (count + 1));
                wc[count].word = strdup(word);
                wc[count].count = 1;
                wordCounts = wc;
                count++;
            } else {
                wc->count++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    int spamCount = 0;
    for (int i = 0; i < count; i++) {
        if (wordCounts[i].count >= THRESHOLD * count) {
            spamCount++;
        }
    }

    free(wordCounts);

    return spamCount > 0;
}

int main() {
    char email[MAX_WORD_LENGTH];

    printf("Enter email: ");
    scanf("%s", email);

    if (isSpam(email)) {
        printf("Email is spam\n");
    } else {
        printf("Email is not spam\n");
    }

    return 0;
}