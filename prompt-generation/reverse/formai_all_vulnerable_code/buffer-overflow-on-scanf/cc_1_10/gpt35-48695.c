//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = head;
    head = new_node;
}

void delete(int val) {
    struct node* current = head;
    struct node* previous = NULL;

    while(current != NULL && current->data != val) {
        previous = current;
        current = current->next;
    }

    if(current == NULL) {
        printf("Value not found\n");
    }
    else if(previous == NULL) {
        head = current->next;
    }
    else {
        previous->next = current->next;
    }

    free(current);
}

struct node* search(int val) {
    struct node* current = head;

    while(current != NULL && current->data != val) {
        current = current->next;
    }

    return current;
}

void print() {
    struct node* current = head;
    printf("List: ");
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice;
    int val;
    struct node* result;

    do {
        printf("\nMenu\n");
        printf("1. Insert into list\n");
        printf("2. Delete from list\n");
        printf("3. Search for value\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete(val);
                break;

            case 3:
                printf("Enter value to search for: ");
                scanf("%d", &val);
                result = search(val);
                if(result == NULL) {
                    printf("Value not found\n");
                }
                else {
                    printf("Value found at address %p\n", result);
                }
                break;

            case 4:
                print();
                break;

            case 5:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);

    return 0;
}