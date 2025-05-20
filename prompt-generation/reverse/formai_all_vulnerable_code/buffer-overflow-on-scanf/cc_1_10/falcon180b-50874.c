//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_NODE_COUNT 1000

typedef struct node {
    char key[MAX_KEY_LENGTH];
    int value;
    struct node *children[MAX_NODE_COUNT];
    int count;
} Node;

Node *create_node(char *key, int value) {
    Node *node = malloc(sizeof(Node));
    strcpy(node->key, key);
    node->value = value;
    node->count = 1;
    memset(node->children, 0, sizeof(node->children));
    return node;
}

void insert_key(Node *node, char *key, int value) {
    if (strlen(key) == 1) {
        node->value += value;
        return;
    }
    int index = *key;
    if (node->children[index] == NULL) {
        node->children[index] = create_node(key + 1, value);
    } else {
        insert_key(node->children[index], key + 1, value);
    }
}

void print_tree(Node *node, int space) {
    if (node == NULL) {
        return;
    }
    printf("%*s%s (%d)\n", space, "", node->key, node->value);
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        if (node->children[i]!= NULL) {
            print_tree(node->children[i], space + 4);
        }
    }
}

int main() {
    Node *root = create_node("", 0);
    char key[MAX_KEY_LENGTH];
    while (scanf("%s", key)!= EOF) {
        int value = 1;
        insert_key(root, key, value);
    }
    print_tree(root, 0);
    return 0;
}