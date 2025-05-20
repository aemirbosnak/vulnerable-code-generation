//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char *str;
    struct node *next;
} Node;

void push(Node **head, char *str) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->str = strdup(str);
    new_node->next = *head;
    *head = new_node;
}

void pop(Node **head) {
    Node *temp = *head;
    *head = (*head)->next;
    free(temp->str);
    free(temp);
}

void print_list(Node *head) {
    while (head!= NULL) {
        printf("%s ", head->str);
        head = head->next;
    }
}

void reverse_list(Node *head) {
    Node *prev = NULL;
    Node *curr = head;
    while (curr!= NULL) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    Node *head = NULL;
    char input[100];

    while (1) {
        printf("Enter a string: ");
        scanf("%s", input);
        push(&head, input);
        printf("Current list: ");
        print_list(head);
        printf("\n");
    }

    return 0;
}