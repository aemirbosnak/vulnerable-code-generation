//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>

#define MAX 100

typedef struct node{
    int data;
    struct node *next;
}node;

node *head=NULL;

void addNode(int data){
    node *newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void deleteNode(int data){
    node *temp=head;
    node *prev=NULL;
    while(temp!=NULL && temp->data!=data){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Node not found\n");
        return;
    }
    if(prev==NULL){
        head=temp->next;
    }
    else{
        prev->next=temp->next;
    }
    free(temp);
}

void display(){
    node *temp=head;
    printf("Linked List:\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void *runner(void *param){
    int i;
    for(i=0;i<3;i++){
        addNode(i*10);
        sleep(1);
    }
    for(i=0;i<2;i++){
        deleteNode(i*10);
        sleep(1);
    }
    pthread_exit(0);
}

int main(){
    pthread_t thread[5];
    int i;
    for(i=0;i<5;i++){
        pthread_create(&thread[i],NULL,runner,NULL);
    }
    for(i=0;i<5;i++){
        pthread_join(thread[i],NULL);
    }
    display();
    return 0;
}