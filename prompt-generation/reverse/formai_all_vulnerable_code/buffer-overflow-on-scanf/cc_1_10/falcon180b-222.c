//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct node{
    int data;
    struct node* next;
    struct node* child;
};

struct node* create(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    new_node->child=NULL;
    return new_node;
}

void add_child(struct node* parent,struct node* child){
    if(parent->child==NULL){
        parent->child=child;
    }
    else{
        struct node* temp=parent->child;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=child;
    }
}

void print_graph(struct node* root,int space){
    if(root==NULL){
        return;
    }
    space+=10;
    printf("\n");
    for(int i=0;i<space;i++){
        printf(" ");
    }
    printf("%d\n",root->data);
    for(int i=0;i<MAX;i++){
        if(root->child!=NULL && root->child->data==i){
            print_graph(root->child,space);
        }
    }
}

int main(){
    int choice,data;
    struct node* root=NULL;
    do{
        printf("\n1.Add Node");
        printf("\n2.Print Graph");
        printf("\n3.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("\nEnter the data:");
                scanf("%d",&data);
                root=create(data);
                break;
            }
            case 2:{
                print_graph(root,0);
                break;
            }
            case 3:{
                exit(0);
            }
            default:{
                printf("\nInvalid choice!");
            }
        }
    }while(choice!=3);
    return 0;
}