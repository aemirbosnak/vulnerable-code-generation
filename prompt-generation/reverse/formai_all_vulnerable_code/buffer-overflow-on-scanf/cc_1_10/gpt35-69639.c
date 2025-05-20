//FormAI DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

// Structure definition for Linked List
struct node{
    int data;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
struct node* insertAtBeginning(struct node* head, int data){
    struct node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    newNode -> next = head;
    return newNode;
}

// Function to insert a node at the end of the list
struct node* insertAtEnd(struct node* head, int data){
    struct node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    struct node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    return head;
}

// Function to insert a node after a given node
struct node* insertAfterNode(struct node* head, int data, int positionData){
    struct node* newNode = createNode(data);
    if(head == NULL){
        printf("List is empty. Cannont insert node after the given node.\n");
        return head;
    }
    struct node* temp = head;
    while(temp != NULL && temp -> data != positionData){
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("The given node is not found in the list. Cannot insert node after the given node.\n");
        return head;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
    return head;
}

// Function to delete a node from the beginning
struct node* deleteFromBeginning(struct node* head){
    if(head == NULL){
        printf("List is empty. Cannot delete from empty list.\n");
        return head;
    }
    struct node* temp = head;
    head = head -> next;
    free(temp);
    return head;
}

// Function to delete a node from the end
struct node* deleteFromEnd(struct node* head){
    if(head == NULL){
        printf("List is empty. Cannot delete from empty list.\n");
        return head;
    }
    struct node *temp = head, *prev = NULL;
    while(temp -> next != NULL){
        prev = temp;
        temp = temp -> next;
    }
    free(temp);
    prev -> next = NULL;
    return head;
}

// Function to delete a node at a given position
struct node* deleteFromPosition(struct node* head, int positionData){
    if(head == NULL){
        printf("List is empty. Cannot delete from empty list.\n");
        return head;
    }
    struct node* temp = head, *prev = NULL;
    while(temp != NULL && temp -> data != positionData){
        prev = temp;
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("The given node is not found in the list. Cannot delete node.\n");
        return head;
    }
    if(prev == NULL){
        head = head -> next;
        free(temp);
        return head;
    }
    prev -> next = temp -> next;
    free(temp);
    return head;
}

// Function to display the Linked List
void displayList(struct node* head){
    if(head == NULL){
        printf("List is empty. Cannot display empty list.\n");
        return;
    }
    struct node* temp = head;
    printf("The Linked List is: ");
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

// Main Function
int main(){
    struct node* head = NULL;   // Initializing the Linked List as empty
    int choice, data, positionData;
    while(1){   // Infinite loop until the user decides to exit the program
        printf("Enter the operation you want to perform:\n");
        printf("1. Insert a node at the beginning\n");
        printf("2. Insert a node at the end\n");
        printf("3. Insert a node after a given node\n");
        printf("4. Delete a node from the beginning\n");
        printf("5. Delete a node from the end\n");
        printf("6. Delete a node at a given position\n");
        printf("7. Display the Linked List\n");
        printf("8. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the data you want to insert: ");
                    scanf("%d",&data);
                    head = insertAtBeginning(head,data);
                    printf("The node with data %d is inserted at the beginning of the Linked List.\n",data);
                    break;

            case 2: printf("Enter the data you want to insert: ");
                    scanf("%d",&data);
                    head = insertAtEnd(head,data);
                    printf("The node with data %d is inserted at the end of the Linked List.\n",data);
                    break;

            case 3: printf("Enter the data you want to insert: ");
                    scanf("%d",&data);
                    printf("Enter the node after which you want to insert the new node: ");
                    scanf("%d",&positionData);
                    head = insertAfterNode(head,data,positionData);
                    if(head != NULL){
                        printf("The node with data %d is inserted after the node with data %d in the Linked List.\n",data,positionData);
                    }
                    break;

            case 4: head = deleteFromBeginning(head);
                    if(head != NULL){
                        printf("The first node of the Linked List is deleted successfully.\n");
                    }
                    break;

            case 5: head = deleteFromEnd(head);
                    if(head != NULL){
                        printf("The last node of the Linked List is deleted successfully.\n");
                    }
                    break;

            case 6: printf("Enter the data of the node you want to delete: ");
                    scanf("%d",&positionData);
                    head = deleteFromPosition(head,positionData);
                    if(head != NULL){
                        printf("The node with data %d is deleted successfully.\n",positionData);
                    }
                    break;

            case 7: displayList(head);
                    break;

            case 8: exit(0);

            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}