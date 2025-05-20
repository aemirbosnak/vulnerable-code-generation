//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Create a struct to store the word count data
typedef struct {
  int count;
  char *word;
} WordCount;

// Create a linked list to store the word count data
typedef struct Node {
  WordCount data;
  struct Node *next;
} Node;

// Create a new node with the given word and count
Node *create_node(char *word, int count) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data.word = word;
  new_node->data.count = count;
  new_node->next = NULL;
  return new_node;
}

// Insert a new node into the linked list in sorted order
void insert_node(Node **head, Node *new_node) {
  if (*head == NULL || (*head)->data.count <= new_node->data.count) {
    new_node->next = *head;
    *head = new_node;
  } else {
    Node *current = *head;
    while (current->next != NULL && current->next->data.count > new_node->data.count) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

// Print the linked list of word count data
void print_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%s: %d\n", current->data.word, current->data.count);
    current = current->next;
  }
}

// Free the linked list of word count data
void free_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    Node *next = current->next;
    free(current->data.word);
    free(current);
    current = next;
  }
}

// Count the words in the given file and store the results in a linked list
Node *count_words(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Create a linked list to store the word count data
  Node *head = NULL;

  // Read the file line by line
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    // Tokenize the line into words
    char *token = strtok(line, " ");
    while (token != NULL) {
      // Convert the token to lowercase
      char *lower_token = strdup(token);
      for (int i = 0; lower_token[i]; i++) {
        lower_token[i] = tolower(lower_token[i]);
      }

      // Find the node for the word or create a new one if it doesn't exist
      Node *node = head;
      while (node != NULL && strcmp(node->data.word, lower_token) != 0) {
        node = node->next;
      }
      if (node == NULL) {
        node = create_node(lower_token, 0);
        insert_node(&head, node);
      }

      // Increment the count for the word
      node->data.count++;

      // Get the next token
      token = strtok(NULL, " ");
    }
  }

  // Close the file
  fclose(file);

  // Return the linked list of word count data
  return head;
}

// Print the top 10 most common words in the given linked list
void print_top_10(Node *head) {
  // Create an array to store the top 10 words
  Node *top_10[10];
  for (int i = 0; i < 10; i++) {
    top_10[i] = NULL;
  }

  // Iterate over the linked list and update the top 10 words
  Node *current = head;
  while (current != NULL) {
    // Find the smallest word in the top 10
    Node *smallest = NULL;
    for (int i = 0; i < 10; i++) {
      if (top_10[i] == NULL || top_10[i]->data.count < current->data.count) {
        smallest = top_10[i];
      }
    }

    // If the smallest word is NULL or has a smaller count than the current word,
    // then replace the smallest word with the current word
    if (smallest == NULL || smallest->data.count < current->data.count) {
      for (int i = 0; i < 10; i++) {
        if (top_10[i] == smallest) {
          top_10[i] = current;
          break;
        }
      }
    }

    // Move to the next word in the linked list
    current = current->next;
  }

  // Print the top 10 words
  printf("Top 10 most common words:\n");
  for (int i = 0; i < 10; i++) {
    printf("%s: %d\n", top_10[i]->data.word, top_10[i]->data.count);
  }
}

// Main function
int main() {
  // Get the filename from the user
  char filename[1024];
  printf("Enter the filename: ");
  scanf("%s", filename);

  // Count the words in the file
  Node *head = count_words(filename);

  // Print the top 10 most common words
  print_top_10(head);

  // Free the linked list of word count data
  free_list(head);

  return 0;
}