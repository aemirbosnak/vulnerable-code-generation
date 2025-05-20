//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 10000

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtEnd(Node* head, int data){
    Node* newNode = createNode(data);
    Node* temp = head;
    if(head == NULL){
        head = newNode;
        return head;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertAtBeginning(Node* head, int data){
    Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

Node* deleteNode(Node* head, int data){
    Node* temp = head;
    Node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        head = temp->next;
        free(temp);
        return head;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

void display(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;
    int choice, data;
    do{
        printf("Enter 1 to insert at the beginning\n");
        printf("Enter 2 to insert at the end\n");
        printf("Enter 3 to delete a node\n");
        printf("Enter 4 to display the list\n");
        printf("Enter 5 to exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(1);
    return 0;
}