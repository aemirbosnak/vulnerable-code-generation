//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // maximum size of the array

struct node {
    int data;
    struct node* next;
};

void insertNode(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct node* createLinkedList(int arr[], int size) {
    struct node* head = NULL;
    for (int i = 0; i < size; i++) {
        insertNode(&head, arr[i]);
    }
    return head;
}

void printLinkedList(struct node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void searchElement(struct node* head, int target) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (temp->data == target) {
            printf("Element found at position %d\n", temp->data);
            return;
        }
        temp = temp->next;
    }
    printf("Element not found in the linked list\n");
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct node* head = createLinkedList(arr, size);
    printf("Linked list: ");
    printLinkedList(head);

    int target = 9;
    searchElement(head, target);

    return 0;
}