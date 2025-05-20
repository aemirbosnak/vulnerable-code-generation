//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node* next;
};

void addNode(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
    }
    else {
        struct node* temp = *head;
        while(temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int searchNode(struct node* head, int data) {
    struct node* temp = head;

    while(temp!= NULL) {
        if(temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

void deleteNode(struct node** head, int data) {
    struct node* temp = *head;
    struct node* prev = NULL;

    if(temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    struct node* head = NULL;

    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    printf("Before deletion:\n");
    struct node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    deleteNode(&head, 4);

    printf("After deletion:\n");
    temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    int searchData = 3;
    if(searchNode(head, searchData)) {
        printf("Data found in the list!\n");
    }
    else {
        printf("Data not found in the list.\n");
    }

    return 0;
}