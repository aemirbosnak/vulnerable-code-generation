//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    int length;
    struct node *next;
} Node;

Node *head = NULL;

void addNode(char *str) {
    int len = strlen(str);
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->length = len;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void search(char *str) {
    Node *temp = head;
    while (temp!= NULL) {
        if (strstr(temp->data, str)!= NULL) {
            printf("%s found in the list.\n", str);
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%s not found in the list.\n", str);
    }
}

int main() {
    addNode("apple");
    addNode("banana");
    addNode("orange");
    addNode("grape");
    addNode("pear");

    search("apple");
    search("mango");

    return 0;
}