//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory Error\n");
        return;
    }
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void deleteNode(struct Node** head, int data){
    struct Node* temp = (*head);
    struct Node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        (*head) = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Element not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void searchNode(struct Node* head, int data){
    struct Node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

void displayList(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct Node* head = NULL;
    int choice, data;
    while(1){
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter data: ");
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
    }
    return 0;
}