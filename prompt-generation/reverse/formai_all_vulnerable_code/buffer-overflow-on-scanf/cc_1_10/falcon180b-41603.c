//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//Node structure for linked list
typedef struct node{
    int data;
    struct node *next;
}Node;

//Function to create a new node
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to print the linked list
void printList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Function to search for an element in the linked list
Node* searchList(Node* head, int key){
    Node* temp = head;
    while(temp!= NULL){
        if(temp->data == key){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//Main function
int main(){
    Node* head = NULL;
    int choice, key;

    //Menu-driven program
    while(TRUE){
        printf("1. Insert element\n");
        printf("2. Display list\n");
        printf("3. Search element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &key);
                head = createNode(key);
                break;
            case 2:
                printf("List: ");
                printList(head);
                break;
            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &key);
                Node* result = searchList(head, key);
                if(result!= NULL){
                    printf("Element found\n");
                }
                else{
                    printf("Element not found\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}