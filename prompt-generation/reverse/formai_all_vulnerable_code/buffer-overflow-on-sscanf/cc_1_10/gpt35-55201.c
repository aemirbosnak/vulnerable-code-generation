//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100 // Maximum number of circuit nodes
#define MAX_NAME_LENGTH 10 // Maximum length of a node name

typedef struct node {
  char name[MAX_NAME_LENGTH];
  int value;
} Node;

Node nodes[MAX_NODES]; // All circuit nodes
int numNodes = 0; // Number of nodes in the circuit

int findNode(char* name) {
  for (int i = 0; i < numNodes; i++) {
    if (strcmp(name, nodes[i].name) == 0) {
      return i;
    }
  }
  return -1;
}

void addNode(char* name, int value) {
  int index = findNode(name);
  if (index >= 0) {
    printf("Node %s already exists.\n", name);
    return;
  }
  if (numNodes >= MAX_NODES) {
    printf("Cannot add more nodes. Maximum number of nodes reached.\n");
    return;
  }
  strcpy(nodes[numNodes].name, name);
  nodes[numNodes].value = value;
  numNodes++;
  printf("Node %s added with value %d.\n", name, value);
}

void updateNode(char* name, int value) {
  int index = findNode(name);
  if (index < 0) {
    printf("Node %s does not exist.\n", name);
    return;
  }
  nodes[index].value = value;
  printf("Node %s updated with value %d.\n", name, value);
}

void simulateCircuit() {
  // TODO: Implement circuit simulation logic
  printf("Circuit simulation complete.\n");
}

void printNodes() {
  printf("Current circuit nodes:\n");
  for (int i = 0; i < numNodes; i++) {
    printf("%s = %d\n", nodes[i].name, nodes[i].value);
  }
}

int main() {
  printf("Welcome to the C Circuit Simulator!\n");
  printf("Commands:\n");
  printf("add <name> <value>: Add a new circuit node.\n");
  printf("update <name> <value>: Update the value of an existing node.\n");
  printf("simulate: Simulate the circuit.\n");
  printf("nodes: List all current circuit nodes.\n");
  printf("exit: Exit the program.\n");
  
  while (1) {
    char input[50];
    char command[10], name[MAX_NAME_LENGTH];
    int value;
    printf(">> ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s %s %d", command, name, &value);
    if (strcmp(command, "add") == 0) {
      addNode(name, value);
    } else if (strcmp(command, "update") == 0) {
      updateNode(name, value);
    } else if (strcmp(command, "simulate") == 0) {
      simulateCircuit();
    } else if (strcmp(command, "nodes") == 0) {
      printNodes();
    } else if (strcmp(command, "exit") == 0) {
      exit(0);
    } else {
      printf("Invalid command.\n");
    }
  }
  return 0;
}