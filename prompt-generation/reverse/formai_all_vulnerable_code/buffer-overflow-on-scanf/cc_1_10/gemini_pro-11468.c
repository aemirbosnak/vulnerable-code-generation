//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE (MAX_INPUT_SIZE * 2)

struct node {
    char c;
    int count;
    struct node *next;
};

struct node *create_node(char c, int count) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->c = c;
    new_node->count = count;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node **head, struct node *new_node) {
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

int compare_nodes(const void *a, const void *b) {
    struct node *node_a = *(struct node **)a;
    struct node *node_b = *(struct node **)b;
    return node_b->count - node_a->count;
}

char *compress(char *input) {
    int input_size = strlen(input);
    int output_size = 0;

    // Create a frequency table
    int frequency_table[256] = {0};
    for (int i = 0; i < input_size; i++) {
        frequency_table[input[i]]++;
    }

    // Create a linked list of nodes
    struct node *head = NULL;
    for (int i = 0; i < 256; i++) {
        if (frequency_table[i] > 0) {
            insert_node(&head, create_node(i, frequency_table[i]));
        }
    }

    // Sort the linked list in descending order of frequency
    struct node *nodes[256];
    int i = 0;
    while (head != NULL) {
        nodes[i++] = head;
        head = head->next;
    }

    qsort(nodes, i, sizeof(struct node *), compare_nodes);

    // Create the compressed output
    char *output = malloc(MAX_OUTPUT_SIZE);
    output_size = 0;
    for (int i = 0; i < i; i++) {
        for (int j = 0; j < nodes[i]->count; j++) {
            output[output_size++] = nodes[i]->c;
        }
    }

    output[output_size] = '\0';
    return output;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter the input string: ");
    scanf("%s", input);

    char *output = compress(input);
    printf("The compressed string is: %s\n", output);

    free(output);
    return 0;
}