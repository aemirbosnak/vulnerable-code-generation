//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAME_SIZE 30
#define EMAIL_SIZE 50
#define MAX_ENTRIES 100

typedef struct {
  char name[NAME_SIZE];
  char email[EMAIL_SIZE];
  int subscribed;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *name, char *email) {
  if (num_entries >= MAX_ENTRIES) {
    printf("Mailing list full!\n");
    return;
  }

  strcpy(entries[num_entries].name, name);
  strcpy(entries[num_entries].email, email);
  entries[num_entries].subscribed = 1;
  num_entries++;
}

void remove_entry(char *name) {
  int i;

  for (i = 0; i < num_entries; i++) {
    if (strcmp(entries[i].name, name) == 0) {
      entries[i].subscribed = 0;
      return;
    }
  }

  printf("Name not found in mailing list.\n");
}

void send_email(char *subject, char *body) {
  int i;

  for (i = 0; i < num_entries; i++) {
    if (entries[i].subscribed) {
      printf("Sending email to %s (%s):\n", entries[i].name, entries[i].email);
      printf("Subject: %s\n", subject);
      printf("Body: %s\n", body);
    }
  }
}

void print_list() {
  int i;

  printf("Mailing list:\n");
  for (i = 0; i < num_entries; i++) {
    printf("%s (%s)\n", entries[i].name, entries[i].email);
  }
}

int main() {
  char input[100];
  char name[NAME_SIZE];
  char email[EMAIL_SIZE];
  char subject[100];
  char body[1000];
  int i;

  while (1) {
    printf("> ");
    gets(input);

    if (strcmp(input, "add") == 0) {
      printf("Name: ");
      gets(name);
      printf("Email: ");
      gets(email);
      add_entry(name, email);
    } else if (strcmp(input, "remove") == 0) {
      printf("Name: ");
      gets(name);
      remove_entry(name);
    } else if (strcmp(input, "send") == 0) {
      printf("Subject: ");
      gets(subject);
      printf("Body: ");
      gets(body);
      send_email(subject, body);
    } else if (strcmp(input, "list") == 0) {
      print_list();
    } else if (strcmp(input, "quit") == 0) {
      break;
    } else {
      printf("Unknown command.\n");
    }
  }

  return 0;
}