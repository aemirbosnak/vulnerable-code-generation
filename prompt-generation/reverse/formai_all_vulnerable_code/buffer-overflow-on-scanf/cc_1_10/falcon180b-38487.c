//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* searchList(Node* head, int key) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    int choice, data, key;

    while (true) {
        printf("\nLinked List Operations\n");
        printf("1. Insert element\n");
        printf("2. Display elements\n");
        printf("3. Search element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                head = createNode(data);
                if (head == NULL) {
                    printf("Memory error\n");
                    exit(0);
                }
                break;
            case 2:
                printf("Elements in the list are:\n");
                printList(head);
                break;
            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &key);
                Node* result = searchList(head, key);
                if (result == NULL)
                    printf("Element not found\n");
                else
                    printf("Element found\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}