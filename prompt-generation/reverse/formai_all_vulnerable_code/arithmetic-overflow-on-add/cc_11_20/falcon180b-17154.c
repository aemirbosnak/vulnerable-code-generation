//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

int main() {
    int n, i, j;
    char line[MAX_WORD_LEN];
    Word words[MAX_WORDS];
    FILE *fp;

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read input file
    n = 0;
    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        int len = strlen(line);
        for (i = 0; i < len; i++) {
            if (isalpha(line[i])) {
                line[i] = tolower(line[i]);
            } else {
                line[i] = '\0';
            }
        }
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, line) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            strcpy(words[n].word, line);
            words[n].count = 1;
            n++;
            if (n == MAX_WORDS) {
                printf("Maximum number of words reached\n");
                fclose(fp);
                return 1;
            }
        }
    }

    // Sort words by frequency
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (words[i].count < words[j].count) {
                strcpy(words[i].word, words[j].word);
                words[i].count = words[j].count;
                strcpy(words[j].word, words[i].word);
                words[j].count = words[i].count;
            }
        }
    }

    // Write output file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening output file\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s %d\n", words[i].word, words[i].count);
    }
    fclose(fp);

    return 0;
}