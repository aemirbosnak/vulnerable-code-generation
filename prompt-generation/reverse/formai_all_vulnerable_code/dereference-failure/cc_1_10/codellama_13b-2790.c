//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: complete
// Linked list operations example program

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printList(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct node* createList(int arr[], int n) {
    struct node *head = NULL;
    struct node *prev = NULL;
    for (int i = 0; i < n; i++) {
        struct node *newNode = (struct node*) malloc(sizeof(struct node));
        newNode->data = arr[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
    }
    return head;
}

struct node* reverseList(struct node *head) {
    struct node *prev = NULL;
    struct node *curr = head;
    while (curr != NULL) {
        struct node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct node *head = createList(arr, n);
    printList(head);
    head = reverseList(head);
    printList(head);
    return 0;
}