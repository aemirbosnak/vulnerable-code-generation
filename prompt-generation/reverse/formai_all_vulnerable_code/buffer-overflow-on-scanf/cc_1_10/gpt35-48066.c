//FormAI DATASET v1.0 Category: Linked list operations ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void display(Node* head);
Node* insert_at_beginning(Node*, int);
Node* insert_at_end(Node*, int);
Node* insert_at_position(Node*, int, int);
Node* delete_at_beginning(Node*);
Node* delete_at_end(Node*);
Node* delete_at_position(Node*, int);
void search(Node*, int);

int main(){
    Node* head = NULL;
    int choice = 0, data, position;
    do{
        printf("\n1-Insert at beginning\n2-Insert at end\n3-Insert at position\n4-Delete at beginning\n5-Delete at end\n6-Delete at position\n7-Display\n8-Search\n9-Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the data:");
                scanf("%d",&data);
                head = insert_at_beginning(head, data);
                break;
            case 2:
                printf("\nEnter the data:");
                scanf("%d",&data);
                head = insert_at_end(head, data);
                break;
            case 3:
                printf("\nEnter the data:");
                scanf("%d",&data);
                printf("\nEnter the position:");
                scanf("%d",&position);
                head = insert_at_position(head, data, position);
                break;
            case 4:
                head = delete_at_beginning(head);
                break;
            case 5:
                head = delete_at_end(head);
                break;
            case 6:
                printf("\nEnter the position to delete:");
                scanf("%d",&position);
                head = delete_at_position(head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("\nEnter the data to search:");
                scanf("%d",&data);
                search(head, data);
                break;
            case 9:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }while(choice!=9);
    return 0;
}

void display(Node* head){
    if(head==NULL){
        printf("\nList is empty!");
        return;
    }
    printf("\nThe list is:");
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

Node* insert_at_beginning(Node* head, int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    printf("\n%d inserted at the beginning!", data);
    return head;
}

Node* insert_at_end(Node* head, int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if(head==NULL){
        head = newnode;
    }
    else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("\n%d inserted at the end!", data);
    return head;
}

Node* insert_at_position(Node* head, int data, int position){
    if(position==1){
        head = insert_at_beginning(head, data);
    }
    else{
        int count = 1;
        Node* temp = head;
        while(temp!=NULL && count!=position-1){
            temp = temp->next;
            count++;
        }
        if(temp==NULL){
            printf("\nPosition not found in list!");
        }
        else{
            Node* newnode = (Node*)malloc(sizeof(Node));
            newnode->data = data;
            newnode->next = temp->next;
            temp->next = newnode;
            printf("\n%d inserted at position %d!", data, position);
        }
    }
    return head;
}

Node* delete_at_beginning(Node* head){
    if(head==NULL){
        printf("\nList is empty!");
        return head;
    }
    else{
        Node* temp = head;
        printf("\n%d deleted from beginning!", temp->data);
        head = head->next;
        free(temp);
    }
    return head;
}

Node* delete_at_end(Node* head){
    if(head==NULL){
        printf("\nList is empty!");
        return head;
    }
    else if(head->next==NULL){
        printf("\n%d deleted from end!",head->data);
        free(head);
        head = NULL;
    }
    else{
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        printf("\n%d deleted from end!",temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
    return head;
}

Node* delete_at_position(Node* head, int position){
    if(head==NULL){
        printf("\nList is empty!");
        return head;
    }
    else if(position==1){
        head = delete_at_beginning(head);
    }
    else{
        int count = 1;
        Node* temp = head;
        while(temp!=NULL && count!=position-1){
            temp = temp->next;
            count++;
        }
        if(temp==NULL || temp->next==NULL){
            printf("\nPosition not found in list!");
        }
        else{
            Node* todelete = temp->next;
            temp->next = temp->next->next;
            printf("\n%d deleted from position %d!", todelete->data, position);
            free(todelete);
        }
    }
    return head;
}

void search(Node* head, int data){
    int count = 1, found = 0;
    while(head!=NULL){
        if(head->data==data){
            printf("\n%d found at position %d!", data, count);
            found = 1;
            break;
        }
        head = head->next;
        count++;
    }
    if(found==0){
        printf("\n%d not found in list!", data);
    }
}