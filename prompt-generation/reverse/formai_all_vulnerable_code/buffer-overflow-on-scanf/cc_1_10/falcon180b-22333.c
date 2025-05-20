//Falcon-180B DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Memory error\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;

        while (temp->next!= NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}

void delete(int data) {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    if (temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element not found\n");
        return;
    }

    struct node *del_node = temp->next;
    temp->next = temp->next->next;
    free(del_node);
}

void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, data;

    do {
        printf("Enter 1 to insert an element\n");
        printf("Enter 2 to delete an element\n");
        printf("Enter 3 to display the list\n");
        printf("Enter 4 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            insert(data);
            break;

        case 2:
            printf("Enter the element to be deleted: ");
            scanf("%d", &data);
            delete(data);
            break;

        case 3:
            display();
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