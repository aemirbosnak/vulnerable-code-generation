//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

//node structure for linked list
struct node{
    int data;
    struct node* next;
};

//function to create a new node
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to add a node at the end of the list
void addNode(struct node** head, int data){
    struct node* newNode = createNode(data);
    struct node* temp = *head;

    if(*head == NULL){
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    while(temp->next!= NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = NULL;
}

//function to print the linked list
void printList(struct node* head){
    struct node* temp = head;

    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

//function to search an element in the linked list
int searchList(struct node* head, int searchKey){
    struct node* temp = head;

    while(temp!= NULL){
        if(temp->data == searchKey){
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

//main function
int main(){
    struct node* head = NULL;
    int choice, data, searchKey;

    do{
        printf("\n\n");
        printf("1. Add Node\n");
        printf("2. Print List\n");
        printf("3. Search List\n");
        printf("4. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;

            case 2:
                printf("List: ");
                printList(head);
                printf("\n");
                break;

            case 3:
                printf("Enter search key: ");
                scanf("%d", &searchKey);
                if(searchList(head, searchKey)){
                    printf("Element found!\n");
                }
                else{
                    printf("Element not found.\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }while(choice!= 4);

    return 0;
}