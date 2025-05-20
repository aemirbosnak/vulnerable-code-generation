//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node* temp = head;

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void print_list() {
    struct node* temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;

    do {
        printf("\n1. Insert an element\n2. Print the list\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(data);
                break;

            case 2:
                print_list();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice!= 3);

    return 0;
}