//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    if (wc1->count > wc2->count)
        return -1;
    else if (wc1->count < wc2->count)
        return 1;
    else
        return 0;
}

int main() {
    FILE *fp;
    char ch, word[MAX_WORD_LENGTH];
    int i = 0, j, k, n;
    WordCount words[MAX_WORDS];

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            word[i] = tolower(ch);
            i++;
        } else {
            word[i] = '\0';
            i = 0;

            for (j = 0; j < k; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    break;
                }
            }

            if (j == k) {
                strcpy(words[k].word, word);
                words[k].count = 1;
                k++;
            }
        }
    }

    qsort(words, k, sizeof(WordCount), compare);

    printf("Word\t\tFrequency\n");
    for (n = 0; n < k; n++) {
        printf("%s\t\t%d\n", words[n].word, words[n].count);
    }

    fclose(fp);
    return 0;
}