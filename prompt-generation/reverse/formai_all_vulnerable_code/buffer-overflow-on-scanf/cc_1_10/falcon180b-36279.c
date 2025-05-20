//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10000
#define MAX_ELEMENTS 1000000

typedef struct node {
    int index;
    double val[2];
    struct node *next;
} Node;

typedef struct element {
    int index;
    double val[2];
    struct element *next;
} Element;

Node *nodes = NULL;
Element *elements = NULL;

void add_node(int index, double val1, double val2) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->index = index;
    new_node->val[0] = val1;
    new_node->val[1] = val2;
    new_node->next = nodes;
    nodes = new_node;
}

void add_element(int index, double val1, double val2) {
    Element *new_element = (Element *)malloc(sizeof(Element));
    new_element->index = index;
    new_element->val[0] = val1;
    new_element->val[1] = val2;
    new_element->next = elements;
    elements = new_element;
}

void solve() {
    Node *curr_node = nodes;
    while (curr_node!= NULL) {
        double sum = 0;
        int count = 0;
        Element *curr_element = elements;
        while (curr_element!= NULL) {
            if (curr_element->index == curr_node->index) {
                sum += curr_element->val[0];
                count++;
            }
            curr_element = curr_element->next;
        }
        if (count == 0) {
            printf("Error: Node %d has no elements\n", curr_node->index);
            exit(1);
        }
        curr_node->val[0] = sum / count;
        curr_node = curr_node->next;
    }
}

int main() {
    int num_nodes, num_elements;
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter number of elements: ");
    scanf("%d", &num_elements);

    for (int i = 0; i < num_nodes; i++) {
        double val1, val2;
        printf("Enter value for node %d: ", i);
        scanf("%lf %lf", &val1, &val2);
        add_node(i, val1, val2);
    }

    for (int i = 0; i < num_elements; i++) {
        int node1, node2;
        double val1, val2;
        printf("Enter values for element %d: ", i);
        scanf("%d %d %lf %lf", &node1, &node2, &val1, &val2);
        add_element(i, val1, val2);
        add_node(node1, val1, 0);
        add_node(node2, val2, 0);
    }

    solve();

    return 0;
}