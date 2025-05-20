//FormAI DATASET v1.0 Category: Linked list operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

void addFront(node** head_ref, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void addEnd(node** head_ref, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void addAt(node** head_ref, int data, int position) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;

    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    node* prev_node = *head_ref;
    int i;
    for (i = 0; prev_node != NULL && i < position - 1; i++) {
        prev_node = prev_node->next;
    }

    if (prev_node == NULL) {
        printf("Invalid position\n");
        return;
    }

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void deleteFront(node** head_ref) {
    node* temp_node = *head_ref;
    *head_ref = temp_node->next;
    free(temp_node);
}

void deleteEnd(node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }

    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    node* last_node = *head_ref;
    node* prev_node = NULL;

    while (last_node->next != NULL) {
        prev_node = last_node;
        last_node = last_node->next;
    }

    free(last_node);
    prev_node->next = NULL;
}

void deleteAt(node** head_ref, int position) {
    if (*head_ref == NULL) {
        return;
    }

    node* temp_node = *head_ref;
    if (position == 0) {
        *head_ref = temp_node->next;
        free(temp_node);
        return;
    }

    int i;
    for (i = 0; temp_node != NULL && i < position - 1; i++) {
        temp_node = temp_node->next;
    }

    if (temp_node == NULL || temp_node->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    node* next_node = temp_node->next->next;
    free(temp_node->next);
    temp_node->next = next_node;
}

void printList(node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;

    int choice, data, position;
    while (1) {
        printf("1. Add to front\n");
        printf("2. Add to end\n");
        printf("3. Add at position\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete at position\n");
        printf("7. Print list\n");
        printf("8. Exit\n");

        printf("Enter choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add to front:\n");
                scanf("%d", &data);
                addFront(&head, data);
                break;
            case 2:
                printf("Enter data to add to end:\n");
                scanf("%d", &data);
                addEnd(&head, data);
                break;
            case 3:
                printf("Enter data to add:\n");
                scanf("%d", &data);
                printf("Enter position to add:\n");
                scanf("%d", &position);
                addAt(&head, data, position);
                break;
            case 4:
                deleteFront(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Enter position to delete:\n");
                scanf("%d", &position);
                deleteAt(&head, position);
                break;
            case 7:
                printList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}