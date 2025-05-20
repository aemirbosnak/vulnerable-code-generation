//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define HASH_SIZE 1024

typedef struct Node {
    char data[HASH_SIZE];
    struct Node* next;
} Node;

void hash_insert(Node* head, char* data) {
    int hash = hash_function(data);
    Node* newNode = malloc(sizeof(Node));
    newNode->data[0] = data[0];
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int hash_function(char* data) {
    int hash = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        hash = (hash * 33) + data[i];
    }
    return hash % HASH_SIZE;
}

int main() {
    Node* head = NULL;
    char* data = "Hello, world!";

    hash_insert(head, data);

    Node* current = head;
    while (current) {
        printf("%s\n", current->data);
        current = current->next;
    }

    return 0;
}