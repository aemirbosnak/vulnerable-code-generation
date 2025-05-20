//FormAI DATASET v1.0 Category: Linked list operations ; Style: careful
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete(int data){
    struct Node *temp = head;
    struct Node *prev = NULL;

    while(temp != NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("%d not found in linked list\n", data);
    }
    else if(prev == NULL){
        head = temp->next;
        free(temp);
    }
    else{
        prev->next = temp->next;
        free(temp);
    }
}

void display(){
    if(head == NULL){
        printf("List is empty!\n");
    }
    else{
        struct Node *temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int choice, data;

    while(1){
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}