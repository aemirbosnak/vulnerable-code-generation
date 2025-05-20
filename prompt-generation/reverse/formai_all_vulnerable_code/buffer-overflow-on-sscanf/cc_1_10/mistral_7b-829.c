//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 10001

typedef struct HashNode {
    int data;
    struct HashNode *next;
} HashNode;

unsigned int hash(int key) {
    return key % TABLE_SIZE;
}

HashNode* createNode(int data) {
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertHashTable(HashNode** hashTable, int data) {
    unsigned int index = hash(data);
    HashNode* newNode = createNode(data);

    if (*hashTable == NULL) {
        *hashTable = newNode;
    } else {
        HashNode* temp = *hashTable;

        while (temp->next != NULL && temp->next->data != data) {
            temp = temp->next;
        }

        if (temp->next == NULL && temp->data != data) {
            temp->next = newNode;
        } else {
            free(newNode);
        }
    }
}

void readCSVFile(const char* filename, HashNode** hashTable) {
    FILE* file = fopen(filename, "r");
    char line[1024];
    char* token;
    int num;

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%s%n", line, &num);

        for (int i = 0; i < num && *line != '\0'; ++i) {
            line[i] = (char)toupper((unsigned char)line[i]);
        }

        sscanf(line, "%d%n", &num, &num);
        insertHashTable(hashTable, num);
    }

    fclose(file);
}

int main() {
    HashNode* hashTable[TABLE_SIZE] = {NULL};
    const char* filename = "data.csv";

    readCSVFile(filename, hashTable);

    printf("Unique numbers:\n");

    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode* temp = hashTable[i];

        if (temp != NULL) {
            printf("%d ", temp->data);

            while (temp->next != NULL) {
                temp = temp->next;
                printf("%d ", temp->data);
            }

            printf("\n");
        }
    }

    return 0;
}