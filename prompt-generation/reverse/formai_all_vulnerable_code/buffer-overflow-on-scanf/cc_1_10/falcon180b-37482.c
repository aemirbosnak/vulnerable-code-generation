//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
    } else {
        printf("List elements: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void search(int data) {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
    } else {
        while (temp!= NULL) {
            if (temp->data == data) {
                printf("Element found at position %d\n", temp->data);
                return;
            }
            temp = temp->next;
        }
        printf("Element not found\n");
    }
}

int main() {
    int choice, data;

    do {
        printf("1. Insert element\n");
        printf("2. Display list\n");
        printf("3. Search element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter element to be searched: ");
                scanf("%d", &data);
                search(data);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}