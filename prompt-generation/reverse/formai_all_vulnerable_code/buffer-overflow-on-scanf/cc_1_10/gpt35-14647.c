//FormAI DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* insert(Node* head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    Node* current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void delete(Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    int choice = 0;
    do {
        printf("Choose an option:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int data;
                printf("Enter the data: ");
                scanf("%d", &data);
                head = insert(head, data);
                break;
            }
            case 2:
                delete(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}