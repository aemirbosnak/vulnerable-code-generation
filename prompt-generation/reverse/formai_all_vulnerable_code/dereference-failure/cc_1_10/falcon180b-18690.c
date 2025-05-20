//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node *next;
} Node;

Node *create_node(char *data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

Node *insert_node(Node *head, char *data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

Node *delete_node(Node *head, char *data) {
    Node *cur_node = head;
    Node *prev_node = NULL;

    while (cur_node!= NULL && strcmp(cur_node->data, data)!= 0) {
        prev_node = cur_node;
        cur_node = cur_node->next;
    }

    if (cur_node == NULL) {
        return head;
    }

    if (prev_node == NULL) {
        head = cur_node->next;
    } else {
        prev_node->next = cur_node->next;
    }

    free(cur_node);
    return head;
}

void print_list(Node *head) {
    Node *cur_node = head;

    while (cur_node!= NULL) {
        printf("%s ", cur_node->data);
        cur_node = cur_node->next;
    }

    printf("\n");
}

int main() {
    Node *head = NULL;

    head = insert_node(head, "apple");
    head = insert_node(head, "banana");
    head = insert_node(head, "cherry");

    print_list(head);

    head = delete_node(head, "banana");

    print_list(head);

    return 0;
}