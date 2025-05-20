//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_ITERATIONS 1000

typedef struct node {
    int value;
    struct node* next;
} node_t;

int main() {
    node_t* head = NULL;
    node_t* current = NULL;
    int num_nodes = 0;
    int num_iterations = 0;
    char input[MAX_LENGTH];

    while (1) {
        printf("Enter a value (or 'q' to quit): ");
        fgets(input, MAX_LENGTH, stdin);
        if (strcmp(input, "q") == 0) {
            break;
        }

        sscanf(input, "%d", &num_nodes);
        if (num_nodes == 0) {
            num_iterations++;
        }

        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        if (new_node == NULL) {
            printf("Memory allocation failed\n");
            continue;
        }

        new_node->value = num_nodes;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            current = new_node;
        }

        printf("Created node with value %d\n", new_node->value);
    }

    printf("Visualizing the linked list:\n");
    current = head;
    while (current!= NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");

    printf("Number of iterations: %d\n", num_iterations);

    free(head);
    return 0;
}