//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10001
#define MAX_STRING_LENGTH 100

typedef struct HashNode {
    char key[MAX_STRING_LENGTH];
    int value;
    struct HashNode* next;
} HashNode;

HashNode* table[TABLE_SIZE];

unsigned long hash(char* key) {
    unsigned long hash = 5381;
    int i;
    for (i = 0; i < strlen(key); i++)
        hash = ((hash << 5) + hash) + key[i]; /* hash * 33 + c */
    return hash % TABLE_SIZE;
}

void insert(char* key, int value) {
    int index = hash(key);
    HashNode* newNode = (HashNode*) malloc(sizeof(HashNode));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

int find(char* key) {
    int index = hash(key);
    HashNode* current = table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }
    return -1;
}

int main(void) {
    char str[MAX_STRING_LENGTH];
    int i, value;

    for (i = 0; i < 10000; i++) {
        printf("Enter a string and a value: ");
        scanf("%s %d", str, &value);
        insert(str, value);
    }

    printf("Enter a string to search for: ");
    scanf("%s", str);

    value = find(str);

    if (value == -1)
        printf("String not found.\n");
    else
        printf("Value for string '%s' is %d.\n", str, value);

    return 0;
}