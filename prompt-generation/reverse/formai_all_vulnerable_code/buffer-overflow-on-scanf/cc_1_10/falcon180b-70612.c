//Falcon-180B DATASET v1.0 Category: Memory management ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

struct node{
    int data;
    struct node* next;
};

void addNode(struct node** head,int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void printList(struct node* head){
    while(head!= NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;
    int choice,data;

    do{
        printf("Enter your choice:\n");
        printf("1.Add Node\n");
        printf("2.Print List\n");
        printf("3.Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:{
                printf("Enter data to be added:\n");
                scanf("%d",&data);
                addNode(&head,data);
                break;
            }
            case 2:{
                printList(head);
                break;
            }
            case 3:{
                exit(0);
            }
            default:{
                printf("Invalid choice\n");
            }
        }
    }while(choice!= 3);

    return 0;
}