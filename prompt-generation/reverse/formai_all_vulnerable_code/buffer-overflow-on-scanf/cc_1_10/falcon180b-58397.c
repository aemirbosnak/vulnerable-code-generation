//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//Node structure definition
struct Node{
    int data;
    struct Node* next;
};

//Function to create a new node with given data
struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//Function to add element at the rear of the queue
void enqueue(struct Node** frontRef,struct Node** rearRef,int data){
    struct Node* newNode=createNode(data);
    if(*rearRef==NULL){
        *frontRef=newNode;
        *rearRef=newNode;
    }
    else{
        (*rearRef)->next=newNode;
        *rearRef=newNode;
    }
}

//Function to remove element from the front of the queue
int dequeue(struct Node** frontRef,struct Node** rearRef){
    struct Node* temp=*frontRef;
    int data=temp->data;
    if(*frontRef==NULL){
        printf("Queue Underflow\n");
        exit(0);
    }
    else if(*frontRef==*rearRef){
        *frontRef=NULL;
        *rearRef=NULL;
    }
    else{
        *frontRef=temp->next;
    }
    free(temp);
    return data;
}

//Function to display the queue
void display(struct Node* front){
    printf("Queue elements are: ");
    while(front!=NULL){
        printf("%d ",front->data);
        front=front->next;
    }
}

int main(){
    struct Node* front=NULL;
    struct Node* rear=NULL;
    int choice,data;

    //Menu driven program to perform various operations on queue
    while(1){
        printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d",&data);
                enqueue(&front,&rear,data);
                break;

            case 2:
                data=dequeue(&front,&rear);
                printf("The deleted element is: %d\n",data);
                break;

            case 3:
                display(front);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}