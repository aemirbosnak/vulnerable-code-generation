//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert(int data);
void delete(int data);
void print();

int main() {
    int choice, data;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Insert\n2. Delete\n3. Print\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted:\n");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the data to be deleted:\n");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                print();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void insert(int data) {
    node *new_node = (node *) malloc(sizeof(node));

    if (new_node == NULL) {
        printf("Memory error!\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node *temp = head;

        while (temp->next!= NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}

void delete(int data) {
    node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->data == data) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found!\n");
    } else {
        node *next = temp->next;
        free(temp);
        temp = next;
    }
}

void print() {
    node *temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}