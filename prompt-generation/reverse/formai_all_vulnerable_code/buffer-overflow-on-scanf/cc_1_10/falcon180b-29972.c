//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverseList(Node *head) {
    Node *prev = NULL;
    Node *curr = head;
    while (curr!= NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    Node *head = NULL;
    int choice, data;

    while (1) {
        printf("Enter the size of the linked list (max %d): ", MAX_SIZE);
        scanf("%d", &choice);
        if (choice <= 0 || choice > MAX_SIZE) {
            printf("Invalid input. Please try again.\n");
        } else {
            break;
        }
    }

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < choice; i++) {
        scanf("%d", &data);
        head = createNode(data);
        if (i == 0) {
            head = head->next;
        }
    }

    printf("Original linked list:\n");
    printList(head);

    printf("Reversed linked list:\n");
    reverseList(head);
    printList(head);

    return 0;
}