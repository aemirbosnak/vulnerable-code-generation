//FormAI DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int value;
    struct node *next;
} node;

void display(node *head) {
    if(head == NULL) {
        printf("The list is empty.");
        return;
    }
    node *temp = head;
    printf("List: ");
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void insert(node **head, int value) {
    node *new_node = malloc(sizeof(node));
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

void delete(node **head, int value) {
    if(*head == NULL) {
        printf("The list is empty.");
        return;
    }
    node *prev = NULL;
    node *temp = *head;
    while(temp != NULL) {
        if(temp->value == value) {
            if(prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            printf("Deleted %d from the list.\n", value);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("%d not found in the list.\n", value);
}

node *generate(int n) {
    node *head = NULL;
    for(int i = 0; i < n; i++) {
        int value = rand() % 101;
        insert(&head, value);
    }
    return head;
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Linked List Visualization Program!\n");
    printf("This program will generate a linked list of random integers for you to visualize.\n");
    printf("Please enter the number of elements you would like in the list: ");
    int n;
    scanf("%d", &n);
    printf("Generating list...\n");
    node *head = generate(n);
    display(head);
    printf("What would you like to do with the list?\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Exit program\n");
    int choice;
    while(1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("Please enter the value you would like to insert: ");
                int value;
                scanf("%d", &value);
                insert(&head, value);
                display(head);
                break;
            }
            case 2: {
                printf("Please enter the value you would like to delete: ");
                int value;
                scanf("%d", &value);
                delete(&head, value);
                display(head);
                break;
            }
            case 3: {
                printf("Exiting program...\n");
                return 0;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
}