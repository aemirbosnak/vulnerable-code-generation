//Falcon-180B DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void add_node(Node** head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void delete_node(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void reverse_list(Node** head) {
    Node* curr = *head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

int main() {
    srand(time(NULL));

    Node* head = NULL;

    for (int i = 0; i < MAX_SIZE; i++) {
        int data = rand() % 100;
        add_node(&head, data);
    }

    printf("Original list:\n");
    print_list(head);

    reverse_list(&head);

    printf("Reversed list:\n");
    print_list(head);

    int search_data = rand() % 100;
    delete_node(&head, search_data);

    printf("List after deleting %d:\n", search_data);
    print_list(head);

    return 0;
}