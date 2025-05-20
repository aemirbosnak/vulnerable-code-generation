//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 30
#define MIN_WORD_LENGTH 3

typedef struct {
    int frequency;
    char word[MAX_WORD_LENGTH];
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *w1 = (WordFrequency *)a;
    WordFrequency *w2 = (WordFrequency *)b;
    return w2->frequency - w1->frequency;
}

int isSpam(char *email) {
    FILE *fp;
    char ch;
    int count = 0;
    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening spam_words.txt\n");
        exit(1);
    }
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            count++;
        }
    }
    fclose(fp);
    if (count > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char email[1000];
    int i, j, k, n;
    char word[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    time_t now;
    FILE *fp;
    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening spam_words.txt\n");
        exit(1);
    }
    while (fscanf(fp, "%s", word)!= EOF) {
        words[i].frequency = 0;
        strcpy(words[i].word, word);
        i++;
    }
    fclose(fp);
    qsort(words, i, sizeof(WordFrequency), compareWords);
    printf("Enter email: ");
    scanf("%s", email);
    if (isSpam(email)) {
        printf("Email is spam\n");
    } else {
        printf("Email is not spam\n");
    }
    return 0;
}