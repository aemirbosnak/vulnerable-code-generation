//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LEN 50

typedef struct {
    char word[WORD_LEN];
    int count;
} word_t;

void toLowerCase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

int splitWord(char *str, word_t *words) {
    int index = 0;
    toLowerCase(str);
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            if (strcmp(words[i].word, str) == 0) {
                words[i].count++;
                return 1;
            }
        } else {
            strcpy(words[i].word, str);
            words[i].count++;
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *fp;
    char filename[100];
    char str[1024];
    word_t words[MAX_WORDS];

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(str, sizeof(str), fp) != NULL) {
        char *token = strtok(str, " \t\n");
        if (token != NULL) {
            int i;
            for (i = 0; i < MAX_WORDS && token != words[i].word; i++);
            if (i < MAX_WORDS) {
                words[i].count++;
            } else {
                int j;
                for (j = 0; j < MAX_WORDS; j++) {
                    if (words[j].count == 0) {
                        strcpy(words[j].word, token);
                        words[j].count++;
                        break;
                    }
                }
                if (j == MAX_WORDS) {
                    printf("Max number of words reached. Exiting...\n");
                    break;
                }
            }
        }
    }

    fclose(fp);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}