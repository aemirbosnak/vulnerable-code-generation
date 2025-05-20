//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

//Structure for a node
typedef struct node{
    char data;
    struct node* next;
}Node;

//Function to create a node
Node* createNode(char data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to add a node to the end of the list
void addNode(Node** head, char data){
    Node* newNode = createNode(data);
    Node* temp = *head;
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
bool search(Node* head, char data){
    Node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//Function to display the list
void display(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;
    int choice, data;

    //Loop to perform operations on the list
    while(true){
        printf("Enter your choice:\n");
        printf("1.Add element\n");
        printf("2.Search element\n");
        printf("3.Display list\n");
        printf("4.Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                printf("Enter the element to be added:\n");
                scanf(" %c", &data);
                addNode(&head, data);
                break;
            }
            case 2:{
                printf("Enter the element to be searched:\n");
                scanf(" %c", &data);
                if(search(head, data)){
                    printf("Element found!\n");
                }
                else{
                    printf("Element not found.\n");
                }
                break;
            }
            case 3:{
                display(head);
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}