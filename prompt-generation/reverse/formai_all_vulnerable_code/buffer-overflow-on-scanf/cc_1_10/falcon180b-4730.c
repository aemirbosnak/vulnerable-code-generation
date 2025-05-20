//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Node structure
struct node{
    int data;
    struct node* next;
};

//Function to create a new node
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to add a node at the end of the list
void addNode(struct node** head, int data){
    struct node* newNode = createNode(data);
    struct node* temp = *head;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function to search for an element in the list
struct node* searchList(struct node* head, int data){
    struct node* current = head;
    while(current!= NULL){
        if(current->data == data){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

//Main function
int main(){
    struct node* head = NULL;
    int choice, data;
    do{
        printf("\nEnter your choice:\n");
        printf("1. Add element\n");
        printf("2. Search element\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to add:\n");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter the element to search:\n");
                scanf("%d", &data);
                struct node* result = searchList(head, data);
                if(result!= NULL){
                    printf("Element found!\n");
                }
                else{
                    printf("Element not found.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!= 3);
    return 0;
}