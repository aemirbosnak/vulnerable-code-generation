//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX 10
#define PI 3.14159

struct node{
    int data;
    struct node* next;
};

struct node* create(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    if(!new_node){
        printf("Memory Error\n");
        exit(0);
    }
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void push(struct node** top_ref,int data){
    struct node* new_node=create(data);
    new_node->next=(*top_ref);
    (*top_ref)=new_node;
}

int pop(struct node** top_ref){
    struct node* top=*top_ref;
    int data=top->data;
    struct node* temp=top->next;
    free(top);
    (*top_ref)=temp;
    return data;
}

int peek(struct node* top){
    return top->data;
}

int is_empty(struct node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void display(struct node* top){
    while(top!=NULL){
        printf("%d ",top->data);
        top=top->next;
    }
}

void reverse(struct node** top_ref){
    struct node* prev=NULL;
    struct node* curr=*top_ref;
    while(curr!=NULL){
        struct node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    (*top_ref)=prev;
}

int main(){
    int choice,data;
    struct node* top=NULL;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Reverse\n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data:");
                scanf("%d",&data);
                push(&top,data);
                break;
            case 2:
                data=pop(&top);
                printf("Popped element is %d\n",data);
                break;
            case 3:
                data=peek(top);
                printf("Top element is %d\n",data);
                break;
            case 4:
                display(top);
                break;
            case 5:
                reverse(&top);
                printf("Stack reversed\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}