//FormAI DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct list{
    Node *head;
    int size;
}List;

List* createList(){
    List *pList=(List*)malloc(sizeof(List));
    if(pList==NULL){
        printf("Memory Allocation Failed!!!");
        exit(1);
    }
    pList->head=NULL;
    pList->size=0;
    return pList;
}

void insert(List *pList,int data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memory Allocation Failed!!!");
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    
    if(pList->head==NULL){
        pList->head=newNode;
    }else{
        Node *temp=pList->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("\nInserted %d Successfully!\n",data);
    pList->size+=1;
}

void delete(List *pList,int data){
    if(pList->head==NULL){
        printf("List is Empty!\n");
        return;
    }
    Node *temp=pList->head;
    Node *prev=NULL;
    while(temp!=NULL && temp->data!=data){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("%d not Found!\n",data);
        return;
    }else if(prev==NULL){
        pList->head=temp->next;
    }else{
        prev->next=temp->next;
    }
    printf("\nDeleted %d Successfully!\n",data);
    pList->size-=1;
    free(temp);
}

void display(List *pList){
    if(pList->head==NULL){
        printf("List is Empty!\n");
        return;
    }
    Node *temp=pList->head;
    printf("\tList Size : %d\n",pList->size);
    printf("\t[");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
        if(temp!=NULL){
            printf(",");
        }
    }
    printf("]\n");
}

void menu(){
    printf("\n******************************\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display\n");
    printf("4.Quit");
    printf("\n******************************\n");
}

int main(){
    List *pList=createList();
    int choice,data;
    while(1){
        menu();
        printf("Enter your Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                    printf("Enter the Value to be Inserted : ");
                    scanf("%d",&data);
                    insert(pList,data);
                    break;
            case 2:
                    printf("Enter the Value to be Deleted : ");
                    scanf("%d",&data);
                    delete(pList,data);
                    break;
            case 3:
                    display(pList);
                    break;
            case 4:
                    printf("Thank You!");
                    exit(0);
            default:
                    printf("Invalid Choice!");
        }
    }
    return 0;
}