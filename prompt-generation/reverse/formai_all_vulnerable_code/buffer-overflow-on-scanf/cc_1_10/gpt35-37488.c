//FormAI DATASET v1.0 Category: Syntax parsing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char value;
    struct node* next;
} node_t;

node_t* create_node(char value) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}

void free_nodes(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        node_t* temp = current;
        current = current->next;
        free(temp);
    }
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    char input[100];
    printf("Enter the C syntax: ");
    scanf("%s", input);
    
    node_t* head = create_node(input[0]);
    node_t* current = head;
    for (int i=1; input[i] != '\0'; i++) {
        if (is_operator(input[i])) {
            current->next = create_node(input[i]);
            current = current->next;
        }
    }
    
    current = head;
    printf("Operators in the C syntax: ");
    while (current != NULL) {
        printf("%c ", current->value);
        current = current->next;
    }
    printf("\n");
    
    free_nodes(head);
    
    return 0;
}