//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
  char data;
  struct node *next;
} Node;

typedef struct stack {
  Node *top;
  int size;
} Stack;

typedef struct queue {
  Node *front;
  Node *rear;
  int size;
} Queue;

typedef struct linked_list {
  Node *head;
  Node *tail;
  int size;
} LinkedList;

typedef struct binary_tree {
  char data;
  struct binary_tree *left;
  struct binary_tree *right;
} BinaryTree;

void push(Stack *stack, char data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = stack->top;
  stack->top = new_node;
  stack->size++;
}

char pop(Stack *stack) {
  if (stack->size == 0) {
    printf("Stack is empty!\n");
    return '\0';
  }
  Node *temp = stack->top;
  stack->top = stack->top->next;
  char data = temp->data;
  free(temp);
  stack->size--;
  return data;
}

void enqueue(Queue *queue, char data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  if (queue->rear == NULL) {
    queue->front = queue->rear = new_node;
  } else {
    queue->rear->next = new_node;
    queue->rear = new_node;
  }
  queue->size++;
}

char dequeue(Queue *queue) {
  if (queue->size == 0) {
    printf("Queue is empty!\n");
    return '\0';
  }
  Node *temp = queue->front;
  queue->front = queue->front->next;
  char data = temp->data;
  free(temp);
  queue->size--;
  return data;
}

void insert_at_head(LinkedList *list, char data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = list->head;
  list->head = new_node;
  list->size++;
}

void insert_at_tail(LinkedList *list, char data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  if (list->tail == NULL) {
    list->head = list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->size++;
}

char delete_at_head(LinkedList *list) {
  if (list->size == 0) {
    printf("List is empty!\n");
    return '\0';
  }
  Node *temp = list->head;
  list->head = list->head->next;
  char data = temp->data;
  free(temp);
  list->size--;
  return data;
}

char delete_at_tail(LinkedList *list) {
  if (list->size == 0) {
    printf("List is empty!\n");
    return '\0';
  }
  Node *temp = list->head;
  while (temp->next != list->tail) {
    temp = temp->next;
  }
  char data = list->tail->data;
  free(list->tail);
  list->tail = temp;
  list->tail->next = NULL;
  list->size--;
  return data;
}

void insert_in_binary_tree(BinaryTree **tree, char data) {
  if (*tree == NULL) {
    *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    (*tree)->data = data;
    (*tree)->left = NULL;
    (*tree)->right = NULL;
  } else if (data <= (*tree)->data) {
    insert_in_binary_tree(&(*tree)->left, data);
  } else {
    insert_in_binary_tree(&(*tree)->right, data);
  }
}

void print_stack(Stack *stack) {
  printf("Stack: ");
  Node *temp = stack->top;
  while (temp != NULL) {
    printf("%c ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void print_queue(Queue *queue) {
  printf("Queue: ");
  Node *temp = queue->front;
  while (temp != NULL) {
    printf("%c ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void print_linked_list(LinkedList *list) {
  printf("Linked List: ");
  Node *temp = list->head;
  while (temp != NULL) {
    printf("%c ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void print_binary_tree(BinaryTree *tree) {
  if (tree == NULL) {
    return;
  }
  printf("%c ", tree->data);
  print_binary_tree(tree->left);
  print_binary_tree(tree->right);
}

int main() {
  Stack stack;
  stack.top = NULL;
  stack.size = 0;
  Queue queue;
  queue.front = queue.rear = NULL;
  queue.size = 0;
  LinkedList list;
  list.head = list.tail = NULL;
  list.size = 0;
  BinaryTree *tree = NULL;

  char input[MAX_SIZE];
  printf("Enter a string: ");
  scanf("%s", input);

  for (int i = 0; i < strlen(input); i++) {
    push(&stack, input[i]);
    enqueue(&queue, input[i]);
    insert_at_head(&list, input[i]);
    insert_in_binary_tree(&tree, input[i]);
  }

  printf("\nOriginal String: %s\n", input);

  printf("\nStack:\n");
  print_stack(&stack);

  printf("\nQueue:\n");
  print_queue(&queue);

  printf("\nLinked List:\n");
  print_linked_list(&list);

  printf("\nBinary Tree:\n");
  print_binary_tree(tree);

  printf("\nReversed String (using stack): ");
  while (stack.size > 0) {
    printf("%c", pop(&stack));
  }

  printf("\nReversed String (using queue): ");
  while (queue.size > 0) {
    printf("%c", dequeue(&queue));
  }

  printf("\nReversed String (using linked list): ");
  while (list.size > 0) {
    printf("%c", delete_at_head(&list));
  }

  printf("\nBinary Tree (in-order traversal): ");
  print_binary_tree(tree);

  return 0;
}