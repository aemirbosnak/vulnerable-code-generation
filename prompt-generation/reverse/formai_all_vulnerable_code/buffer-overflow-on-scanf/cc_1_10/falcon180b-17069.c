//Falcon-180B DATASET v1.0 Category: File handling ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head=NULL;

void insert(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}

void display(){
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int choice;
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL){
        printf("File not found\n");
        exit(0);
    }
    char ch;
    while((ch=fgetc(fp))!=EOF){
        if(isdigit(ch)){
            insert(ch-'0');
        }
    }
    fclose(fp);
    printf("Enter your choice:\n1.Display\n2.Exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            display();
            break;
        case 2:
            exit(0);
        default:
            printf("Invalid choice\n");
    }
    return 0;
}