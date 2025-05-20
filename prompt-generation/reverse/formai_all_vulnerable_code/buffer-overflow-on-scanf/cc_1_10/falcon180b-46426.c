//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

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

int main() {
    int choice, data;

    while (1) {
        printf("Enter 1 to insert element\n");
        printf("Enter 2 to search element\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            printf("Enter element to search: ");
            scanf("%d", &data);
            if (search(data)) {
                printf("%d found\n", data);
            } else {
                printf("%d not found\n", data);
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}