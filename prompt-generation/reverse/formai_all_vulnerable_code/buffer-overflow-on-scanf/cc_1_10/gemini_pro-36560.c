//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a node for the linked list
typedef struct node {
  char *word;
  int count;
  struct node *next;
} node_t;

// Create a new node
node_t *create_node(char *word) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->word = strdup(word);
  new_node->count = 1;
  new_node->next = NULL;
  return new_node;
}

// Insert a node into the linked list
void insert_node(node_t **head, node_t *new_node) {
  if (*head == NULL) {
    *head = new_node;
  } else {
    node_t *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Search for a node in the linked list
node_t *search_node(node_t *head, char *word) {
  node_t *current = head;
  while (current != NULL) {
    if (strcmp(current->word, word) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// Count the words in a string
int count_words(char *str) {
  int count = 0;
  char *word;

  // Get the first word
  word = strtok(str, " ");

  // While there are more words
  while (word != NULL) {
    // Increment the count
    count++;

    // Get the next word
    word = strtok(NULL, " ");
  }

  return count;
}

// Print the contents of the linked list
void print_list(node_t *head) {
  node_t *current = head;
  while (current != NULL) {
    printf("%s: %d\n", current->word, current->count);
    current = current->next;
  }
}

// Free the memory allocated for the linked list
void free_list(node_t *head) {
  node_t *current = head;
  while (current != NULL) {
    node_t *next = current->next;
    free(current->word);
    free(current);
    current = next;
  }
}

int main() {
  // Get the input string
  char *str = malloc(1000);
  printf("Enter a string: ");
  scanf("%[^\n]", str);

  // Count the words in the string
  int word_count = count_words(str);

  // Create a linked list to store the words
  node_t *head = NULL;

  // Get the first word
  char *word = strtok(str, " ");

  // While there are more words
  while (word != NULL) {
    // Search for the word in the linked list
    node_t *node = search_node(head, word);

    // If the word is not found
    if (node == NULL) {
      // Create a new node
      node = create_node(word);

      // Insert the node into the linked list
      insert_node(&head, node);
    } else {
      // Increment the count of the node
      node->count++;
    }

    // Get the next word
    word = strtok(NULL, " ");
  }

  // Print the contents of the linked list
  print_list(head);

  // Free the memory allocated for the linked list
  free_list(head);

  // Free the memory allocated for the string
  free(str);

  return 0;
}