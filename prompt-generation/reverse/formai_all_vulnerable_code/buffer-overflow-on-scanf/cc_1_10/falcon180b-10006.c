//Falcon-180B DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void insert(node** start_ref,int data){
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    if(*start_ref==NULL){
        *start_ref=new_node;
        return;
    }
    node* last=*start_ref;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
    return;
}

void print_list(node* node){
    while(node!=NULL){
        printf("%d ",node->data);
        node=node->next;
    }
}

int main(){
    node* start=NULL;
    int choice,data;
    do{
        printf("\n1.Insert\n2.Print\n3.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the data:");
                scanf("%d",&data);
                insert(&start,data);
                break;
            case 2:
                print_list(start);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }while(choice!=3);
    return 0;
}