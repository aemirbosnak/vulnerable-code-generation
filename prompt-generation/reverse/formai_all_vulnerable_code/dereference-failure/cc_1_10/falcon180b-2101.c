//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int length;
    struct node *next;
} Node;

Node *head = NULL;

void createNode(char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->length = strlen(data);
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

void displayList() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteNode(char *data) {
    Node *temp = head;
    Node *prev = NULL;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

void searchNode(char *data) {
    Node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            printf("%s found at position %d\n", data, temp->length);
            break;
        }
        temp = temp->next;
    }
}

int main() {
    createNode("Romeo");
    createNode("Juliet");
    createNode("Capulet");
    createNode("Montague");
    displayList();
    deleteNode("Capulet");
    displayList();
    searchNode("Montague");
    return 0;
}