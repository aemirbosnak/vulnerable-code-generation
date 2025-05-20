//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to insert a node at the end of the linked list
void insert(int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to search for a value in the linked list
int search(int value) {
    struct node *temp = head;

    while (temp!= NULL) {
        if (temp->data == value) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

// Function to delete a node from the linked list
void delete(int value) {
    struct node *temp = head;
    struct node *prev = NULL;

    if (temp!= NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void print_list() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked list: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("1. Insert\n2. Search\n3. Delete\n4. Print list\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(value)) {
                printf("%d found in the list.\n", value);
            } else {
                printf("%d not found in the list.\n", value);
            }
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            delete(value);
            break;
        case 4:
            print_list();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}