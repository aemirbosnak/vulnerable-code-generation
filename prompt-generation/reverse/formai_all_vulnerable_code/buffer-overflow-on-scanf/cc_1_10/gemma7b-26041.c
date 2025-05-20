//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

typedef struct Node {
  char **commands;
  struct Node *next;
} Node;

Node *head = NULL;

void addCommand(char *command) {
  Node *newNode = malloc(sizeof(Node));
  newNode->commands = malloc(MAX_CMD_LEN * sizeof(char *));

  int i = 0;
  for (newNode->commands[i] = NULL; i < MAX_CMD_LEN - 1; i++) {
    if (command[i] == '\0') {
      newNode->commands[i] = command;
      break;
    } else {
      newNode->commands[i] = &command[i];
    }
  }

  if (head == NULL) {
    head = newNode;
  } else {
    Node *temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void executeCommand(char *command) {
  for (Node *node = head; node; node) {
    for (int i = 0; node->commands[i] != NULL; i++) {
      if (strcmp(node->commands[i], command) == 0) {
        system(node->commands[i + 1]);
        break;
      }
    }
  }
}

int main() {
  char command[MAX_CMD_LEN];

  printf("Welcome to the Dragon's Lair Shell!\n");

  while (1) {
    printf("$ ");
    scanf("%s", command);

    if (strcmp(command, "exit") == 0) {
      break;
    }

    executeCommand(command);
  }

  return 0;
}