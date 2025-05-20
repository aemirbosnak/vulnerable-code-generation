//FormAI DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_node(struct node **head, int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
    }
    else {
        struct node *curr = *head;

        while(curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = new_node;
    }
}

void delete_node(struct node **head, int value) {
    struct node *prev = NULL, *curr = *head;

    while(curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL) {
        printf("Value not found");
    }
    else if(prev == NULL) {
        *head = curr->next;
        free(curr);
    }
    else {
        prev->next = curr->next;
        free(curr);
    }
}

void display_list(struct node *head) {
    if(head == NULL) {
        printf("List is empty");
    }
    else {
        struct node *curr = head;

        while(curr != NULL) {
            printf("%d -> ", curr->data);
            curr = curr->next;
        }
        printf("NULL");
    }
}

int main() {
    struct node *head = NULL;
    int choice, value;

    do {
        printf("\nMenu\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &value);
                insert_node(&head, value);
                break;

            case 2:
                printf("Enter value to be deleted: ");
                scanf("%d", &value);
                delete_node(&head, value);
                break;

            case 3:
                printf("List: ");
                display_list(head);
                break;
        }
    } while(choice != 4);

    return 0;
}