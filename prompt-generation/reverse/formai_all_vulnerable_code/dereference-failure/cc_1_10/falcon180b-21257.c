//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

void insert(node** head, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void delete(node** head, int key) {
    node* temp = *head;
    node* prev = NULL;

    if (temp!= NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void search(node* head, int key) {
    node* current = head;

    while (current!= NULL) {
        if (current->data == key)
            printf("%d found\n", key);
        current = current->next;
    }

    if (current == NULL)
        printf("%d not found\n", key);
}

void display(node* head) {
    node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("Linked list before deletion:\n");
    display(head);

    delete(&head, 3);
    printf("\nLinked list after deletion of 3:\n");
    display(head);

    search(head, 4);
    search(head, 6);

    return 0;
}