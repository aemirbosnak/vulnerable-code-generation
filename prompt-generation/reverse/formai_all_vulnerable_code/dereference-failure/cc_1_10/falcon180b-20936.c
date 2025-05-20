//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

//struct to represent a node in a linked list
struct node{
    int data;
    struct node* next;
};

//function to create a new node with given data
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to add a node at the end of the linked list
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

//function to print the linked list
void printList(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//function to sort the linked list using bucket sort
void bucketSort(struct node** head){
    int max = 0;
    struct node* temp = *head;
    while(temp!= NULL){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }
    int bucketSize = max/MAX_SIZE + 1;
    int* bucket[MAX_SIZE];
    for(int i=0; i<MAX_SIZE; i++){
        bucket[i] = (int*)malloc(sizeof(int)*bucketSize);
    }
    temp = *head;
    while(temp!= NULL){
        int bucketIndex = temp->data/bucketSize;
        addNode(&bucket[bucketIndex], temp->data);
        temp = temp->next;
    }
    int j = 0;
    temp = *head;
    while(temp!= NULL){
        for(int i=0; i<bucketSize; i++){
            if(bucket[i][j]!= -1){
                temp->data = bucket[i][j];
                j++;
                break;
            }
        }
        temp = temp->next;
    }
    for(int i=0; i<MAX_SIZE; i++){
        free(bucket[i]);
    }
}

//main function to test the linked list and bucket sort functions
int main(){
    struct node* head = NULL;
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);
    printList(head);
    bucketSort(&head);
    printList(head);
    return 0;
}