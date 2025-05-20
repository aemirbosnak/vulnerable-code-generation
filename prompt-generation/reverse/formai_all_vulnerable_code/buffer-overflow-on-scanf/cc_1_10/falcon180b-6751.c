//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *createNode(int data){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if(newnode == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void addNode(NODE **head, int data){
    NODE *newnode = createNode(data);
    newnode->next = *head;
    *head = newnode;
}

void printList(NODE *head){
    NODE *temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int searchNode(NODE *head, int data){
    NODE *temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            return TRUE;
        }
        temp = temp->next;
    }
    return FALSE;
}

void deleteNode(NODE **head, int data){
    NODE *temp = *head;
    NODE *prev = NULL;
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Element not found\n");
        return;
    }
    if(prev == NULL){
        *head = temp->next;
    }
    else{
        prev->next = temp->next;
    }
    free(temp);
}

int main(){
    NODE *head = NULL;
    int choice, data;
    while(TRUE){
        printf("1. Add Node\n2. Print List\n3. Search Node\n4. Delete Node\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                if(searchNode(head, data)){
                    printf("Element found\n");
                }
                else{
                    printf("Element not found\n");
                }
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}