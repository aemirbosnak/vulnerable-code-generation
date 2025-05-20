//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_CHARS 100

typedef struct {
    char word[MAX_CHARS];
    char translation[MAX_CHARS];
} WordTranslation;

void loadDictionary(WordTranslation words[MAX_WORDS]) {
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(dictFile, "%s %s\n", words[numWords].word, words[numWords].translation) == 2) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: Dictionary file contains too many words.\n");
            exit(1);
        }
    }

    fclose(dictFile);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <text file>\n", argv[0]);
        exit(1);
    }

    FILE *textFile = fopen(argv[1], "r");
    if (textFile == NULL) {
        printf("Error: Could not open text file.\n");
        exit(1);
    }

    WordTranslation words[MAX_WORDS];
    loadDictionary(words);

    char line[MAX_CHARS];
    while (fgets(line, MAX_CHARS, textFile)!= NULL) {
        char *token = strtok(line, ",.?!;");
        while (token!= NULL) {
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    printf("%s ", words[i].translation);
                    break;
                }
            }
            if (i == MAX_WORDS) {
                printf("%s ", token);
            }
            token = strtok(NULL, ",.?!;");
        }
        printf("\n");
    }

    fclose(textFile);
    return 0;
}