//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define MAX_WORDS 100

struct word {
    char *word;
    int count;
};

int compare(const void *a, const void *b) {
    struct word *w1 = (struct word *) a;
    struct word *w2 = (struct word *) b;

    return strcmp(w1->word, w2->word);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    char filename[MAX_SIZE];
    char line[MAX_SIZE];
    char word[MAX_SIZE];
    int i, j, k, word_count;
    struct word words[MAX_WORDS];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    for (i = 0; i < MAX_WORDS; i++) {
        words[i].word = (char *) malloc(MAX_SIZE * sizeof(char));
        words[i].count = 0;
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            word[k] = '\0';
            for (j = 0; j < i; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    break;
                }
            }
            if (j == i) {
                strcpy(words[i].word, word);
                words[i].count = 1;
                i++;
            }
            k = 0;
        } else {
            word[k++] = tolower(ch);
        }
    }

    fclose(fp);

    qsort(words, i, sizeof(struct word), compare);

    printf("Word\t\tFrequency\n");
    for (j = 0; j < i; j++) {
        printf("%s\t\t%d\n", words[j].word, words[j].count);
    }

    return 0;
}