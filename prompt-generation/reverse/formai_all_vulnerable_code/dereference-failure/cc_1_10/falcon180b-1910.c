//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *create(int data){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void addNode(node **head, int data){
    node *newnode = create(data);
    newnode->next = *head;
    *head = newnode;
}

void deleteNode(node **head, int data){
    node *temp = *head;
    if(temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp->next!= NULL && temp->next->data!= data){
        temp = temp->next;
    }
    if(temp->next == NULL){
        return;
    }
    node *newnode = temp->next;
    temp->next = temp->next->next;
    free(newnode);
}

void printList(node *head){
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    node *head = NULL;
    int choice, data;
    do{
        printf("\nEnter your choice:\n");
        printf("1. Add a node\n2. Delete a node\n3. Display the list\n4. Exit\n");
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
                printf("The list is: ");
                printList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!= 4);
    return 0;
}