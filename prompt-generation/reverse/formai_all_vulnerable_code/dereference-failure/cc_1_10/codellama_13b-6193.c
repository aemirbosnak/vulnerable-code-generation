//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: Claude Shannon
/*
 * A unique C Data structures visualization example program in a Claude Shannon style
 */

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Define a structure for a tree
typedef struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
} Tree;

// Define a structure for a graph
typedef struct Graph {
    int data;
    struct Graph *adjacency_list[10];
} Graph;

// Define a structure for a queue
typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

// Define a structure for a stack
typedef struct Stack {
    int data;
    struct Stack *next;
} Stack;

// Function to create a new node in a linked list
Node *create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new tree
Tree *create_tree(int data) {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

// Function to create a new graph
Graph *create_graph(int data) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->data = data;
    for (int i = 0; i < 10; i++) {
        graph->adjacency_list[i] = NULL;
    }
    return graph;
}

// Function to create a new queue
Queue *create_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = NULL;
    queue->next = NULL;
    return queue;
}

// Function to create a new stack
Stack *create_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = NULL;
    stack->next = NULL;
    return stack;
}

// Function to insert a node into a linked list
void insert_node(Node *head, int data) {
    Node *node = create_node(data);
    node->next = head;
    head = node;
}

// Function to insert a tree into a tree
void insert_tree(Tree *root, int data) {
    Tree *node = create_tree(data);
    if (root->left == NULL) {
        root->left = node;
    } else {
        root->right = node;
    }
}

// Function to insert a graph into a graph
void insert_graph(Graph *graph, int data) {
    Graph *node = create_graph(data);
    graph->adjacency_list[data] = node;
}

// Function to insert a queue into a queue
void insert_queue(Queue *queue, int data) {
    Queue *node = create_queue();
    node->data = data;
    node->next = queue;
    queue = node;
}

// Function to insert a stack into a stack
void insert_stack(Stack *stack, int data) {
    Stack *node = create_stack();
    node->data = data;
    node->next = stack;
    stack = node;
}

// Function to traverse a linked list
void traverse_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to traverse a tree
void traverse_tree(Tree *root) {
    if (root != NULL) {
        traverse_tree(root->left);
        printf("%d ", root->data);
        traverse_tree(root->right);
    }
}

// Function to traverse a graph
void traverse_graph(Graph *graph) {
    for (int i = 0; i < 10; i++) {
        if (graph->adjacency_list[i] != NULL) {
            printf("%d ", graph->adjacency_list[i]->data);
        }
    }
    printf("\n");
}

// Function to traverse a queue
void traverse_queue(Queue *queue) {
    while (queue != NULL) {
        printf("%d ", queue->data);
        queue = queue->next;
    }
    printf("\n");
}

// Function to traverse a stack
void traverse_stack(Stack *stack) {
    while (stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int main() {
    // Linked list example
    Node *head = NULL;
    insert_node(head, 1);
    insert_node(head, 2);
    insert_node(head, 3);
    traverse_list(head);

    // Tree example
    Tree *root = create_tree(1);
    insert_tree(root, 2);
    insert_tree(root, 3);
    insert_tree(root, 4);
    traverse_tree(root);

    // Graph example
    Graph *graph = create_graph(1);
    insert_graph(graph, 2);
    insert_graph(graph, 3);
    insert_graph(graph, 4);
    traverse_graph(graph);

    // Queue example
    Queue *queue = create_queue();
    insert_queue(queue, 1);
    insert_queue(queue, 2);
    insert_queue(queue, 3);
    traverse_queue(queue);

    // Stack example
    Stack *stack = create_stack();
    insert_stack(stack, 1);
    insert_stack(stack, 2);
    insert_stack(stack, 3);
    traverse_stack(stack);

    return 0;
}