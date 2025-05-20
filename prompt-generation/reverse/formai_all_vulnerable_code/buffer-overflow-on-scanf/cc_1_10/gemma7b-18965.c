//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

int main() {
  Node *head = NULL;
  char buffer[MAX_BUFFER_SIZE];

  // Create a directory for the backups
  mkdir("backup", 0755);

  // Loop until the user enters "quit"
  while (1) {
    // Get the user input
    printf("Enter file name or 'quit': ");
    scanf("%s", buffer);

    // Check if the user wants to quit
    if (strcmp(buffer, "quit") == 0) {
      break;
    }

    // Create a new node
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(buffer);
    newNode->next = head;
    head = newNode;

    // Backup the file
    FILE *file = fopen(buffer, "r");
    if (file) {
      int fileSize = 0;
      while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        fileSize++;
      }
      fclose(file);

      char *backupFile = malloc(fileSize);
      file = fopen(buffer, "r");
      if (file) {
        rewind(file);
        fread(backupFile, fileSize, 1, file);
        fclose(file);

        // Save the backup file
        FILE *backup = fopen(strcat("backup/", buffer), "w");
        if (backup) {
          fwrite(backupFile, fileSize, 1, backup);
          fclose(backup);
        }
      }
    }
  }

  // Free the memory
  while (head) {
    Node *next = head->next;
    free(head);
    head = next;
  }

  return 0;
}