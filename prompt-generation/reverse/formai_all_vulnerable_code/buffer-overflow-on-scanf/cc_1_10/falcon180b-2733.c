//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10000

struct node {
    char word[100];
    int count;
};

struct node *hashTable[MAX_SIZE];

int hashFunction(char *word) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(word); i++) {
        sum += tolower(word[i]);
    }
    return sum % MAX_SIZE;
}

void insertWord(char *word) {
    int index = hashFunction(word);
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    hashTable[index] = newNode;
}

void printWords() {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (hashTable[i]!= NULL) {
            printf("%s %d\n", hashTable[i]->word, hashTable[i]->count);
        }
    }
}

int main() {
    char word[100];
    char fileName[100];
    FILE *file;
    int i, count;

    printf("Enter the name of the file: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("File not found\n");
        exit(0);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        count = 0;
        for (i = 0; i < strlen(word); i++) {
            if (isalpha(word[i])) {
                count++;
            }
        }
        if (count > 0) {
            insertWord(word);
        }
    }

    fclose(file);

    printf("The words in the file are:\n");
    printWords();

    return 0;
}