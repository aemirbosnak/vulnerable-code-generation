//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* head = NULL;
    int choice, num, i;
    char* option = "y\n";
    printf("Welcome to the Multiplayer Game!\n");

    while (1) {
        printf("Enter your choice:\n1. Insert a number\n2. Delete a number\n3. Display the list\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &num);
                push(&head, num);
                break;
            case 2:
                if (head == NULL) {
                    printf("List is empty\n");
                } else {
                    printf("Enter a number to delete: ");
                    scanf("%d", &num);
                    struct Node* temp = head;
                    while (temp->next!= NULL && temp->next->data!= num) {
                        temp = temp->next;
                    }
                    if (temp->next == NULL) {
                        printf("Number not found\n");
                    } else {
                        temp->next = temp->next->next;
                        free(temp->next);
                        temp->next = NULL;
                    }
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("List is empty\n");
                } else {
                    struct Node* temp = head;
                    while (temp!= NULL) {
                        printf("%d\n", temp->data);
                        temp = temp->next;
                    }
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}