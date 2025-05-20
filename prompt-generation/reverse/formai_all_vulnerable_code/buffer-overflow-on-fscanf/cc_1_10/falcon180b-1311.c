//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HASH_SIZE 1000
#define BUFFER_SIZE 10000

typedef struct {
    char word[20];
    int count;
} WordCount;

typedef struct {
    char word[20];
    bool isCorrect;
} CorrectWord;

typedef struct {
    CorrectWord correctWords[10000];
    int numCorrectWords;
} Dictionary;

typedef struct {
    char word[20];
    int hashValue;
} HashEntry;

HashEntry hashTable[HASH_SIZE];
char inputBuffer[BUFFER_SIZE];
int inputIndex = 0;
int hashValue;

void buildHashTable(Dictionary dict) {
    for (int i = 0; i < dict.numCorrectWords; i++) {
        hashValue = dict.correctWords[i].word[0] % HASH_SIZE;
        HashEntry entry;
        strcpy(entry.word, dict.correctWords[i].word);
        entry.hashValue = hashValue;
        hashTable[hashValue] = entry;
    }
}

void processWord(char word[20]) {
    hashValue = word[0] % HASH_SIZE;
    HashEntry entry = hashTable[hashValue];
    while (entry.word[0]!= '\0') {
        if (strcmp(entry.word, word) == 0) {
            printf("%s is spelled correctly.\n", word);
            return;
        }
        entry = hashTable[++hashValue % HASH_SIZE];
    }
    printf("%s is not in the dictionary.\n", word);
}

int main() {
    FILE *dictFile;
    Dictionary dict;
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }
    int numCorrectWords = 0;
    while (fscanf(dictFile, "%s", dict.correctWords[numCorrectWords].word)!= EOF) {
        numCorrectWords++;
        if (numCorrectWords == 10000) {
            break;
        }
    }
    fclose(dictFile);
    buildHashTable(dict);
    printf("Enter text to spell check:\n");
    fgets(inputBuffer, BUFFER_SIZE, stdin);
    char word[20];
    char *token = strtok(inputBuffer, ",.?!;:");
    while (token!= NULL) {
        strcpy(word, token);
        processWord(word);
        token = strtok(NULL, ",.?!;:");
    }
    return 0;
}