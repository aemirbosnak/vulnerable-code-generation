//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    char data[MAX_SIZE];
    int length;
    struct Node *next;
};

struct Node *createNode(char *data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->length = strlen(data);
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node *head, struct Node *newNode) {
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void searchNode(struct Node *head, char *data) {
    struct Node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            printf("Data found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Data not found.\n");
}

int main() {
    struct Node *head = NULL;
    int choice, length;
    char data[MAX_SIZE];

    while (1) {
        printf("1. Insert data\n2. Search data\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%s", data);
            length = strlen(data);
            insertNode(head, createNode(data));
            break;
        case 2:
            printf("Enter data to search: ");
            scanf("%s", data);
            searchNode(head, data);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}