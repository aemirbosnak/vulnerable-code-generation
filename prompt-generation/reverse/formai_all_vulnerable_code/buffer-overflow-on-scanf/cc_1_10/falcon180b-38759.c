//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(node** head, int data) {
    node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

int search(node* head, int key) {
    while (head!= NULL) {
        if (head->data == key)
            return 1;
        head = head->next;
    }
    return 0;
}

void deleteNode(node** head, int key) {
    node* temp = *head;
    node* prev = NULL;

    if (temp!= NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void display(node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int choice, data, key;

    do {
        printf("1. Add node\n");
        printf("2. Search node\n");
        printf("3. Delete node\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                if (search(head, key))
                    printf("Node found!\n");
                else
                    printf("Node not found.\n");
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}