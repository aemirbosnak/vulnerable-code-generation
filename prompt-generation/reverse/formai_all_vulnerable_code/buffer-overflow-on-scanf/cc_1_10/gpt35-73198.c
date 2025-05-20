//FormAI DATASET v1.0 Category: Linked list operations ; Style: automated
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

void createList(Node **head, int n){
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *temp = *head;
    printf("\nEnter the data for the node 1:");
    scanf("%d",&newNode->data);

    newNode->next = NULL;
    *head = newNode;
    for(int i=2;i<=n;i++){
        Node *newNode = (Node*)malloc(sizeof(Node));
        printf("\nEnter the data for the node %d:",i);
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void displayList(Node **head){
    Node *temp = *head;
    printf("\nThe linked list is: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void insertAtBeginning(Node **head,int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head,int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node **head,int data,int position){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node *temp = *head;
    for(int i=1;i<position-1;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning(Node **head){
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromEnd(Node **head){
    Node *temp = *head, *previousNode;
    while(temp->next != NULL){
        previousNode = temp;
        temp = temp->next;
    }
    previousNode->next = NULL;
    free(temp);
}

void deleteFromPosition(Node **head,int position){
    Node *temp = *head, *previousNode;
    for(int i=1;i<position;i++){
        previousNode = temp;
        temp = temp->next;
    }
    previousNode->next = temp->next;
    free(temp);
}

int main(){
    Node *head = NULL;

    int choice, nodes, data,position;

    while(1){
        printf("\n----LINKED LIST OPERATIONS----\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at end\n");
        printf("5. Insert at any position\n");
        printf("6. Delete from beginning\n");
        printf("7. Delete from end\n");
        printf("8. Delete from any position\n");
        printf("9. Exit\n");

        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the total no of Nodes:");
                scanf("%d",&nodes);
                createList(&head,nodes);
                break;
            case 2:
                displayList(&head);
                break;
            case 3:
                printf("\nEnter the data to insert at beginning:");
                scanf("%d",&data);              
                insertAtBeginning(&head,data);
                break;
            case 4:
                printf("\nEnter the data to insert at end:");
                scanf("%d",&data);
                insertAtEnd(&head,data);
                break;
            case 5:
                printf("\nEnter the data to insert:");
                scanf("%d",&data);
                printf("\nEnter the position to insert:");
                scanf("%d",&position);
                insertAtPosition(&head,data,position);
                break;
            case 6:
                deleteFromBeginning(&head);
                break;
            case 7:
                deleteFromEnd(&head);
                break;
            case 8:
                printf("\nEnter the position to delete:");
                scanf("%d",&position);
                deleteFromPosition(&head,position);
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    return 0;
}