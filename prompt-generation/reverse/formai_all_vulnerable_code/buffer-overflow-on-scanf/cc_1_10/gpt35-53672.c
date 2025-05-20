//FormAI DATASET v1.0 Category: Funny ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Defining the struct to create a node
typedef struct node{
    int data;
    struct node *next;
}node;

//Creating a linked list
void createLinkedList(node **head, int n){
    node *temp, *new_node; //Creating two nodes to navigate the linked list
    
    //Creating the head node
    *head = (node*)malloc(sizeof(node));
    if(*head == NULL){
        printf("Memory not allocated.\n");
        exit(0);
    }
    
    //Initializing the head node data
    srand(time(0)); //Seeding the random number generator with the current time
    (*head)->data = rand()%1000;
    (*head)->next = NULL;
    
    //Creating n-1 nodes
    temp = *head;
    for(int i=1; i<n; i++){
        new_node = (node*)malloc(sizeof(node));
        if(new_node == NULL){
            printf("Memory not allocated.\n");
            exit(0);
        }
        new_node->data = rand()%1000;
        new_node->next = NULL;
        temp->next = new_node;
        temp = temp->next;
    }
}

//Displaying the linked list
void displayList(node *head){
    printf("Linked list:\n");
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Reversing the linked list in place
void reverseLinkedList(node **head){
    node *curr, *prev, *next;
    curr = *head;
    prev = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main(){
    node *head;
    int n;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    createLinkedList(&head, n);
    printf("\nBefore reversal:\n");
    displayList(head);
    reverseLinkedList(&head);
    printf("\nAfter reversal:\n");
    displayList(head);
    return 0;
}