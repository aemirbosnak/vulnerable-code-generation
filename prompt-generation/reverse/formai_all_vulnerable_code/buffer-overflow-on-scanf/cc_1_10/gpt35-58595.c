//FormAI DATASET v1.0 Category: Data structures visualization ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Definition of a linked list node
struct node {
    int data;
    struct node* next;
};

// Function to create a new linked list node
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linked list
void insert_node_beg(struct node** head, int data) {
    struct node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the linked list
void insert_node_end(struct node** head, int data) {
    struct node* new_node = create_node(data);
    struct node* temp = *head;
    if(*head == NULL) {
        *head = new_node;
    }
    else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to delete a node from the linked list
void delete_node(struct node** head, int key) {
    struct node* temp = *head;
    struct node* prev = NULL;
    if(temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void print_list(struct node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int option, data;
    while(1) {
        printf("Choose an option:\n");
        printf("1. Insert a node at the beginning\n");
        printf("2. Insert a node at the end\n");
        printf("3. Delete a node\n");
        printf("4. Print the linked list\n");
        printf("5. Exit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_node_beg(&head, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_node_end(&head, data);
                break;
            case 3:
                printf("Enter the key to be deleted: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            case 4:
                printf("The linked list is: ");
                print_list(head);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option! Choose again.\n");
        }
    }
    return 0;
}