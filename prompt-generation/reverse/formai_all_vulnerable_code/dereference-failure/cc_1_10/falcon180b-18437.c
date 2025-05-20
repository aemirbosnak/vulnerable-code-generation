//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_list(int size);
void print_list(Node *list);
void delete_list(Node *list);

int main() {
    int size;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    Node *list = create_list(size);
    print_list(list);
    delete_list(list);

    return 0;
}

Node *create_list(int size) {
    Node *list = (Node *)malloc(sizeof(Node));
    list->data = 0;
    list->next = NULL;

    int i;
    for (i = 1; i < size; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = i;
        new_node->next = NULL;
        list->next = new_node;
        list = new_node;
    }

    return list;
}

void print_list(Node *list) {
    while (list!= NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
}

void delete_list(Node *list) {
    while (list!= NULL) {
        Node *temp = list;
        list = list->next;
        free(temp);
    }
}