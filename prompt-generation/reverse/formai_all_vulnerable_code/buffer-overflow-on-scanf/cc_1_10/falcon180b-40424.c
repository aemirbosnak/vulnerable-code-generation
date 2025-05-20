//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(struct node** head, int data) {
    struct node* new_node = create_node(data);
    struct node* temp = *head;
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

void insert_at_beginning(struct node** head, int data) {
    struct node* new_node = create_node(data);
    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    new_node->next = *head;
    *head = new_node;
    return;
}

void delete_node(struct node** head, int key) {
    struct node* temp = *head;
    struct node* prev = NULL;
    if (temp!= NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

void search_element(struct node* head, int key) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (temp->data == key) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
    return;
}

int main() {
    struct node* head = NULL;
    int choice, key;

    do {
        printf("1. Insert at end\n");
        printf("2. Insert at beginning\n");
        printf("3. Delete node\n");
        printf("4. Search element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &key);
                insert_at_end(&head, key);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &key);
                insert_at_beginning(&head, key);
                break;
            case 3:
                printf("Enter the data to be deleted: ");
                scanf("%d", &key);
                delete_node(&head, key);
                break;
            case 4:
                printf("Enter the data to be searched: ");
                scanf("%d", &key);
                search_element(head, key);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}