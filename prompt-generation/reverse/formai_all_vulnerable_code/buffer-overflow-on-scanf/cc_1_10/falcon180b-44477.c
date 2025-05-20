//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node* next;
};

void insertNode(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int searchNode(struct node* head, int data) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct node* head = NULL;
    int choice, data;
    while (1) {
        printf("1. Insert\n2. Print\n3. Search\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (searchNode(head, data)) {
                    printf("Data found!\n");
                } else {
                    printf("Data not found.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}