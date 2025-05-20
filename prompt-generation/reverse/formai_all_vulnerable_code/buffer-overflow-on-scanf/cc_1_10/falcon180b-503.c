//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertNode(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    struct node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void searchNode(struct node* head, int key) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (temp->data == key) {
            printf("Key found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Key not found\n");
}

int main() {
    struct node* head = NULL;
    int choice, data, key;

    do {
        printf("Enter 1 to insert a node\n");
        printf("Enter 2 to search for a node\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to be inserted\n");
            scanf("%d", &data);
            head = insertNode(head, data);
            break;
        case 2:
            printf("Enter the key to be searched\n");
            scanf("%d", &key);
            searchNode(head, key);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}