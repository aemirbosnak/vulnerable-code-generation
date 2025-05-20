//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    int frequency;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->frequency = 1;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    }
    struct Node* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = createNode(data);
    return head;
}

struct Node* searchNode(struct Node* head, int data) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE];
    int n;
    printf("Enter the size of the list: ");
    scanf("%d", &n);
    printf("Enter the list elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        head = insertNode(head, list[i]);
    }
    printf("Enter the number to search: ");
    int search;
    scanf("%d", &search);
    struct Node* result = searchNode(head, search);
    if (result == NULL) {
        printf("Element not found.\n");
    } else {
        printf("Element found.\n");
        printf("Frequency: %d\n", result->frequency);
    }
    return 0;
}