//Falcon-180B DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int size) {
    Node* head = NULL;
    Node* curr = NULL;
    int i;

    for (i = 0; i < size; i++) {
        curr = (Node*) malloc(sizeof(Node));
        curr->data = i;
        curr->next = NULL;

        if (head == NULL) {
            head = curr;
        }
        else {
            Node* temp = head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = curr;
        }
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void deleteLinkedList(Node* head) {
    Node* curr = head;
    while (curr!= NULL) {
        Node* temp = curr->next;
        free(curr);
        curr = temp;
    }
}

int main() {
    int size;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    Node* head = createLinkedList(size);
    printLinkedList(head);

    deleteLinkedList(head);

    return 0;
}