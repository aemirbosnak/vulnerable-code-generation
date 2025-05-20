//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} node;

void insert(node** head, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int search(node* head, int key) {
    node* current = head;
    while (current!= NULL) {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    node* head = NULL;
    int choice, data, key;

    printf("Linked List Implementation\n");
    printf("1. Insert\n2. Print\n3. Search\n4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                printf("Enter the key: ");
                scanf("%d", &key);
                if (search(head, key)) {
                    printf("Key found\n");
                } else {
                    printf("Key not found\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}