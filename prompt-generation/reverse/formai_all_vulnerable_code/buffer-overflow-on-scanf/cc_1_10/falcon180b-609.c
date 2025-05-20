//Falcon-180B DATASET v1.0 Category: Error handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* insert_at_end(Node* head, int data) {
    Node* new_node = create_node(data);
    Node* temp = head;
    if (head == NULL) {
        head = new_node;
        return head;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

void display_list(Node* head) {
    Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Insert element at the end\n");
        printf("2. Display list\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                head = insert_at_end(head, data);
                break;
            case 2:
                display_list(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}