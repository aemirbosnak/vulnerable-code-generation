//Gemma-7B DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 10

typedef struct Message {
  char *subject;
  char *from;
  char *to;
  char *message;
} Message;

Message messages[MAX_MESSAGES];

void read_messages() {
  FILE *fp = fopen("messages.txt", "r");
  int i = 0;
  if (fp) {
    while (!feof(fp) && i < MAX_MESSAGES) {
      messages[i].subject = malloc(100);
      messages[i].from = malloc(100);
      messages[i].to = malloc(100);
      messages[i].message = malloc(1000);

      fscanf(fp, "%s", messages[i].subject);
      fscanf(fp, "%s", messages[i].from);
      fscanf(fp, "%s", messages[i].to);
      fscanf(fp, "%[^\n]%*c", messages[i].message);

      i++;
    }
    fclose(fp);
  }
}

void write_message(char *subject, char *from, char *to, char *message) {
  FILE *fp = fopen("messages.txt", "a");
  int i = MAX_MESSAGES - 1;
  if (fp) {
    messages[i].subject = malloc(100);
    messages[i].from = malloc(100);
    messages[i].to = malloc(100);
    messages[i].message = malloc(1000);

    messages[i].subject = subject;
    messages[i].from = from;
    messages[i].to = to;
    messages[i].message = message;

    fprintf(fp, "%s\n", subject);
    fprintf(fp, "%s\n", from);
    fprintf(fp, "%s\n", to);
    fprintf(fp, "%s\n", message);

    fclose(fp);
  }
}

int main() {
  read_messages();
  write_message("Test Subject", "sender@example.com", "recipient@example.com", "This is a test message");

  int i = 0;
  for (i = 0; i < MAX_MESSAGES; i++) {
    if (messages[i].subject) {
      printf("Subject: %s\n", messages[i].subject);
      printf("From: %s\n", messages[i].from);
      printf("To: %s\n", messages[i].to);
      printf("Message: %s\n", messages[i].message);
      printf("\n");
    }
  }

  return 0;
}