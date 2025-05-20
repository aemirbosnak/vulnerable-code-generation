//Falcon-180B DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 5
#define MAX_NAME_LENGTH 50

typedef struct node {
    char name[MAX_NAME_LENGTH];
    int age;
    int num_children;
    struct node *children[MAX_CHILDREN];
} Node;

Node *create_node(char *name, int age, int num_children) {
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->name, name);
    node->age = age;
    node->num_children = num_children;
    return node;
}

void add_child(Node *parent, Node *child) {
    int i;
    for (i = 0; i < parent->num_children; i++) {
        if (parent->children[i] == NULL) {
            parent->children[i] = child;
            break;
        }
    }
}

void print_family_tree(Node *node) {
    printf("Name: %s\n", node->name);
    printf("Age: %d\n", node->age);
    printf("Children:\n");
    int i;
    for (i = 0; i < node->num_children; i++) {
        if (node->children[i]!= NULL) {
            print_family_tree(node->children[i]);
        }
    }
}

int main() {
    Node *root = create_node("John", 35, 2);
    Node *child1 = create_node("Jane", 10, 0);
    Node *child2 = create_node("Jack", 8, 0);
    add_child(root, child1);
    add_child(root, child2);
    print_family_tree(root);
    return 0;
}