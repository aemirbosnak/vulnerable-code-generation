//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: lively
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void addNode(node **head, int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        node *temp = *head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(node **head, int data){
    node *temp = *head;
    node *prev = NULL;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void displayList(node *head){
    node *temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    node *head = NULL;
    int choice, data;
    while(1){
        printf("Enter 1 to add a node, 2 to delete a node, 3 to display the list, 0 to exit: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be added: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}