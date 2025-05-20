//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data);
void printList(struct Node* node);
void deleteList(struct Node **head_ref);

int main(int argc, char *argv[]) {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n");
        printf("1. Push\n");
        printf("2. Print List\n");
        printf("3. Delete List\n");
        printf("4. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(&head, data);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                deleteList(&head);
                head = NULL;
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else {
        while (last->next!= *head_ref) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = *head_ref;
    }
}

void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

void deleteList(struct Node **head_ref) {
    struct Node* temp = *head_ref;

    while (temp!= NULL) {
        *head_ref = temp->next;
        free(temp);
        temp = *head_ref;
    }
}