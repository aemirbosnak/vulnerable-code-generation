//Falcon-180B DATASET v1.0 Category: File handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[100];
    struct node* next;
};

void append(struct node** head, char* str) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->data, str);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void prepend(struct node** head, char* str) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->data, str);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    new_node->next = *head;
    *head = new_node;
}

void delete_node(struct node** head, char* str) {
    struct node* temp = *head;

    if (temp!= NULL && strcmp(temp->data, str) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && strcmp(temp->data, str)!= 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    struct node* prev = temp->next;
    free(temp);
    prev->next = temp->next;
}

void print_list(struct node* head) {
    while (head!= NULL) {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;

    append(&head, "Hello");
    append(&head, "World");

    prepend(&head, "Claude");

    print_list(head);

    delete_node(&head, "World");

    print_list(head);

    return 0;
}