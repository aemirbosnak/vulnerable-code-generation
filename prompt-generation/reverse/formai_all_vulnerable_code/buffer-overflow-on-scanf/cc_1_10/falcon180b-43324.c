//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct node{
    int data;
    struct node *next;
} Node;

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** head, int data){
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head){
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    int arr[MAX_SIZE];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    Node *head = NULL;
    Node *tail = NULL;

    for(i=0; i<n; i++){
        if(head == NULL){
            head = createNode(arr[i]);
            tail = head;
        }else if(arr[i] == arr[i-1]){
            tail->next = createNode(arr[i]);
            tail = tail->next;
        }else{
            push(&head, arr[i]);
            tail = tail->next;
        }
    }

    printf("Sorted array is: ");
    printList(head);

    return 0;
}