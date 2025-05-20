//FormAI DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct node { // struct to model each node of the linked list
    int data;
    struct node *next;
};

struct node* create_node(int value) { // method to create a new node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void insert_at_tail(struct node** head, int value) { // method to insert a new node at the end of linked list
    struct node* new_node = create_node(value);

    if (*head == NULL) { // if the list is empty
        *head = new_node;
        return;
    }

    struct node* current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

void insert_at_head(struct node** head, int value) { // method to insert a new node at the beginning of linked list
    struct node* new_node = create_node(value);

    if (*head == NULL) { // if the list is empty
        *head = new_node;
        return;
    }

    new_node->next = *head;
    *head = new_node;
}

void delete_element(struct node** head, int value) { // method to delete an element from linked list
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == value) { // if the first element needs to be deleted
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct node* current_node = *head;
    while (current_node->next != NULL) {
        if (current_node->next->data == value) { // if current_node's next node needs to be deleted
            struct node* temp = current_node->next;
            current_node->next = current_node->next->next;
            free(temp);
            return;
        }
        current_node = current_node->next;
    }
}

void print_list(struct node* head) { // method to print the linked list
    if (head == NULL) {
        printf("List is Empty!\n");
        return;
    }

    struct node* current_node = head;
    while (current_node != NULL) {
        printf("%d->", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL; // initialize an empty linked list
    int choice, value, delete_value;

    do {
        printf("\n1. Insert at Head\n2. Insert at Tail\n3. Delete Element\n4. Print List\n0. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // insert at head
                printf("Enter Value to Insert: ");
                scanf("%d", &value);
                insert_at_head(&head, value);
                printf("Element Inserted at Head Successfully!\n");
                break;
            case 2: // insert at tail
                printf("Enter Value to Insert: ");
                scanf("%d", &value);
                insert_at_tail(&head, value);
                printf("Element Inserted at Tail Successfully!\n");
                break;
            case 3: // delete element
                printf("Enter Value to Delete: ");
                scanf("%d", &delete_value);
                delete_element(&head, delete_value);
                printf("Element Deleted Successfully!\n");
                break;
            case 4: // print list
                print_list(head);
                break;
            case 0: // exit
                printf("Exiting Program...\n");
                break;
            default: // invalid choice
                printf("Invalid Choice! Please Try Again.\n");
                break;
        }

    } while(choice != 0);

    return 0;
}