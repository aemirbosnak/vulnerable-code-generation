//FormAI DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

//Defining the structure of node in linked list
struct node {
    int data;
    struct node *next;
};

//Function to traverse and display the linked list
void traverse(struct node *head) {
    printf("Traversing the linked list...\n");
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Function to create a new node and add it to the end of the linked list
void add_node(struct node **head, int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL) {
        *head = new_node;
    }
    else {
        struct node *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("%d added to the end of the linked list.\n",data);
}

//Function to delete a node with a given value from the linked list
void delete_node(struct node **head, int data) {
    struct node *temp = *head;
    struct node *prev = NULL;
    while(temp != NULL) {
        if(temp->data == data) {
            if(prev == NULL) {
                *head = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            printf("%d deleted from the linked list.\n",data);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("%d not found in the linked list.\n",data);
}

//Function to insert a new node with a given value after a node with a given value
void insert_after_node(struct node **head, int existing_data, int new_data) {
    struct node *temp = *head;
    while (temp != NULL) {
        if (temp->data == existing_data) {
            struct node *new_node = (struct node*) malloc(sizeof(struct node));
            new_node->data = new_data;
            new_node->next = temp->next;
            temp->next = new_node;
            printf("%d added after %d in the linked list.\n",new_data,existing_data);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in the linked list.\n",existing_data);
}

//Function to reverse the linked list
void reverse_list(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("The linked list has been reversed.\n");
}

//The main function
int main() {
    struct node *head = NULL;
    printf("Welcome to the Surrealist Linked List Program!\n");
    int choice, value, existing_value;
    while(1) {
        printf("\n");
        printf("1. Add a node to the end of the linked list\n");
        printf("2. Delete a node with a given value from the linked list\n");
        printf("3. Insert a new node with a given value after a node with a given value\n");
        printf("4. Reverse the linked list\n");
        printf("5. Traverse and display the linked list\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice) {
            case 1:
                printf("Enter a value to add to the end of the linked list: ");
                scanf("%d",&value);
                add_node(&head, value);
                break;
            case 2:
                printf("Enter a value to delete from the linked list: ");
                scanf("%d",&value);
                delete_node(&head, value);
                break;
            case 3:
                printf("Enter an existing value in the linked list: ");
                scanf("%d",&existing_value);
                printf("Enter a new value to insert after %d: ",existing_value);
                scanf("%d",&value);
                insert_after_node(&head, existing_value, value);
                break;
            case 4:
                reverse_list(&head);
                break;
            case 5:
                traverse(head);
                break;
            case 6:
                printf("Thank you for using the Surrealist Linked List Program!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}