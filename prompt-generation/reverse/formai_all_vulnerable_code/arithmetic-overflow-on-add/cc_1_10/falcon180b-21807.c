//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void ReadWords(FILE *fp, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
        }
    }
}

void SpellCheck(FILE *fp, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        int j;
        for (j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s\n", word);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary> <text_file>\n", argv[0]);
        return 1;
    }
    FILE *dict = fopen(argv[1], "r");
    if (dict == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }
    WordCount words[MAX_WORDS];
    ReadWords(dict, words);
    fclose(dict);

    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Error: Could not open text file.\n");
        return 1;
    }
    SpellCheck(fp, words);
    fclose(fp);

    return 0;
}