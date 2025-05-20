//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HASH_SIZE 256

typedef struct HashNode {
    char *key;
    struct HashNode *next;
} HashNode;

HashNode *insert(HashNode *head, char *key) {
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        HashNode *traversing = head;
        while (traversing->next) {
            traversing = traversing->next;
        }
        traversing->next = newNode;
    }

    return head;
}

char *hashFunction(char *str) {
    int hashValue = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hashValue = (hashValue * 33) + str[i];
    }

    char *hash = malloc(HASH_SIZE);
    sprintf(hash, "%x", hashValue);

    return hash;
}

int main() {
    char *str = "A deer of a gentle heart";
    char *hash = hashFunction(str);
    printf("Hash of '%s': %s\n", str, hash);

    free(hash);

    return 0;
}