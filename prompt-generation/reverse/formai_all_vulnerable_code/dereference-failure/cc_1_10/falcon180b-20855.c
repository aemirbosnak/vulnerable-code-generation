//Falcon-180B DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
    int size;
};

void initLinkedList(struct LinkedList *list) {
    list->head = NULL;
    list->size = 0;
}

int isEmptyLinkedList(struct LinkedList *list) {
    return list->head == NULL;
}

void addNodeToLinkedList(struct LinkedList *list, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isEmptyLinkedList(list)) {
        list->head = newNode;
    } else {
        struct Node *temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

void deleteNodeFromLinkedList(struct LinkedList *list, int data) {
    if (isEmptyLinkedList(list)) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = list->head;
    if (temp->data == data) {
        list->head = temp->next;
        free(temp);
        list->size--;
        return;
    }
    while (temp->next!= NULL) {
        if (temp->next->data == data) {
            struct Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
            list->size--;
            return;
        }
        temp = temp->next;
    }
    printf("Node not found\n");
}

void printLinkedList(struct LinkedList *list) {
    if (isEmptyLinkedList(list)) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList myList;
    initLinkedList(&myList);
    addNodeToLinkedList(&myList, 5);
    addNodeToLinkedList(&myList, 10);
    addNodeToLinkedList(&myList, 15);
    printLinkedList(&myList);
    deleteNodeFromLinkedList(&myList, 10);
    printLinkedList(&myList);
    deleteNodeFromLinkedList(&myList, 5);
    printLinkedList(&myList);
    deleteNodeFromLinkedList(&myList, 15);
    printLinkedList(&myList);
    return 0;
}