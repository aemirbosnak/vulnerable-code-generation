//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtTail(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Multiplayer operations
    while (1) {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);

        if (data == -1) {
            break;
        }

        head = insertAtTail(head, data);
    }

    printList(head);

    return 0;
}