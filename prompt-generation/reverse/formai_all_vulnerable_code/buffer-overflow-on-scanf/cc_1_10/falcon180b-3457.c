//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void addNode(node** head, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(node** head, int data){
    node* temp = *head;
    node* prev = NULL;
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

void searchNode(node* head, int data){
    node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            printf("%d found\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found\n", data);
}

void printList(node* head){
    node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    node* head = NULL;
    int choice, data;
    while(1){
        printf("1. Add Node\n2. Delete Node\n3. Search Node\n4. Print List\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter data to be deleted: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter data to be searched: ");
                scanf("%d", &data);
                searchNode(head, data);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}