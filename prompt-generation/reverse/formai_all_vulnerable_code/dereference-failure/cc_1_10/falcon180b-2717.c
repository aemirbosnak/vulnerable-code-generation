//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insert(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

int search(int data) {
    Node *temp = head;

    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int main() {
    int choice, data;

    printf("Enter 1 to insert a node\n");
    printf("Enter 2 to search for a node\n");

    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        insert(data);
    } else if (choice == 2) {
        printf("Enter the data to be searched: ");
        scanf("%d", &data);
        if (search(data)) {
            printf("Node found!\n");
        } else {
            printf("Node not found!\n");
        }
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}