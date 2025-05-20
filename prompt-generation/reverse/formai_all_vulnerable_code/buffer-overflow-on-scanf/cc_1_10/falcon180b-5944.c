//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_KEY_SIZE 20

// Node structure for linked list
struct Node {
    int key;
    int value;
    struct Node* next;
};

void createList(struct Node** head, int size);
void printList(struct Node* head);
void searchList(struct Node* head, int key);

int main() {
    struct Node* head = NULL;
    int size;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }

    srand(time(NULL));
    createList(&head, size);
    printList(head);

    int searchKey;
    printf("Enter the key to search: ");
    scanf("%d", &searchKey);

    searchList(head, searchKey);

    return 0;
}

void createList(struct Node** head, int size) {
    *head = NULL;

    for (int i = 0; i < size; i++) {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->key = rand() % MAX_KEY_SIZE;
        newNode->value = i;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            struct Node* temp = *head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;

    while (temp!= NULL) {
        printf("Key: %d, Value: %d\n", temp->key, temp->value);
        temp = temp->next;
    }
}

void searchList(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp!= NULL) {
        if (temp->key == key) {
            printf("Found key: %d\n", key);
            return;
        }
        temp = temp->next;
    }

    printf("Key not found.\n");
}