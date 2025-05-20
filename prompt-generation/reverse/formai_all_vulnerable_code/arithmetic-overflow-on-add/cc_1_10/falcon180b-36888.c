//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void initWordCount(WordCount* wc) {
    strcpy(wc->word, "");
    wc->count = 0;
}

void addWord(WordCount* wc, char* word) {
    strcpy(wc->word, word);
    wc->count++;
}

void printWordCount(WordCount* wc) {
    printf("%s: %d\n", wc->word, wc->count);
}

void addWordToMap(char* word, int* map, int mapSize) {
    int index = tolower(word[0]) - 'a';
    if (index >= 0 && index < mapSize) {
        map[index]++;
    }
}

void printMap(int* map, int mapSize) {
    for (int i = 0; i < mapSize; i++) {
        printf("%c: %d\n", 'a' + i, map[i]);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    int map[26] = { 0 };
    WordCount wc;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("Warning: word '%s' is too long and will be truncated\n", word);
            strncpy(wc.word, word, MAX_WORD_LENGTH - 1);
            wc.word[MAX_WORD_LENGTH - 1] = '\0';
        } else {
            strcpy(wc.word, word);
        }

        addWordToMap(word, map, 26);
        addWord(&wc, word);
    }

    printMap(map, 26);
    printWordCount(&wc);

    fclose(file);
    return 0;
}