//Falcon-180B DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1000
#define MAX_TREE_DEPTH 10
#define NODE_COUNT 10

typedef struct node {
    int count;
    int is_leaf;
    struct node *children[NODE_COUNT];
} Node;

Node *create_node() {
    Node *node = malloc(sizeof(Node));
    node->count = 0;
    node->is_leaf = 0;
    for (int i = 0; i < NODE_COUNT; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void destroy_node(Node *node) {
    for (int i = 0; i < NODE_COUNT; i++) {
        destroy_node(node->children[i]);
    }
    free(node);
}

void insert_data(Node *node, char *data) {
    if (node->is_leaf) {
        node->count++;
        return;
    }

    int index = data[0] - 'a';
    if (node->children[index] == NULL) {
        node->children[index] = create_node();
    }

    insert_data(node->children[index], data);
}

void traverse_tree(Node *node, char *prefix) {
    if (node->is_leaf) {
        printf("%s: %d\n", prefix, node->count);
        return;
    }

    for (int i = 0; i < NODE_COUNT; i++) {
        if (node->children[i]!= NULL) {
            char next_char = (char) ('a' + i);
            traverse_tree(node->children[i], strcat(strcat(prefix, next_char), ""));
        }
    }
}

int main() {
    char data[MAX_DATA_SIZE];
    int data_count = 0;

    printf("Enter data (type 'done' when finished):\n");
    while (fgets(data, MAX_DATA_SIZE, stdin)!= NULL) {
        if (strcmp(data, "done") == 0) {
            break;
        }
        insert_data(create_node(), data);
        data_count++;
    }

    printf("Data count: %d\n", data_count);
    printf("Data:\n");
    traverse_tree(create_node(), "");

    return 0;
}