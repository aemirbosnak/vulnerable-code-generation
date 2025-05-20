//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertNode(struct node* head, int data){
    struct node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

void printList(struct node* head){
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node* searchElement(struct node* head, int element){
    struct node* current = head;
    while(current!=NULL){
        if(current->data == element){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main(){
    struct node* head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);
    printf("Original List:\n");
    printList(head);
    struct node* searchResult = searchElement(head, 3);
    if(searchResult!=NULL){
        printf("Element found at position %d\n", (int) (searchResult - head + 1));
    }
    else{
        printf("Element not found\n");
    }
    return 0;
}