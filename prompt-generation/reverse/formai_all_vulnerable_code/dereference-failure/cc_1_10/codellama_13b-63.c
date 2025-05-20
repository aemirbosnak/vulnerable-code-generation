//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: scientific
/*
 * Program: Unique C Data Structures Visualization Example
 * Description: A program that demonstrates the use of unique C data structures
 *              such as linked lists, stacks, queues, and trees.
 */

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct node {
    int data;
    struct node *next;
};

// Stack structure
struct stack {
    int size;
    struct node *top;
};

// Queue structure
struct queue {
    int size;
    struct node *front;
    struct node *rear;
};

// Tree node structure
struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
};

// Function to create a new linked list node
struct node* create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new stack
struct stack* create_stack(int size) {
    struct stack *new_stack = malloc(sizeof(struct stack));
    new_stack->size = size;
    new_stack->top = NULL;
    return new_stack;
}

// Function to create a new queue
struct queue* create_queue(int size) {
    struct queue *new_queue = malloc(sizeof(struct queue));
    new_queue->size = size;
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

// Function to create a new tree
struct tree_node* create_tree(int data) {
    struct tree_node *new_tree = malloc(sizeof(struct tree_node));
    new_tree->data = data;
    new_tree->left = NULL;
    new_tree->right = NULL;
    return new_tree;
}

// Function to add a node to a linked list
void add_node(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        *head = new_node;
    }
}

// Function to add a node to a stack
void push(struct stack *stack, int data) {
    struct node *new_node = create_node(data);
    if (stack->size == 0) {
        stack->top = new_node;
    } else {
        new_node->next = stack->top;
        stack->top = new_node;
    }
    stack->size++;
}

// Function to add a node to a queue
void enqueue(struct queue *queue, int data) {
    struct node *new_node = create_node(data);
    if (queue->size == 0) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

// Function to add a node to a tree
void add_node_tree(struct tree_node **root, int data) {
    struct tree_node *new_node = create_tree(data);
    if (*root == NULL) {
        *root = new_node;
    } else {
        struct tree_node *current = *root;
        while (current != NULL) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = new_node;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = new_node;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

// Function to traverse a linked list
void traverse_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to traverse a stack
void traverse_stack(struct stack *stack) {
    struct node *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to traverse a queue
void traverse_queue(struct queue *queue) {
    struct node *current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to traverse a tree
void traverse_tree(struct tree_node *root) {
    if (root != NULL) {
        traverse_tree(root->left);
        printf("%d ", root->data);
        traverse_tree(root->right);
    }
}

int main() {
    // Linked list example
    struct node *head = NULL;
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    traverse_list(head);

    // Stack example
    struct stack *stack = create_stack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    traverse_stack(stack);

    // Queue example
    struct queue *queue = create_queue(3);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    traverse_queue(queue);

    // Tree example
    struct tree_node *root = NULL;
    add_node_tree(&root, 1);
    add_node_tree(&root, 2);
    add_node_tree(&root, 3);
    traverse_tree(root);

    return 0;
}