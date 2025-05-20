//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct node{
    char data[MAX];
    int count;
    struct node* next;
};

struct node* createNode(){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data,"");
    newNode->count = 0;
    newNode->next = NULL;
    return newNode;
}

void insert(struct node** head, char data[], int count){
    struct node* newNode = createNode();
    strcpy(newNode->data,data);
    newNode->count = count;
    newNode->next = *head;
    *head = newNode;
}

void search(struct node* head, char data[], int count){
    struct node* current = head;
    printf("Searching for %s...\n",data);
    while(current!= NULL){
        if(strcmp(current->data,data) == 0){
            printf("Found %s %d times\n",data,current->count);
            return;
        }
        current = current->next;
    }
    printf("Not found\n");
}

int main(){
    struct node* head = NULL;
    char data[MAX];
    int count;
    while(1){
        printf("Enter a string to search: ");
        scanf("%s",data);
        printf("Enter the number of times to search: ");
        scanf("%d",&count);
        insert(&head,data,count);
    }
    return 0;
}