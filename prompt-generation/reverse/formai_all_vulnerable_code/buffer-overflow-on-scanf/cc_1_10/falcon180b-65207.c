//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

int isSpam(char *email) {
    char *words[MAX_WORDS];
    int numWords = 0;
    FILE *fp = fopen("spamWords.txt", "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            words[numWords++] = word;
            word = strtok(NULL, " ");
        }
    }
    fclose(fp);
    qsort(words, numWords, sizeof(char *), compareWords);
    int spamCount = 0;
    for (int i = 0; i < numWords; i++) {
        if (strstr(email, words[i])!= NULL) {
            spamCount++;
        }
    }
    if (spamCount >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char email[MAX_WORD_LENGTH];
    printf("Enter email address: ");
    scanf("%s", email);
    if (isSpam(email)) {
        printf("Email is spam.\n");
    } else {
        printf("Email is not spam.\n");
    }
    return 0;
}