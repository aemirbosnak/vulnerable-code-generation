//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct node {
    int key;
    struct node *next;
};

struct node *head = NULL;

void insert(int key) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->next = head;
    head = new_node;
}

void delete_node(struct node *node) {
    struct node *temp;
    temp = head;
    while (temp!= NULL && temp->next!= node) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found!\n");
        return;
    }
    temp->next = node->next;
    free(node);
}

void print_list() {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, key;
    struct node *temp;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter key %d: ", i+1);
        scanf("%d", &key);
        insert(key);
    }

    printf("List of keys:\n");
    print_list();

    printf("Enter key to delete: ");
    scanf("%d", &key);
    delete_node(head);

    printf("List of keys after deletion:\n");
    print_list();

    return 0;
}