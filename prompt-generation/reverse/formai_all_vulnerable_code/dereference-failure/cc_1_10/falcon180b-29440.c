//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct node {
    int key;
    int value;
    struct node *next;
} Node;

Node *hashTable[MAX_SIZE];
int hash(int key) {
    return key % MAX_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(int key) {
    int index = hash(key);
    Node *curr = hashTable[index];
    while (curr!= NULL) {
        if (curr->key == key) {
            return curr->value;
        }
        curr = curr->next;
    }
    return -1;
}

void delete(int key) {
    int index = hash(key);
    Node *curr = hashTable[index];
    Node *prev = NULL;
    while (curr!= NULL && curr->key!= key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        return;
    }
    if (prev == NULL) {
        hashTable[index] = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}

int main() {
    int choice, key, value;
    while (1) {
        printf("1. Insert\n2. Search\n3. Delete\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                value = search(key);
                if (value == -1) {
                    printf("Key not found\n");
                } else {
                    printf("Value: %d\n", value);
                }
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}