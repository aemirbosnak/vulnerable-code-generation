//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: genious
#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node* next;
};

//Function prototypes
void addNode(struct Node** head, int data);
void printList(struct Node* head);
void reverseList(struct Node** head);
void sortList(struct Node** head);

int main(){
    struct Node* head = NULL;

    //Adding nodes
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 1);

    //Printing original list
    printf("Original list: ");
    printList(head);

    //Reversing list
    reverseList(&head);

    //Printing reversed list
    printf("\nReversed list: ");
    printList(head);

    //Sorting list
    sortList(&head);

    //Printing sorted list
    printf("\nSorted list: ");
    printList(head);

    return 0;
}

//Function to add a node at the end of the list
void addNode(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function to print the list
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Function to reverse the list
void reverseList(struct Node** head){
    struct Node* prev = NULL;
    struct Node* curr = *head;

    while(curr!= NULL){
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

//Function to sort the list
void sortList(struct Node** head){
    struct Node* temp = *head;

    while(temp!= NULL && temp->next!= NULL){
        if(temp->data > temp->next->data){
            int tempData = temp->data;
            temp->data = temp->next->data;
            temp->next->data = tempData;
        }
        temp = temp->next;
    }
}