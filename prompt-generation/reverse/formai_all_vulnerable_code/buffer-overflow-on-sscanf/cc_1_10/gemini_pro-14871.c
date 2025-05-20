//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 12

typedef struct {
  char name[MAX_NAME_LEN];
  char phone[MAX_PHONE_LEN];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(char *name, char *phone) {
  if (num_contacts >= MAX_CONTACTS) {
    fprintf(stderr, "Error: phone book is full\n");
    return;
  }

  strcpy(contacts[num_contacts].name, name);
  strcpy(contacts[num_contacts].phone, phone);
  num_contacts++;
}

void print_contacts() {
  printf("Contacts:\n");
  for (int i = 0; i < num_contacts; i++) {
    printf("%s: %s\n", contacts[i].name, contacts[i].phone);
  }
}

void search_contacts(char *regex) {
  regex_t re;
  int reti;

  if (regcomp(&re, regex, 0) != 0) {
    fprintf(stderr, "Error: could not compile regular expression\n");
    return;
  }

  printf("Matching contacts:\n");
  for (int i = 0; i < num_contacts; i++) {
    reti = regexec(&re, contacts[i].name, 0, NULL, 0);
    if (reti == 0) {
      printf("%s: %s\n", contacts[i].name, contacts[i].phone);
    }
  }

  regfree(&re);
}

int main() {
  char input[256];
  char name[MAX_NAME_LEN];
  char phone[MAX_PHONE_LEN];
  char regex[256];

  printf("Welcome to the phone book!\n");

  while (1) {
    printf("> ");
    fgets(input, sizeof(input), stdin);

    if (strncmp(input, "add", 3) == 0) {
      sscanf(input, "add %s %s", name, phone);
      add_contact(name, phone);
    } else if (strncmp(input, "print", 5) == 0) {
      print_contacts();
    } else if (strncmp(input, "search", 6) == 0) {
      sscanf(input, "search %s", regex);
      search_contacts(regex);
    } else if (strncmp(input, "quit", 4) == 0) {
      break;
    } else {
      printf("Unrecognized command\n");
    }
  }

  return 0;
}