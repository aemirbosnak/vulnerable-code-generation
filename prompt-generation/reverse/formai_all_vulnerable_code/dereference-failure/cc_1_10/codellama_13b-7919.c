//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: genius
// Genius Memory Management Program in C

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_node(struct Node** head, int data) {
    struct Node* node = create_node(data);
    node->next = *head;
    *head = node;
}

void delete_node(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Data not found\n");
    } else {
        if (prev == NULL) {
            *head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}

void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);
    delete_node(&head, 3);
    print_list(head);
    delete_node(&head, 1);
    print_list(head);
    delete_node(&head, 5);
    print_list(head);
    delete_node(&head, 4);
    print_list(head);
    delete_node(&head, 2);
    print_list(head);
    return 0;
}