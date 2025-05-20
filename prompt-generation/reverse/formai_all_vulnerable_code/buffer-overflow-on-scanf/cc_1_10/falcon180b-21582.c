//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    if (head == NULL) {
        head = newNode;
        return head;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    do {
        printf("Enter your choice:\n");
        printf("1. Insert element\n2. Display list\n3. Search element\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data:\n");
                scanf("%d", &data);
                head = insertNode(head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter key to search:\n");
                scanf("%d", &key);
                if (searchElement(head, key)) {
                    printf("Key found!\n");
                } else {
                    printf("Key not found!\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}