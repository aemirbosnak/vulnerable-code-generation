//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define ALPHABET_SIZE 26
#define HASH_SIZE 101

typedef struct Node {
    char ch;
    int count;
    struct Node *next;
} Node;

Node *hashTable[HASH_SIZE];

int hashFunction(char ch) {
    return (ch - 'a' + HASH_SIZE) % HASH_SIZE;
}

void insert(char ch) {
    int index = hashFunction(ch);
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void translate(char *str) {
    Node *currentNode;
    int index;
    char translatedStr[MAX_SIZE];
    strcpy(translatedStr, "");

    for (int i = 0; str[i] != '\0'; i++) {
        index = hashFunction(str[i]);
        currentNode = hashTable[index];

        while (currentNode != NULL) {
            if (currentNode->ch == str[i]) {
                int asciiValue = str[i] + (currentNode->count % ALPHABET_SIZE);
                translatedStr[i] = (char) asciiValue;
                break;
            }
            currentNode = currentNode->next;
        }
    }

    printf("Original String: %s\n", str);
    printf("Translated String: %s\n", translatedStr);
}

int main() {
    char inputStr[MAX_SIZE];

    printf("Enter a CAT string: ");
    scanf("%s", inputStr);

    for (int i = 0; inputStr[i] != '\0'; i++) {
        insert(inputStr[i]);
    }

    translate(inputStr);

    for (int i = 0; i < HASH_SIZE; i++) {
        Node *currentNode = hashTable[i];
        while (currentNode != NULL) {
            free(currentNode);
            currentNode = currentNode->next;
        }
    }

    return 0;
}