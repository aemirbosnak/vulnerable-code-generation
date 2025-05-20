//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    int index;
    struct node* next;
};

void insertNode(struct node* head, int data, int index) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->index = index;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct node* temp = head;
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
}

void search(struct node* head, int searchElement) {
    struct node* temp = head;
    int count = 0;
    while (temp!= NULL) {
        if (temp->data == searchElement) {
            printf("Element found at index %d\n", temp->index);
            return;
        }
        temp = temp->next;
        count++;
        if (count == MAX_SIZE) {
            printf("Element not found\n");
            return;
        }
    }
    printf("Element not found\n");
}

int main() {
    struct node* head = NULL;
    int choice, data, index;
    char ch;

    do {
        printf("1. Insert\n2. Search\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter index: ");
                scanf("%d", &index);
                insertNode(head, data, index);
                printf("Node inserted\n");
                break;
            case 2:
                printf("Enter search element: ");
                scanf("%d", &data);
                search(head, data);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}