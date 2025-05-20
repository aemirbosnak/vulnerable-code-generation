//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* deleteNode(struct Node* head, int data){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(head->data == data){
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* temp = head;
    while(temp->next!= NULL && temp->next->data!= data){
        temp = temp->next;
    }
    if(temp->next == NULL){
        printf("Element not found in list\n");
        return head;
    }
    struct Node* delNode = temp->next;
    temp->next = temp->next->next;
    free(delNode);
    return head;
}

void displayList(struct Node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, data;
    struct Node* head = NULL;
    while(1){
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                head = insertNode(head, data);
                break;
            }
            case 2:{
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            }
            case 3:{
                displayList(head);
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}