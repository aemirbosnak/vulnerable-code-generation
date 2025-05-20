//Falcon-180B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *create_node(char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Out of memory!\n");
        exit(1);
    }
    new_node->data = strdup(data);
    new_node->next = NULL;
    return new_node;
}

void delete_node(Node *node) {
    free(node->data);
    free(node);
}

void print_list(Node *list) {
    while (list!= NULL) {
        printf("%s -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

int main() {
    Node *list = NULL;
    char *data;

    printf("Enter data to add to the list (enter 'done' to stop):\n");
    while (scanf("%s", data) == 1 && strcmp(data, "done")!= 0) {
        list = create_node(data);
        if (list == NULL) {
            printf("Out of memory!\n");
            exit(1);
        }
        list = list->next;
    }

    printf("List:\n");
    print_list(list);

    while (list!= NULL) {
        Node *temp = list;
        list = list->next;
        delete_node(temp);
    }

    printf("List deleted.\n");

    return 0;
}