//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

struct node{
    char name[50];
    int roll_no;
    struct node *next;
};

struct node *start=NULL;

void add_node(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter name: ");
    scanf("%s",newnode->name);
    printf("Enter roll no: ");
    scanf("%d",&newnode->roll_no);
    newnode->next=NULL;
    if(start==NULL){
        start=newnode;
    }
    else{
        struct node *temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void search_node(){
    char name[50];
    printf("Enter name to search: ");
    scanf("%s",name);
    struct node *temp=start;
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0){
            printf("Name: %s\nRoll no: %d",temp->name,temp->roll_no);
            return;
        }
        temp=temp->next;
    }
    printf("Record not found!");
}

void delete_node(){
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s",name);
    struct node *temp=start;
    struct node *prev=NULL;
    while(temp!=NULL && strcmp(temp->name,name)!=0){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Record not found!");
    }
    else{
        prev->next=temp->next;
        free(temp);
    }
}

void display(){
    struct node *temp=start;
    printf("\nName\tRoll no\n");
    while(temp!=NULL){
        printf("%s\t%d\n",temp->name,temp->roll_no);
        temp=temp->next;
    }
}

int main(){
    int ch;
    while(1){
        printf("\n1. Add node\n2. Search node\n3. Delete node\n4. Display\n5. Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                add_node();
                break;
            case 2:
                search_node();
                break;
            case 3:
                delete_node();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
    return 0;
}