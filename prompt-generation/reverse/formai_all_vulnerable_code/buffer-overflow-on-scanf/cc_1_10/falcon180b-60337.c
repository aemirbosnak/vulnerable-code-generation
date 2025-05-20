//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createLinkedList(int size, int* arr) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < size; i++) {
        Node* newNode = createNode(arr[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

Node* search(Node* head, int target) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == target) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    Node* linkedList = createLinkedList(size, arr);

    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    Node* result = search(linkedList, target);

    if (result == NULL) {
        printf("Element not found in the linked list.\n");
    } else {
        printf("Element found in the linked list.\n");
        printLinkedList(linkedList);
    }

    return 0;
}