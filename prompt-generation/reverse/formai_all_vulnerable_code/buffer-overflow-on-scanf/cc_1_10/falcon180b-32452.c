//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

node*createNode(int data){
    node*newNode=malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void addNode(node**head,int data){
    node*newNode=createNode(data);
    newNode->next=*head;
    *head=newNode;
}

void deleteNode(node**head,int key){
    node*temp=*head,*prev=NULL;
    if(temp!=NULL&&temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL) return;
    prev->next=temp->next;
    free(temp);
}

void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int search(node*head,int key){
    node*temp=head;
    while(temp!=NULL){
        if(temp->data==key)
            return 1;
        temp=temp->next;
    }
    return 0;
}

void reverse(node**head){
    node*prev=NULL,*next=NULL,*temp=*head;
    *head=NULL;
    while(temp!=NULL){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    *head=prev;
}

int main(){
    node*head=NULL;
    int choice,data;
    do{
        printf("\nEnter your choice\n1.Add node\n2.Delete node\n3.Search node\n4.Display\n5.Reverse\n6.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to be added\n");
                scanf("%d",&data);
                addNode(&head,data);
                break;
            case 2:
                printf("Enter data to be deleted\n");
                scanf("%d",&data);
                deleteNode(&head,data);
                break;
            case 3:
                printf("Enter data to be searched\n");
                scanf("%d",&data);
                if(search(head,data))
                    printf("%d is found\n",data);
                else
                    printf("%d is not found\n",data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                reverse(&head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(1);
    return 0;
}