//FormAI DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* node;

node create_node(int value) {
    node temp = (node)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void insert_at_beginning(node *head_ref, int value) {
    node temp = create_node(value);
    temp->next = *head_ref;
    *head_ref = temp;
    printf("\nWoohoo! Element %d is added at the beginning of the list!\n", value);
}

void insert_at_end(node *head_ref, int value) {
    node temp = create_node(value);
    if (*head_ref == NULL) {
        *head_ref = temp;
    }
    else {
        node current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
    printf("\nElement %d is added at the end of the list!\n", value);
}

void display(node head) {
    printf("\nThe list contains: ");
    node current = head;
    if (current == NULL) {
        printf("nothing yet!\n");
    }
    else {
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void delete_node(node *head_ref, int value) {
    node current = *head_ref;
    node previous = NULL;
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("\nOops! Element %d not found in the list!\n", value);
        return;
    }
    if (previous == NULL) {
        *head_ref = current->next;
    }
    else {
        previous->next = current->next;
    }
    free(current);
    printf("\nOh no! Element %d is deleted from the list!\n", value);
}

void search_node(node head, int value) {
    node current = head;
    int position = 0;
    while (current != NULL && current->data != value) {
        position++;
        current = current->next;
    }
    if (current == NULL) {
        printf("\nElement %d not found in the list!\n", value);
    }
    else {
        printf("\nYay! Element %d is found at position %d in the list!\n", value, position);
    }
}

int count_nodes(node head) {
    int count = 0;
    node current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void reverse_list(node *head_ref) {
    node current = *head_ref;
    node previous = NULL;
    node next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head_ref = previous;
    printf("\nThe list is reversed!\n");
}

int main() {
    node head = NULL;

    printf("Welcome to the Magical Linked List Operations Program!\n");
    printf("In this program, you can perform different operations on a linked list.\n\n");

    int choice, value, position;

    do {
        printf("\nEnter 1 to insert a node at the beginning of the list\n");
        printf("Enter 2 to insert a node at the end of the list\n");
        printf("Enter 3 to display the list\n");
        printf("Enter 4 to delete a node from the list\n");
        printf("Enter 5 to search for a node in the list\n");
        printf("Enter 6 to count the number of nodes in the list\n");
        printf("Enter 7 to reverse the list\n");
        printf("Enter 8 to exit the program\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to be inserted at the beginning: ");
                scanf("%d", &value);
                insert_at_beginning(&head, value);
                break;
            case 2:
                printf("\nEnter the value to be inserted at the end: ");
                scanf("%d", &value);
                insert_at_end(&head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("\nEnter the value to be deleted: ");
                scanf("%d", &value);
                delete_node(&head, value);
                break;
            case 5:
                printf("\nEnter the value to be searched: ");
                scanf("%d", &value);
                search_node(head, value);
                break;
            case 6:
                printf("\nThe total number of nodes in the list is %d\n", count_nodes(head));
                break;
            case 7:
                reverse_list(&head);
                break;
            case 8:
                printf("\nThank you for using the Magical Linked List Operations Program!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again!\n");
                break;
        }
    } while (choice != 8);

    return 0;
}