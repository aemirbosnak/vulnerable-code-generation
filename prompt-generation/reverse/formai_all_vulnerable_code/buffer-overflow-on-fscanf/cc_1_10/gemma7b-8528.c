//Gemma-7B DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGES 10
#define MAX_MESSAGE_LENGTH 200

typedef struct Message {
  char sender[50];
  char recipient[50];
  char subject[50];
  char message[MAX_MESSAGE_LENGTH];
} Message;

Message messages[MAX_MESSAGES];

void read_messages() {
  FILE *fp = fopen("messages.txt", "r");
  if (fp) {
    int i = 0;
    while (fscanf(fp, "%s %s %s %[^\n]", messages[i].sender, messages[i].recipient, messages[i].subject, messages[i].message) != EOF) {
      i++;
    }
    fclose(fp);
  }
}

void write_messages() {
  FILE *fp = fopen("messages.txt", "w");
  if (fp) {
    int i = 0;
    for (i = 0; messages[i].sender[0] != '\0'; i++) {
      fprintf(fp, "%s %s %s %s\n", messages[i].sender, messages[i].recipient, messages[i].subject, messages[i].message);
    }
    fclose(fp);
  }
}

void display_messages() {
  int i = 0;
  for (i = 0; messages[i].sender[0] != '\0'; i++) {
    printf("From: %s\n", messages[i].sender);
    printf("To: %s\n", messages[i].recipient);
    printf("Subject: %s\n", messages[i].subject);
    printf("Message: %s\n", messages[i].message);
    printf("\n");
  }
}

int main() {
  read_messages();
  display_messages();
  write_messages();
  display_messages();

  return 0;
}