//FormAI DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
} NODE;

NODE *front = NULL, *rear = NULL;

void Push(int item){
    NODE *temp;
    temp = (NODE*)malloc(sizeof(NODE));
    temp -> data = item;
    temp -> link = NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
        return;
    }
    rear -> link = temp;
    rear = temp;
}

void Pop(){
    NODE *temp = front;
    if(front == NULL){
        printf("Underflow");
        return;
    }
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front -> link;
    }
    free(temp);
}

void Display(){
    NODE *temp = front;
    if(front == NULL){
        printf("Queue is empty");
        return;
    }
    while(temp != NULL){
        printf("%d\t", temp -> data);
        temp = temp -> link;
    }
}

int main(){
    int ch, item;
    while(1){
        printf("\n\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("\nEnter the element to be inserted: ");
                    scanf("%d", &item);
                    Push(item);
                    break;
            case 2: Pop();
                    break;
            case 3: Display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("\nInvalid choice. Please enter a valid choice.");
        }
    }
    return 0;
}