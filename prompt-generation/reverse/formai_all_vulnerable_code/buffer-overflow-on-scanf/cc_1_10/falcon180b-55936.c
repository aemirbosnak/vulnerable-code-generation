//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(struct Node** head, int data){
    struct Node* temp = *head;
    struct Node* prev = NULL;
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

void searchNode(struct Node* head, int data){
    struct Node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            printf("%d found\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found\n", data);
}

void displayList(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    int choice, data;
    do{
        printf("\nEnter your choice:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted:\n");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
            case 2:
                printf("Enter the data to be deleted:\n");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter the data to be searched:\n");
                scanf("%d", &data);
                searchNode(head, data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(1);
    return 0;
}