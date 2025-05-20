//Code Llama-13B DATASET v1.0 Category: Building a XML Parser ; Style: Sherlock Holmes
// Building a XML Parser in the style of Sherlock Holmes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to store the XML document
typedef struct {
  char *name;
  char *value;
  struct node *next;
} node;

// Function to create a new node
node *create_node(char *name, char *value) {
  node *new_node = malloc(sizeof(node));
  new_node->name = name;
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

// Function to add a node to the end of the list
void add_node(node **head, node *new_node) {
  node *current = *head;
  if (current == NULL) {
    *head = new_node;
  } else {
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Function to parse the XML document
void parse_xml(char *xml_doc, node **head) {
  char *token = strtok(xml_doc, "><");
  while (token != NULL) {
    // Ignore empty tokens
    if (strlen(token) == 0) {
      token = strtok(NULL, "><");
      continue;
    }

    // Check if the token is a node name
    if (token[0] == '<') {
      // Create a new node with the node name and value
      node *new_node = create_node(token, NULL);

      // Add the node to the list
      add_node(head, new_node);
    } else {
      // Check if the token is a node value
      if (token[0] == '>') {
        // Get the current node and set its value
        node *current = *head;
        current->value = token;
      }
    }

    // Get the next token
    token = strtok(NULL, "><");
  }
}

// Function to print the parsed XML document
void print_xml(node *head) {
  node *current = head;
  while (current != NULL) {
    printf("%s: %s\n", current->name, current->value);
    current = current->next;
  }
}

int main() {
  // XML document
  char *xml_doc = "<name>John</name><age>30</age><city>New York</city>";

  // Parse the XML document
  node *head = NULL;
  parse_xml(xml_doc, &head);

  // Print the parsed XML document
  print_xml(head);

  return 0;
}