//FormAI DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

//Function to create a new node
struct node* createNode(int data){
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Memory allocation failed!\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//Function to insert a node at the beginning
void insertAtBeginning(struct node **head, int data){
    struct node *new_node = createNode(data);
    new_node->next = *head;
    *head = new_node;
    printf("%d inserted successfully!\n", data);
}

//Function to insert a node at the end
void insertAtEnd(struct node **head, int data){
    struct node *new_node = createNode(data);
    struct node *temp = *head;
    if(*head == NULL){
        *head = new_node;
    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("%d inserted successfully!\n", data);
}

//Function to delete a node by value
void deleteNode(struct node **head, int data){
    struct node *temp = *head, *prev = NULL;
    if(temp != NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        printf("%d deleted successfully!\n", data);
        return;
    }
    while(temp != NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("%d not found in the list!\n", data);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted successfully!\n", data);
}

//Function to display the linked list
void displayList(struct node *head){
    struct node *temp = head;
    if(temp == NULL){
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *head = NULL;
    int choice, value;
    do{
        printf("Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2: 
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);    
                break;
            case 3: 
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4: 
                displayList(head);
                break;
            case 5:
                printf("Exiting program!\n");
                exit(0);
                break;
            default: 
                printf("Invalid Choice!\n");
        }
    }while(choice != 5);

    return 0;
}