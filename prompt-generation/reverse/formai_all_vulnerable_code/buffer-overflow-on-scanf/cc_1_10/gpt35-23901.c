//FormAI DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

// Defining the node structure
struct node{
    int data;
    struct node *next;
};

// Function to add a new node at the start of the linked list
void insertAtStart(struct node **head_ref, int new_data){
    
    // Creating a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("%d added at the start of the Linked List.\n", new_data);
}

// Function to add a new node at the end of the linked list
void insertAtEnd(struct node **head_ref, int new_data){
    
    // Creating a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    struct node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        printf("%d added at the end of the Linked List.\n", new_data);
        return;
    }
    while(last->next != NULL)
        last = last->next;
    last->next = new_node;
    printf("%d added at the end of the Linked List.\n", new_data);
}

// Function to add a new node at a given position in the linked list
void insertAtPos(struct node **head_ref, int new_data, int pos){
    
    // Checking if position is valid
    if(pos < 1){
        printf("Invalid position entered.\n");
        return;
    }

    // Creating a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;

    // Inserting the new node at start if position is 1
    if(pos == 1){
        new_node->next = *head_ref;
        *head_ref = new_node;
        printf("%d added at position %d of the Linked List.\n", new_data, pos);
        return;
    }
    
    // Finding the node after which new node is to be added
    int i = 1;
    struct node *prev = *head_ref;
    while(i < (pos-1)){
        prev = prev->next;
        if(prev == NULL){
            printf("Invalid position entered.\n");
            return;
        }
        i++;
    }

    // Inserting the new node at the required position
    new_node->next = prev->next;
    prev->next = new_node;
    printf("%d added at position %d of the Linked List.\n", new_data, pos);
}

// Function to delete a node with a given data value
void deleteNode(struct node **head_ref, int key){
    
    // Checking if Linked List is empty
    if(*head_ref == NULL){
        printf("Linked List is empty. Cannot delete node.\n");
        return;
    }

    // Deleting the first node if it contains the key value
    struct node *temp = *head_ref, *prev;
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        printf("%d deleted from the Linked List.\n", key);
        return;
    }

    // Finding the node with the key value
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    // Deleting the node with the key value if found
    if(temp == NULL){
        printf("%d not found in the Linked List.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted from the Linked List.\n", key);
}

// Function to traverse the Linked List and print the contents
void display(struct node **head_ref){
    
    // Checking if Linked List is empty
    if(*head_ref == NULL){
        printf("Linked List is empty. Nothing to display.\n");
        return;
    }

    // Displaying Linked List contents
    struct node *temp = *head_ref;
    printf("Linked List contents are:\n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main(){
    
    // Creating an empty Linked List
    struct node *head = NULL;
    int choice, data, pos, key;
    
    // Displaying menu for Linked List operations
    printf("Welcome to Linked List operations program.\n");
    printf("Please choose an operation:\n");
    printf("1. Insert a node at the start of the Linked List.\n");
    printf("2. Insert a node at the end of the Linked List.\n");
    printf("3. Insert a node at a given position in the Linked List.\n");
    printf("4. Delete a node with a given data value.\n");
    printf("5. Display the contents of the Linked List.\n");
    printf("6. Exit\n");

    // Looping until user chooses to exit
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: // Inserting a node at the start of the Linked List
                    printf("Enter data to be inserted: ");
                    scanf("%d", &data);
                    insertAtStart(&head, data);
                    break;
            
            case 2: // Inserting a node at the end of the Linked List
                    printf("Enter data to be inserted: ");
                    scanf("%d", &data);
                    insertAtEnd(&head, data);
                    break;
            
            case 3: // Inserting a node at a given position in the Linked List
                    printf("Enter data to be inserted: ");
                    scanf("%d", &data);
                    printf("Enter position at which node is to be inserted: ");
                    scanf("%d", &pos);
                    insertAtPos(&head, data, pos);
                    break;
            
            case 4: // Deleting a node with a given data value
                    printf("Enter data to be deleted: ");
                    scanf("%d", &key);
                    deleteNode(&head, key);
                    break;
            
            case 5: // Displaying the contents of the Linked List
                    display(&head);
                    break;
            
            case 6: // Exiting the program
                    printf("Terminating program.\n");
                    exit(0);
                    break;
            
            default: // Handling invalid choice input
                    printf("Invalid choice entered. Please try again.\n");
                    break;
        }
    }

    return 0;
}