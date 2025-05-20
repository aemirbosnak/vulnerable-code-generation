//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
/*
 * File Synchronizer: A Romeo and Juliet style program
 *
 * This program reads two files, one containing Romeo's messages and the other
 * containing Juliet's messages. It then compares the messages and outputs
 * the unique messages to a third file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100

// Structure to store messages
typedef struct {
  char message[MAX_MESSAGE_LENGTH];
} Message;

// Function to read messages from a file
int read_messages(const char *filename, Message *messages, int *num_messages) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    printf("Error opening file %s\n", filename);
    return 1;
  }

  *num_messages = 0;

  while (fscanf(fp, "%s", messages[*num_messages].message) == 1) {
    (*num_messages)++;
  }

  fclose(fp);

  return 0;
}

// Function to write messages to a file
int write_messages(const char *filename, Message *messages, int num_messages) {
  FILE *fp = fopen(filename, "w");
  if (!fp) {
    printf("Error opening file %s\n", filename);
    return 1;
  }

  for (int i = 0; i < num_messages; i++) {
    fprintf(fp, "%s\n", messages[i].message);
  }

  fclose(fp);

  return 0;
}

// Function to compare messages
int compare_messages(Message *messages1, int num_messages1,
                     Message *messages2, int num_messages2,
                     Message *unique_messages) {
  int num_unique_messages = 0;

  for (int i = 0; i < num_messages1; i++) {
    int found = 0;
    for (int j = 0; j < num_messages2; j++) {
      if (strcmp(messages1[i].message, messages2[j].message) == 0) {
        found = 1;
        break;
      }
    }
    if (!found) {
      strcpy(unique_messages[num_unique_messages++].message,
             messages1[i].message);
    }
  }

  return num_unique_messages;
}

int main() {
  Message messages1[100], messages2[100], unique_messages[100];
  int num_messages1, num_messages2, num_unique_messages;

  // Read Romeo's messages
  read_messages("romeo.txt", messages1, &num_messages1);

  // Read Juliet's messages
  read_messages("juliet.txt", messages2, &num_messages2);

  // Compare messages
  num_unique_messages = compare_messages(messages1, num_messages1,
                                         messages2, num_messages2,
                                         unique_messages);

  // Write unique messages to a file
  write_messages("unique.txt", unique_messages, num_unique_messages);

  return 0;
}