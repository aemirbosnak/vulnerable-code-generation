//Falcon-180B DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
    char *data;
    struct Node *next;
};

struct Node *head = NULL;

void append(char *data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error: Out of memory\n");
        exit(0);
    }
    newNode->data = (char *) malloc(strlen(data) + 1);
    if (newNode->data == NULL) {
        printf("Memory error: Out of memory\n");
        exit(0);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList() {
    struct Node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = (struct Node *) malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Memory error: Out of memory\n");
        exit(0);
    }
    head->data = (char *) malloc(MAX_SIZE);
    if (head->data == NULL) {
        printf("Memory error: Out of memory\n");
        exit(0);
    }
    head->next = NULL;
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        append("String ");
    }
    printList();
    return 0;
}