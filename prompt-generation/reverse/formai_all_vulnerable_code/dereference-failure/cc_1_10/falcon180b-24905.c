//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

char *get_word(char *str) {
    int len = 0;
    char *word = NULL;
    char *p = str;
    while (isspace(*p)) {
        p++;
    }
    while (!isspace(*p)) {
        len++;
        p++;
    }
    word = malloc(len + 1);
    if (word == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strncpy(word, str, len);
    word[len] = '\0';
    return word;
}

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *fp;
    char line[MAX_LEN];
    char *word;
    int i = 0;
    int j = 0;
    char **words = NULL;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LEN, fp)!= NULL) {
        word = get_word(line);
        if (i == 0) {
            words = malloc(sizeof(char *));
            if (words == NULL) {
                printf("Memory error\n");
                exit(1);
            }
            words[j] = word;
            j++;
        } else {
            words = realloc(words, sizeof(char *) * (j + 1));
            if (words == NULL) {
                printf("Memory error\n");
                exit(1);
            }
            words[j] = word;
            j++;
        }
        i++;
    }

    fclose(fp);

    qsort(words, j, sizeof(char *), compare);

    for (i = 0; i < j; i++) {
        printf("%s\n", words[i]);
    }

    for (i = 0; i < j; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}