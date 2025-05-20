//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct node{
    char data[100];
    int count;
    struct node* next;
}node;

node* createnode(char* data){
    node* newnode=malloc(sizeof(node));
    strcpy(newnode->data,data);
    newnode->count=1;
    newnode->next=NULL;
    return newnode;
}

void addnode(node** head,char* data){
    node* newnode=createnode(data);
    if(*head==NULL){
        *head=newnode;
        return;
    }
    node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void printlist(node* head){
    node* temp=head;
    while(temp!=NULL){
        printf("%s %d\n",temp->data,temp->count);
        temp=temp->next;
    }
}

int hash(char* data){
    int sum=0;
    for(int i=0;i<strlen(data);i++){
        sum+=data[i];
    }
    return sum%100;
}

void rehash(node** head){
    node* temp=*head;
    int size=0;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    int newsize=size*2;
    node** newtable=malloc(sizeof(node*)*newsize);
    memset(newtable,0,sizeof(node*)*newsize);
    temp=*head;
    while(temp!=NULL){
        int index=hash(temp->data)%newsize;
        temp->next=newtable[index];
        newtable[index]=temp;
        temp=temp->next;
    }
    free(*head);
    *head=newtable;
}

int main(){
    srand(time(NULL));
    node* head=NULL;
    char data[100];
    int choice,size=10;
    while(1){
        printf("\n1.Add element\n2.Display\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter element: ");
                scanf("%s",data);
                addnode(&head,data);
                if(++size%100==0){
                    rehash(&head);
                }
                break;
            }
            case 2:{
                printf("\nElements are:\n");
                printlist(head);
                break;
            }
            case 3:{
                exit(0);
            }
            default:{
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}