//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

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

void printlist() {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search(int data) {
    struct node *temp = head;
    int found = 0;
    while (temp!= NULL) {
        if (temp->data == data) {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found) {
        printf("Element found!\n");
    } else {
        printf("Element not found.\n");
    }
    return found;
}

int main() {
    int choice, data;
    while (1) {
        printf("\n1. Insert\n2. Print\n3. Search\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printlist();
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}