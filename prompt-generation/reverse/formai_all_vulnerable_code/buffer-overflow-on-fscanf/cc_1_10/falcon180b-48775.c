//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int numWords = 0;

void addWord(char* word) {
    if (numWords >= MAX_WORDS) {
        printf("Error: maximum number of words reached\n");
        exit(1);
    }

    strcpy(words[numWords].word, word);
    words[numWords].count = 1;
    numWords++;
}

void loadDictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        addWord(word);
    }

    fclose(file);
}

int isWord(char* word) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (strcmp(word, words[i].word) == 0) {
            return 1;
        }
    }
    return 0;
}

void spellCheck(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            if (isWord(word) == 0) {
                printf("%s\n", word);
            }
            word = strtok(NULL, ",.!?;:");
        }
    }

    fclose(file);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <dictionary> <file>\n", argv[0]);
        exit(1);
    }

    loadDictionary(argv[1]);
    spellCheck(argv[2]);

    return 0;
}