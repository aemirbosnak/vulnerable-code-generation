//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

//Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

//Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Function to add a node at the end of the list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;

    return;
}

//Function to search for an element in the linked list
int search(struct Node* head, int x) {
    struct Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return 1;
        current = current->next;
    }
    return 0;
}

//Function to print the linked list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n");
        printf("1. Add element\n");
        printf("2. Search element\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &data);
                push(&head, data);
                break;
            case 2:
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                if (search(head, data))
                    printf("%d found!\n", data);
                else
                    printf("%d not found.\n", data);
                break;
            case 3:
                printf("List: ");
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}