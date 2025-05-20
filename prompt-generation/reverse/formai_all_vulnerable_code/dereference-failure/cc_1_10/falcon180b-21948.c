//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createnode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Node* insertatbeginning(struct Node* head, int data){
    struct Node* newnode = createnode(data);
    newnode->next = head;
    return newnode;
}

struct Node* insertatend(struct Node* head, int data){
    struct Node* newnode = createnode(data);
    struct Node* temp = head;
    if(head == NULL){
        return newnode;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

struct Node* insertatposition(struct Node* head, int data, int position){
    struct Node* newnode = createnode(data);
    struct Node* temp = head;
    int count = 1;
    if(head == NULL){
        return newnode;
    }
    if(position == 1){
        newnode->next = head;
        return newnode;
    }
    while(temp!= NULL && count!= position){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        printf("Invalid position\n");
        return head;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

struct Node* deletebyvalue(struct Node* head, int value){
    struct Node* temp = head;
    struct Node* prev = NULL;
    if(head == NULL){
        return head;
    }
    if(head->data == value){
        head = head->next;
        free(temp);
        return head;
    }
    while(temp!= NULL && temp->data!= value){
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

void display(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct Node* head = NULL;
    int choice, value;
    while(1){
        printf("Enter your choice:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete by value\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertatbeginning(head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertatend(head, value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &value);
                head = insertatposition(head, value, value);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                head = deletebyvalue(head, value);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}