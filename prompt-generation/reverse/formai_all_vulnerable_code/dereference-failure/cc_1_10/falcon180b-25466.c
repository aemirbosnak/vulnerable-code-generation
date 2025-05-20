//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char data[MAX_SIZE];
    int length;
    struct node* next;
};

typedef struct node Node;

Node* createNode(char* data, int length) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->length = length;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* head, Node* newNode) {
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void search(Node* head, char* data, int length) {
    if (head == NULL) {
        printf("Data not found!\n");
        return;
    }
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->length == length && strcmp(temp->data, data) == 0) {
            printf("Data found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Data not found!\n");
}

int main() {
    Node* head = NULL;
    char* data = "Hello World!";
    int length = strlen(data);
    head = createNode(data, length);
    printf("Data inserted!\n");
    search(head, data, length);
    return 0;
}