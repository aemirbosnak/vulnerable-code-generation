//FormAI DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

int main() {
    Node *vertices = NULL;
    int num_vertices, num_edges;
    printf("Welcome to the surreal world of Graphs!\n");
    printf("How many vertices would you like in your graph?\n");
    scanf("%d", &num_vertices);
    printf("How about edges? (just give me a number, I'll take care of the rest)\n");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_vertices; i++) {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = i;
        new_node->next = vertices;
        vertices = new_node;
    }

    printf("Perfect! We have our graph, now let's add some edges.\n");
    printf("Just give me pairs of vertices separated by a space and I'll connect them.\n");

    for (int i = 0; i < num_edges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);

        Node *from_node = vertices;
        Node *to_node = vertices;

        for (int j = 0; j < num_vertices; j++) {
            if (from_node && from_node->data == from) {
                break;
            }
            from_node = from_node->next;
        }

        for (int j = 0; j < num_vertices; j++) {
            if (to_node && to_node->data == to) {
                break;
            }
            to_node = to_node->next;
        }

        if (from_node && to_node) {
            Node *new_edge = malloc(sizeof(Node));
            new_edge->data = to;
            new_edge->next = from_node->next;
            from_node->next = new_edge;
        }
    }

    printf("Amazing! Our surreal graph is ready to be traversed!\n");
    printf("What starting vertex would you like?\n");

    int start_vertex;
    scanf("%d", &start_vertex);

    Node *current_node = vertices;

    for (int i = 0; i < num_vertices; i++) {
        if (current_node && current_node->data == start_vertex) {
            break;
        }
        current_node = current_node->next;
    }

    if (!current_node) {
        printf("That's a no-go. We couldn't find that vertex. Let's start from the beginning.\n");
        current_node = vertices;
    }

    printf("Great! Let's start the surreal traversal.\n");
    printf("Visiting vertex %d\n", current_node->data);

    for (Node *neighbour = current_node->next; neighbour; neighbour = neighbour->next) {
        printf("Visiting vertex %d\n", neighbour->data);
    }

    printf("That's it! Thanks for visiting our surreal graph.\n");

    return 0;
}