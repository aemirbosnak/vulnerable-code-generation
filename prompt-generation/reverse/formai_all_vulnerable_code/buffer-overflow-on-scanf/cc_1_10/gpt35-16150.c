//FormAI DATASET v1.0 Category: Mailing list manager ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
} Email;

int add_email(Email *list, int idx) {
  if (idx == MAX_EMAILS) {
    printf("Error: Mailing list is full\n");
    return idx;
  }
  Email new_email;
  printf("Please enter the name of the email recipient: ");
  fgets(new_email.name, MAX_NAME_LENGTH, stdin);
  printf("Please enter the email address: ");
  fgets(new_email.email, MAX_EMAIL_LENGTH, stdin);
  list[idx] = new_email;
  idx++;
  printf("Email added successfully\n");
  return idx;
}

int remove_email(Email *list, int idx) {
  if (idx == 0) {
    printf("Error: Mailing list is empty\n");
    return idx;
  }
  char search_name[MAX_NAME_LENGTH];
  printf("Please enter the name of the email recipient to remove: ");
  fgets(search_name, MAX_NAME_LENGTH, stdin);
  int found = 0;
  for (int i = 0; i < idx; i++) {
    if (strcmp(search_name, list[i].name) == 0) {
      printf("Removed email for %s (%s)\n", list[i].name, list[i].email);
      for (int j = i; j < idx - 1; j++) {
        list[j] = list[j+1];
      }
      idx--;
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Error: Email recipient not found\n");
  }
  return idx;
}

void print_list(Email *list, int idx) {
  printf("Mailing List:\n");
  for (int i = 0; i < idx; i++) {
    printf("%s (%s)\n", list[i].name, list[i].email);
  }
}

int main() {
  Email mailing_list[MAX_EMAILS];
  int num_emails = 0;

  while (1) {
    char choice;
    printf("\nPlease choose an option:\n");
    printf("  (a) Add email to mailing list\n");
    printf("  (r) Remove email from mailing list\n");
    printf("  (p) Print mailing list\n");
    printf("  (q) Quit\n");
    printf("Your choice: ");
    scanf("%c", &choice);
    getchar(); // clear newline from stdin

    switch (choice) {
      case 'a':
        num_emails = add_email(mailing_list, num_emails);
        break;
      case 'r':
        num_emails = remove_email(mailing_list, num_emails);
        break;
      case 'p':
        print_list(mailing_list, num_emails);
        break;
      case 'q':
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Error: Invalid choice\n");
    }
  }
  return 0;
}