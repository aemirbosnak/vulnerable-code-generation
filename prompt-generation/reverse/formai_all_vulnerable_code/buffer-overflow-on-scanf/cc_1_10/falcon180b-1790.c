//Falcon-180B DATASET v1.0 Category: Memory management ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void delete(struct Node** head){
    struct Node* temp = *head;
    if(temp == NULL){
        printf("List is empty\n");
        return;
    }
    *head = temp->next;
    free(temp);
    printf("Node deleted successfully\n");
}

void reverse(struct Node* head){
    struct Node* prev = NULL;
    struct Node* curr = head;
    while(curr!= NULL){
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display(struct Node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    int choice, data;
    while(1){
        printf("Enter 1 to insert a node\n");
        printf("Enter 2 to delete a node\n");
        printf("Enter 3 to reverse the list\n");
        printf("Enter 4 to display the list\n");
        printf("Enter 5 to exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                delete(&head);
                break;
            case 3:
                reverse(head);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}