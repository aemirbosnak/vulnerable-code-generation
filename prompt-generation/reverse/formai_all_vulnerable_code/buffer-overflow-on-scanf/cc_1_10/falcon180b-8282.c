//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct Node *temp = head;

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

int search(int data) {
    struct Node *temp = head;

    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

void delete(int data) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL) {
        if (temp->data == data) {
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("Empty List\n");
        return;
    }

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted:\n");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter the data to be searched:\n");
                scanf("%d", &data);
                if (search(data)) {
                    printf("Data found!\n");
                } else {
                    printf("Data not found!\n");
                }
                break;
            case 3:
                printf("Enter the data to be deleted:\n");
                scanf("%d", &data);
                delete(data);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}