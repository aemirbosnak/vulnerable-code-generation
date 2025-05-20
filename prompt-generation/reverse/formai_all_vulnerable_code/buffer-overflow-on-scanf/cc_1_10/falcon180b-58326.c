//Falcon-180B DATASET v1.0 Category: Recursive ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* node){
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
}

void push(struct Node** headRef,int newData){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=newData;
    newNode->next=(*headRef);
    (*headRef)=newNode;
}

void mergeSort(struct Node* head){
    struct Node* second=NULL;
    struct Node* rest=NULL;
    struct Node* first=head;
    while(first!=NULL && first->next!=NULL){
        second=first;
        while(second->next!=NULL && second->next!=first){
            second=second->next;
        }
        rest=second->next;
        second->next=NULL;
        push(&first,second->data);
        first=rest;
    }
    push(&first,second->data);
}

int main(){
    struct Node* head=NULL;
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        int elem;
        scanf("%d",&elem);
        push(&head,elem);
    }
    printf("The original list is:\n");
    printList(head);
    mergeSort(head);
    printf("\nThe sorted list is:\n");
    printList(head);
    return 0;
}