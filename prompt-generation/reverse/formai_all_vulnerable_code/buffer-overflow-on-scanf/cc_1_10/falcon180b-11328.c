//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void addNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void searchNode(int data) {
    struct node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            printf("%d found!\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found.\n", data);
}

int main() {
    int choice, data;

    while (1) {
        printf("Enter 1 to add a node, 2 to search a node, or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                addNode(data);
                break;
            case 2:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                searchNode(data);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}