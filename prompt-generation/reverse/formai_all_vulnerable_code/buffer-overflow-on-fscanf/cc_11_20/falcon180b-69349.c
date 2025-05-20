//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define THRESHOLD 0.5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i, j;
    double probSpam;

    fp = fopen("spam.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open spam.txt\n");
        return 1;
    }

    while (fscanf(fp, "%s", line)!= EOF) {
        for (i = 0; i < numWords; i++) {
            if (strcmp(line, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many words in spam.txt\n");
                return 1;
            }
            strcpy(words[numWords].word, line);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(fp);

    fp = fopen("email.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open email.txt\n");
        return 1;
    }

    while (fscanf(fp, "%s", line)!= EOF) {
        probSpam = 0.0;
        for (i = 0; i < numWords; i++) {
            for (j = 0; j < strlen(line); j++) {
                if (line[j] == words[i].word[j]) {
                    probSpam += (double)words[i].count / (double)numWords;
                }
            }
        }
        if (probSpam >= THRESHOLD) {
            printf("Spam detected in email.txt\n");
        }
    }

    fclose(fp);

    return 0;
}