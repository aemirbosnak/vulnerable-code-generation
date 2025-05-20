//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void loadDictionary(WordFrequency *dictionary, int maxSize) {
    FILE *file = fopen(DICTIONARY_FILE, "r");

    if (file == NULL) {
        printf("Error: unable to open dictionary file.\n");
        exit(1);
    }

    int count = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= maxSize) {
            break;
        }
        dictionary[count].word[0] = toupper(word[0]);
        strcpy(&dictionary[count].word[1], &word[1]);
        dictionary[count].frequency = 1;
        count++;
    }

    fclose(file);
}

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    if (strcmp(wordA->word, wordB->word) == 0) {
        return 0;
    } else if (strcmp(wordA->word, wordB->word) < 0) {
        return -1;
    } else {
        return 1;
    }
}

void spellCheck(char *text, WordFrequency *dictionary, int maxSize) {
    char word[MAX_WORD_LENGTH];
    int wordLength;
    char *token;
    int i;

    token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        wordLength = strlen(token);
        if (wordLength > 0 && isalpha(token[0])) {
            strcpy(word, token);
            word[0] = toupper(word[0]);

            qsort(dictionary, maxSize, sizeof(WordFrequency), compareWords);

            i = 0;
            while (i < maxSize && strcmp(dictionary[i].word, word)!= 0) {
                i++;
            }

            if (i == maxSize) {
                printf("Possible spelling mistake: %s\n", token);
            }
        }
        token = strtok(NULL, ",.?!;:");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: unable to open file.\n");
        return 1;
    }

    char text[1000000];
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    fread(text, fileSize, 1, file);
    fclose(file);

    WordFrequency dictionary[MAX_DICTIONARY_SIZE];
    loadDictionary(dictionary, MAX_DICTIONARY_SIZE);

    spellCheck(text, dictionary, MAX_DICTIONARY_SIZE);

    return 0;
}