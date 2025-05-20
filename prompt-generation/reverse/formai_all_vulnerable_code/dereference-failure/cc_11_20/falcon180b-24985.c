//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

struct Word {
    char *word;
    int count;
};

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    int i, j;
    struct Word words[MAX_WORDS];

    fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_WORDS; i++) {
        words[i].word = malloc(MAX_WORD_LENGTH);
        words[i].word[0] = '\0';
        words[i].count = 0;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, " ");

        while (token!= NULL) {
            for (j = 0; j < MAX_WORDS; j++) {
                if (strcmp(token, words[j].word) == 0) {
                    words[j].count++;
                    break;
                }
            }

            if (j == MAX_WORDS) {
                if (strlen(token) < MAX_WORD_LENGTH) {
                    strcpy(words[i].word, token);
                    words[i].count = 1;
                    i++;
                }
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    for (i = 0; i < MAX_WORDS; i++) {
        if (strlen(words[i].word) > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}