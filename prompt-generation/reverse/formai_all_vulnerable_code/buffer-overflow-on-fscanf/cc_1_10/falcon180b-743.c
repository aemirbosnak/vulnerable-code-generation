//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 100

struct word {
    char word[MAX_WORD_LEN];
    int length;
};

struct word words[MAX_WORDS];
int num_words;

void load_words(char *filename) {
    FILE *fp;
    char word[MAX_WORD_LEN];
    int length;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    num_words = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        length = strlen(word);
        if (length > MAX_WORD_LEN) {
            printf("Word '%s' is too long\n", word);
            continue;
        }
        strcpy(words[num_words].word, word);
        words[num_words].length = length;
        num_words++;
    }

    fclose(fp);
}

void search_words(char *query) {
    int i;
    int query_length = strlen(query);
    int max_results = 10;
    int results_found = 0;

    for (i = 0; i < num_words; i++) {
        if (strstr(words[i].word, query)!= NULL) {
            if (results_found >= max_results) {
                break;
            }
            printf("%s\n", words[i].word);
            results_found++;
        }
    }

    if (results_found == 0) {
        printf("No results found\n");
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    load_words(filename);

    char query[100];
    printf("Enter search query: ");
    scanf("%s", query);

    search_words(query);

    return 0;
}