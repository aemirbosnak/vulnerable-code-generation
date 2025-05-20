//FormAI DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the linked list node
struct node {
    int data;           // data contained within node
    struct node* next;  // pointer to the next node in the list
};

// Function to create a new node with the given data
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the list
void insert_beginning(struct node** head, int data) {
    struct node* new_node = create_node(data);
    new_node -> next = *head;
    *head = new_node;
    printf("%d inserted at beginning of list\n", data);
}

// Function to insert a new node at the end of the list
void insert_end(struct node** head, int data) {
    struct node* new_node = create_node(data);
    
    if (*head == NULL) {
        *head = new_node;
        printf("%d inserted at end of list\n", data);
        return;
    }
    
    struct node* curr_node = *head;
    while (curr_node -> next != NULL) {
        curr_node = curr_node -> next;
    }
    curr_node -> next = new_node;
    printf("%d inserted at end of list\n", data);
}

// Function to delete a node from the beginning of the list
void delete_beginning(struct node** head) {
    if (*head == NULL) {
        printf("Cannot delete from empty list\n");
        return;
    }
    
    struct node* temp = *head;
    *head = (*head) -> next;
    free(temp);
    printf("Node at beginning of list deleted\n");
}

// Function to delete a node from the end of the list
void delete_end(struct node** head) {
    if (*head == NULL) {
        printf("Cannot delete from empty list\n");
        return;
    }
    
    struct node* curr_node = *head;
    struct node* prev_node = NULL;
    
    while (curr_node -> next != NULL) {
        prev_node = curr_node;
        curr_node = curr_node -> next;
    }
    
    if (prev_node == NULL) {
        *head = NULL;
    } else {
        prev_node -> next = NULL;
    }
    
    free(curr_node);
    printf("Node at end of list deleted\n");
}

// Function to display the linked list
void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node* curr_node = head;
    printf("List: ");
    
    while (curr_node != NULL) {
        printf("%d ", curr_node -> data);
        curr_node = curr_node -> next;
    }
    printf("\n");
}

// Main function to test the above functions
int main() {
    struct node* head = NULL;
    int choice, data;
    
    do {
        printf("\nLinked list operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_beginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;
            case 3:
                delete_beginning(&head);
                break;
            case 4:
                delete_end(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting program. Bye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}