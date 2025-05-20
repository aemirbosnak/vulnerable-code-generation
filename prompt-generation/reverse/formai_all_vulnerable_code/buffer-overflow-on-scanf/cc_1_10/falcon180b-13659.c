//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    struct node* temp = *head;

    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int search(struct node* head, int key) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\n1. Insert element\n2. Display elements\n3. Search element\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &key);
                if (search(head, key))
                    printf("\nElement found!");
                else
                    printf("\nElement not found!");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }

    return 0;
}