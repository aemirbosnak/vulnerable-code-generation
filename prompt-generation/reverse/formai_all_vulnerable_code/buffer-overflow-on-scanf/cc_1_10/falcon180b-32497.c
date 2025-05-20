//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node *next;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
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

void display(struct node *head) {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *search(struct node *head, int key) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    int n, key;
    struct node *head = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        head = insertNode(head, data);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    struct node *result = search(head, key);
    if (result!= NULL) {
        printf("Element found\n");
    } else {
        printf("Element not found\n");
    }
    return 0;
}