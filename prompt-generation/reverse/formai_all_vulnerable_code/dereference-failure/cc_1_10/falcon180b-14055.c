//Falcon-180B DATASET v1.0 Category: Sorting ; Style: curious
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//Node structure for linked list
struct Node{
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** start_ref, int data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if(*start_ref == NULL){
        new_node->next = new_node;
        *start_ref = new_node;
    }
    else{
        struct Node* last = *start_ref;
        while(last->next!= *start_ref){
            last = last->next;
        }
        last->next = new_node;
        new_node->next = *start_ref;
    }
}

void printList(struct Node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    struct Node* start = NULL;
    int arr[MAX] = {1, 3, 5, 7, 9};
    int i;

    for(i=0; i<MAX; i++){
        insertAtEnd(&start, arr[i]);
    }

    printf("Sorted array: ");
    printList(start);

    return 0;
}