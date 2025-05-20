//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Node {
  char name[MAX_NAME_LENGTH];
  struct Node* next;
} Node;

int main() {
  Node* head = NULL;
  char command[255];

  printf("Welcome to the C Database Simulator!\n");
  printf("Enter a command (help, add, delete, list): ");

  scanf("%s", command);

  // Implement the following commands:
  // - help: displays a list of available commands
  // - add: adds a new node to the database
  // - delete: deletes a node from the database
  // - list: lists all nodes in the database

  if (strcmp(command, "help") == 0) {
    printf("Available commands:\n");
    printf("  help: displays this help message\n");
    printf("  add: adds a new node to the database\n");
    printf("  delete: deletes a node from the database\n");
    printf("  list: lists all nodes in the database\n");
  } else if (strcmp(command, "add") == 0) {
    // Get the node's name
    char name[MAX_NAME_LENGTH];
    printf("Enter the node's name: ");
    scanf("%s", name);

    // Allocate memory for the node
    Node* newNode = malloc(sizeof(Node));

    // Copy the node's name into the structure
    strcpy(newNode->name, name);

    // Insert the node into the database
    if (head == NULL) {
      head = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }

    // Print a confirmation message
    printf("Node added successfully!\n");
  } else if (strcmp(command, "delete") == 0) {
    // Get the node's name
    char name[MAX_NAME_LENGTH];
    printf("Enter the node's name: ");
    scanf("%s", name);

    // Search for the node and delete it
    Node* previousNode = NULL;
    Node* currentNode = head;

    while (currentNode) {
      if (strcmp(currentNode->name, name) == 0) {
        if (previousNode) {
          previousNode->next = currentNode->next;
        } else {
          head = currentNode->next;
        }
        free(currentNode);
        printf("Node deleted successfully!\n");
        break;
      }
      previousNode = currentNode;
      currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
      printf("Node not found!\n");
    }
  } else if (strcmp(command, "list") == 0) {
    // List all nodes in the database
    Node* currentNode = head;

    while (currentNode) {
      printf("Name: %s\n", currentNode->name);
      currentNode = currentNode->next;
    }

    if (head == NULL) {
      printf("No nodes in the database.\n");
    }
  } else {
    printf("Invalid command.\n");
  }

  return 0;
}