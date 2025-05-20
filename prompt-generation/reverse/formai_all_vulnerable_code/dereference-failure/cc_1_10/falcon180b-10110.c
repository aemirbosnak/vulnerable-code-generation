//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    char data[MAX_SIZE];
    int size;
    struct node* next;
} node;

node* createNode(char data[], int size) {
    node* newNode = (node*) malloc(sizeof(node));
    strcpy(newNode->data, data);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

void insertNode(node** head, char data[], int size) {
    node* newNode = createNode(data, size);
    if(*head == NULL) {
        *head = newNode;
    } else {
        node* temp = *head;
        while(temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void searchNode(node* head, char data[], int size) {
    node* temp = head;
    while(temp!= NULL) {
        if(strncmp(temp->data, data, size) == 0) {
            printf("Data found: %s\n", temp->data);
            return;
        }
        temp = temp->next;
    }
    printf("Data not found.\n");
}

int main() {
    node* head = NULL;
    char data[] = "Hello World";
    int size = strlen(data);

    insertNode(&head, data, size);

    searchNode(head, data, size);

    return 0;
}