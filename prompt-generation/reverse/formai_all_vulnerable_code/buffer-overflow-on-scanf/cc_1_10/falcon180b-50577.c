//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    char data[MAX_SIZE];
    int size;
    struct Node* next;
};

struct Node* createNode(char data[], int size) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, char data[], int size) {
    struct Node* newNode = createNode(data, size);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int searchNode(struct Node* head, char data[], int size) {
    struct Node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0 && temp->size == size) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, size;
    char data[MAX_SIZE];

    do {
        printf("Enter your choice:\n");
        printf("1. Insert node\n");
        printf("2. Search node\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert:\n");
                scanf("%s", data);
                printf("Enter size of data:\n");
                scanf("%d", &size);
                head = insertNode(head, data, size);
                break;
            case 2:
                printf("Enter data to search:\n");
                scanf("%s", data);
                printf("Enter size of data:\n");
                scanf("%d", &size);
                if (searchNode(head, data, size)) {
                    printf("Node found!\n");
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 3:
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}