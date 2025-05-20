//Falcon-180B DATASET v1.0 Category: Memory management ; Style: curious
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void createNode(node** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }else{
        node* temp = *head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(node* head){
    node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void deleteNode(node** head, int data){
    node* temp = *head;
    node* prev = NULL;
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Node not found\n");
    }else{
        if(prev == NULL){
            *head = temp->next;
        }else{
            prev->next = temp->next;
        }
        free(temp);
    }
}

int main(){
    node* head = NULL;
    int choice, data;
    while(1){
        printf("Enter your choice:\n");
        printf("1. Create Node\n2. Print List\n3. Delete Node\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                createNode(&head, data);
                break;
            case 2:
                printf("List: ");
                printList(head);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}