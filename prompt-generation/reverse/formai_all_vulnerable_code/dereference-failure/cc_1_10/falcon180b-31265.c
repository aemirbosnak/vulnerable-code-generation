//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node *insertNode(struct node *head, int data) {
    struct node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    struct node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct node *deleteNode(struct node *head, int data) {
    struct node *temp = head;
    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp!= NULL) {
        if (temp->data == data) {
            temp->next = temp->next->next;
            free(temp->next);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

void printList(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int searchElement(struct node *head, int data) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct node *head = NULL;
    head = insertNode(head, 10);
    head = insertNode(head, 20);
    head = insertNode(head, 30);
    head = insertNode(head, 40);
    head = insertNode(head, 50);

    printf("Original list:\n");
    printList(head);

    head = deleteNode(head, 20);

    printf("List after deleting 20:\n");
    printList(head);

    if (searchElement(head, 30)) {
        printf("30 is present in the list\n");
    } else {
        printf("30 is not present in the list\n");
    }

    return 0;
}