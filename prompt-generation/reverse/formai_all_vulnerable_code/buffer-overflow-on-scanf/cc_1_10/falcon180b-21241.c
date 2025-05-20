//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50
#define MAX_QUERIES 10

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void ReadWords(char *filename, WordFrequency *words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[0].word, word);
            words[0].count = 1;
        }
    }

    fclose(fp);
}

void DisplayWords(WordFrequency *words) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char filename[50];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    WordFrequency words[MAX_WORDS];
    ReadWords(filename, words);

    int num_queries;
    printf("Enter the number of queries: ");
    scanf("%d", &num_queries);

    char query[MAX_WORD_LEN];
    int i;
    for (i = 0; i < num_queries; i++) {
        printf("Enter query %d: ", i+1);
        scanf("%s", query);

        int found = 0;
        for (int j = 0; j < MAX_WORDS; j++) {
            if (strcmp(query, words[j].word) == 0) {
                printf("%s: %d\n", query, words[j].count);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Word not found.\n");
        }
    }

    return 0;
}