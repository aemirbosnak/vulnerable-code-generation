//Falcon-180B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void addNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        struct Node *ptr = head;
        while (ptr->next!= NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void displayList() {
    struct Node *ptr = head;
    printf("List: ");
    while (ptr!= NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void deleteNode(int data) {
    struct Node *temp = head;
    struct Node *prev = NULL;
    if (temp!= NULL) {
        if (temp->data == data) {
            head = temp->next;
            free(temp);
            return;
        }
        while (temp!= NULL && temp->data!= data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Node not found\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    } else {
        printf("List is empty\n");
    }
}

int main() {
    addNode(1);
    addNode(2);
    addNode(3);
    displayList();
    deleteNode(2);
    displayList();
    deleteNode(1);
    displayList();
    deleteNode(3);
    displayList();
    return 0;
}