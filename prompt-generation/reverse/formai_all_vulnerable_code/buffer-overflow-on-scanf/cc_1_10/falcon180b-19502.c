//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    int value;
    struct Node *next;
};

struct Node *head = NULL;

void addNode(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory Error\n");
        exit(0);
    }
    newNode->value = value;
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

int search(int value) {
    struct Node *temp = head;
    while (temp!= NULL) {
        if (temp->value == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int choice, value;
    while (1) {
        printf("\n\t\t\t\tSearching Algorithm\n");
        printf("\n1. Add Node\n2. Search Node\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                addNode(value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(value)) {
                    printf("Node found\n");
                }
                else {
                    printf("Node not found\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}