//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void create(struct Node** start_ref,int data){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
    if(*start_ref==NULL){
        *start_ref=new_node;
        return;
    }
    struct Node* last=*start_ref;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
}

void delete(struct Node** start_ref,int key){
    struct Node* temp=*start_ref;
    struct Node* prev=NULL;
    if(temp!=NULL&&temp->data==key){
        *start_ref=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }
    prev->next=temp->next;
    free(temp);
}

void search(struct Node* start,int key){
    struct Node* curr=start;
    while(curr!=NULL){
        if(curr->data==key){
            printf("Element found\n");
            return;
        }
        curr=curr->next;
    }
    printf("Element not found\n");
}

void display(struct Node* start){
    struct Node* curr=start;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}

int main(){
    struct Node* start=NULL;
    int choice,data,key;
    do{
        printf("Enter your choice:\n");
        printf("1.Create\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter the data:\n");
                scanf("%d",&data);
                create(&start,data);
                break;
            }
            case 2:{
                printf("Enter the data to be deleted:\n");
                scanf("%d",&key);
                delete(&start,key);
                break;
            }
            case 3:{
                printf("Enter the data to be searched:\n");
                scanf("%d",&key);
                search(start,key);
                break;
            }
            case 4:{
                display(start);
                break;
            }
            case 5:{
                exit(0);
            }
            default:{
                printf("Invalid choice\n");
            }
        }
    }while(1);
    return 0;
}