//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 10000

typedef struct HashNode {
    char *word;
    int count;
    struct HashNode *next;
} HashNode;

HashNode *hashTable[TABLE_SIZE];

int hashFunc(char *str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++)
        hash = (hash * 31 + str[i]) % TABLE_SIZE;
    return hash;
}

void insertWord(char *word) {
    int index = hashFunc(word);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));

    if (hashTable[index] == NULL) {
        newNode->word = (char *)malloc((strlen(word) + 1) * sizeof(char));
        strcpy(newNode->word, word);
        newNode->count = 1;
        newNode->next = NULL;
        hashTable[index] = newNode;
    } else {
        HashNode *current = hashTable[index];
        while (current != NULL) {
            if (strcmp(current->word, word) == 0) {
                current->count++;
                free(newNode);
                return;
            }
            current = current->next;
        }

        newNode->word = (char *)malloc((strlen(word) + 1) * sizeof(char));
        strcpy(newNode->word, word);
        newNode->count = 1;
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

void readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", fileName);
        return;
    }

    char line[1024];
    char *token;

    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, " ,.\t\n");
        while (token != NULL) {
            if (isalpha(token[0])) {
                token[0] = toupper(token[0]);
                insertWord(token);
            }
            token = strtok(NULL, " ,.\t\n");
        }
    }

    fclose(file);
}

int main() {
    char fileName[128];

    printf("Enter the name of the text file: ");
    scanf("%s", fileName);

    readFile(fileName);

    printf("\nWords starting with the letter 'C' and their frequencies:\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            HashNode *current = hashTable[i];
            while (current != NULL) {
                if (current->word[0] == 'C')
                    printf("%s: %d\n", current->word, current->count);
                current = current->next;
            }
        }
    }

    return 0;
}