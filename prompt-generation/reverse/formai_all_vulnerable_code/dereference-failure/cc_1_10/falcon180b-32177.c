//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
struct node {
    char data[MAX_SIZE];
    struct node* next;
};

void insert_node(struct node** head, char* val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->data, val);
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

void delete_node(struct node** head, char* val) {
    struct node* temp = *head;
    struct node* prev = NULL;

    if (temp!= NULL && strcmp(temp->data, val) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && strcmp(temp->data, val)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display_list(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int search_list(struct node* head, char* val) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, val) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    struct node* head = NULL;

    insert_node(&head, "apple");
    insert_node(&head, "banana");
    insert_node(&head, "cherry");

    printf("Original list:\n");
    display_list(head);

    delete_node(&head, "banana");

    printf("List after deleting 'banana':\n");
    display_list(head);

    int result = search_list(head, "cherry");
    if (result == 1) {
        printf("'cherry' found in the list.\n");
    } else {
        printf("'cherry' not found in the list.\n");
    }

    return 0;
}