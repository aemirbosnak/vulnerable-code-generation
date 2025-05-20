//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void createList(struct Node** headRef) {
    struct Node* head = NULL;
    struct Node* current = NULL;
    int num, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &(current->data));
        current->next = NULL;

        if (head == NULL) {
            head = current;
        } else {
            current->next = head;
            head = current;
        }
        current = current->next;
    }

    *headRef = head;
}

void displayList(struct Node* head) {
    struct Node* current = head;

    printf("List: ");
    while (current!= NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteList(struct Node** headRef) {
    struct Node* temp = NULL;
    struct Node* current = *headRef;

    while (current!= NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }

    *headRef = NULL;
}

int main() {
    struct Node* head;

    createList(&head);
    displayList(head);
    deleteList(&head);

    return 0;
}