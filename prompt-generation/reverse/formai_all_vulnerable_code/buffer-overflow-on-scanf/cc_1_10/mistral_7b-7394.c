//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#define MIN_SIZE 1
#define MAX_SIZE 10000

typedef struct {
    int key;
    void* data;
    struct Node* next;
} Node;

Node* createNode(int key, void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createList(int size, int* keys, void* data) {
    Node* head = NULL;
    for (int i = 0; i < size; i++) {
        if (!head) {
            head = createNode(keys[i], NULL);
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = createNode(keys[i], NULL);
        }
    }
    for (int i = 0; i < size; i++) {
        if (keys[i] == searchList(head, data)) {
            printf("Element %p found at index %d.\n", data, i);
            break;
        }
    }
    if (searchList(head, data) == -1) {
        printf("Element %p not found.\n", data);
    }
    free(head);
    return NULL;
}

int searchList(Node* head, void* data) {
    Node* current = head;
    int index = -1;
    while (current) {
        if (current->key == *(int*)data && current->data == data) {
            index = (int)(current - head);
            break;
        }
        current = current->next;
    }
    return index;
}

int main() {
    int size, key;
    void* data;
    int* keys;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    if (size < MIN_SIZE || size > MAX_SIZE) {
        printf("Size out of range.\n");
        return 1;
    }

    keys = (int*)calloc(size, sizeof(int));
    if (!keys) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &key);
        keys[i] = key;
    }

    printf("Enter the data to search for: ");
    scanf("%p", &data);

    createList(size, keys, data);

    free(keys);
    return 0;
}