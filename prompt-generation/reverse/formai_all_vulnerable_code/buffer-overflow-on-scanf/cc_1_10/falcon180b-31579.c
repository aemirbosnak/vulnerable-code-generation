//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct Node{
    char data[MAX_SIZE];
    int count;
    struct Node* next;
};

struct Node* createNode(char data[]){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, char data[]){
    struct Node* newNode = *head;
    while(newNode!= NULL && strcmp(newNode->data, data)!= 0){
        newNode = newNode->next;
    }
    if(newNode == NULL){
        newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
    }
    else{
        newNode->count++;
    }
}

void search(struct Node* head, char data[]){
    struct Node* current = head;
    while(current!= NULL){
        if(strcmp(current->data, data) == 0){
            printf("%s found at position %d\n", data, current->count);
            return;
        }
        current = current->next;
    }
    printf("%s not found\n", data);
}

int main(){
    struct Node* head = NULL;
    char searchData[MAX_SIZE];
    printf("Enter the string to search: ");
    scanf("%s", searchData);
    search(head, searchData);
    return 0;
}