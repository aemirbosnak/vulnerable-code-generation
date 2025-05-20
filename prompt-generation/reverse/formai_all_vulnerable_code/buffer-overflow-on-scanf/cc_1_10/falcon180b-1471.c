//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_STRING_LENGTH 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node **head, int data) {
    Node *new_node = create_node(data);
    Node *temp = *head;

    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    return;
}

void print_list(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search_node(Node *head, int data) {
    Node *temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    srand(time(NULL));

    Node *head = NULL;
    int choice, data;

    do {
        printf("1. Insert node\n");
        printf("2. Print list\n");
        printf("3. Search node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_node(&head, data);
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search_node(head, data)) {
                    printf("Data found\n");
                } else {
                    printf("Data not found\n");
                }
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