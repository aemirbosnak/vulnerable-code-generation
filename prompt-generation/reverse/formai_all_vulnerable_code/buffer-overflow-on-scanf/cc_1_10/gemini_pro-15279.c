//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void create_list(node **head, int n) {
    node *temp, *last;
    int i;

    for (i = 0; i < n; i++) {
        temp = (node *)malloc(sizeof(node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (*head == NULL) {
            *head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
}

void display_list(node *head) {
    node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void insert_at_beginning(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(node **head, int data) {
    node *temp = *head;
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void insert_at_position(node **head, int data, int position) {
    node *temp = *head;
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    int i = 1;
    while (i < position - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (i == position - 1) {
        new_node->next = temp->next;
        temp->next = new_node;
    } else {
        printf("Invalid position!\n");
    }
}

void delete_at_beginning(node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = *head;
    node *prev;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void delete_at_position(node **head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    node *temp = *head;
    node *prev;

    int i = 1;
    while (i < position && temp->next != NULL) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (i == position) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Invalid position!\n");
    }
}

void reverse_list(node **head) {
    node *prev = NULL;
    node *current = *head;
    node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void sort_list(node **head) {
    node *current = *head;
    node *index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }

            index = index->next;
        }

        current = current->next;
    }
}

int main() {
    node *head = NULL;
    int n, choice, data, position;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    create_list(&head, n);
    printf("Created list: ");
    display_list(head);

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Reverse list\n");
        printf("8. Sort list\n");
        printf("9. Display list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_at_beginning(&head, data);
                printf("List after insertion at beginning: ");
                display_list(head);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                printf("List after insertion at end: ");
                display_list(head);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insert_at_position(&head, data, position);
                printf("List after insertion at position: ");
                display_list(head);
                break;
            case 4:
                delete_at_beginning(&head);
                printf("List after deletion at beginning: ");
                display_list(head);
                break;
            case 5:
                delete_at_end(&head);
                printf("List after deletion at end: ");
                display_list(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_at_position(&head, position);
                printf("List after deletion at position: ");
                display_list(head);
                break;
            case 7:
                reverse_list(&head);
                printf("List after reversing: ");
                display_list(head);
                break;
            case 8:
                sort_list(&head);
                printf("List after sorting: ");
                display_list(head);
                break;
            case 9:
                display_list(head);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice (1-10).\n");
        }
    }

    return 0;
}