//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: safe
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void addNode(struct node** head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct node* temp = *head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(struct node** head, int data){
    struct node* temp = *head;
    struct node* prev = NULL;
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

void searchNode(struct node* head, int data){
    struct node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            printf("%d found\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found\n", data);
}

void printList(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct node* head = NULL;
    int choice, data;
    while(1){
        printf("Enter 1 to add node\n");
        printf("Enter 2 to delete node\n");
        printf("Enter 3 to search node\n");
        printf("Enter 4 to print list\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to add:\n");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter data to delete:\n");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter data to search:\n");
                scanf("%d", &data);
                searchNode(head, data);
                break;
            case 4:
                printList(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}