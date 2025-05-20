//FormAI DATASET v1.0 Category: Data structures visualization ; Style: complete
#include<stdio.h>
#include<stdlib.h>

/*Structure Definition*/

typedef struct node{
    int data;
    struct node *next;
}Node;

/*Function to create a new node*/

Node* createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

/*Function to insert a node at the beginning of the list*/

Node* insertAtBeginning(Node *head, int value){
    Node *newNode = createNode(value);
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }

    return head;
}

/*Function to insert a node at the end of the list*/

void insertAtEnd(Node *head, int value){
    Node *newNode = createNode(value);
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

/*Function to insert a node after a particular node*/

void insertAfter(Node *head, int loc, int value){
    Node *newNode = createNode(value);
    Node *temp = head;
    loc--;
    while(loc>0 && temp!=NULL){
        temp = temp->next;
        loc--;
    }
    if(temp == NULL){
        printf("Invalid location!\n");
    }
    else{
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

/*Function to delete a node at the beginning*/

Node* deleteAtBeginning(Node *head){
    Node *temp = head;
    if(head == NULL){
        printf("List is empty!\n");
    }
    else{
        head = head->next;
        free(temp);
    }

    return head;
}

/*Function to delete a node at the end*/

void deleteAtEnd(Node *head){
    Node *temp = head;
    if(temp == NULL){
        printf("List is empty!\n");
    }
    else if(temp->next == NULL){
        head = NULL;
        free(temp);
    }
    else{
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = NULL;
        free(temp2);
    }
}

/*Function to delete a node after a particular node*/

void deleteAfter(Node *head, int loc){
    Node *temp = head;
    loc--;
    while(loc>0 && temp!=NULL){
        temp = temp->next;
        loc--;
    }
    if(temp == NULL || temp->next == NULL){
        printf("Invalid location!\n");
    }
    else{
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

/*Function to display the list*/

void displayList(Node *head){
    if(head == NULL){
        printf("List is empty!\n");
    }
    else{
        while(head != NULL){
            printf("%d ",head->data);
            head = head->next;
        }
    }
}

/*Main Function*/

int main(){
    Node *head = NULL;
    int choice;
    int value,loc;

    while(1){
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a specific node\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete after a specific node\n");
        printf("7. Display the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf("%d",&value);
                head = insertAtBeginning(head,value);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d",&value);
                insertAtEnd(head,value);
                break;
            case 3:
                printf("Enter the location: ");
                scanf("%d",&loc);
                printf("Enter the value: ");
                scanf("%d",&value);
                insertAfter(head,loc,value);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                deleteAtEnd(head);
                break;
            case 6:
                printf("Enter the location: ");
                scanf("%d",&loc);
                deleteAfter(head,loc);
                break;
            case 7:
                displayList(head);
                printf("\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}