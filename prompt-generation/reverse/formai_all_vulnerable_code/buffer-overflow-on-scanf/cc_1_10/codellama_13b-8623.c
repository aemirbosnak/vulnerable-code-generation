//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: retro
// Retro Email Client
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define constants
#define MAX_EMAILS 10
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 200

// Define structs
typedef struct {
  char subject[MAX_SUBJECT_LEN];
  char body[MAX_BODY_LEN];
} Email;

typedef struct {
  Email emails[MAX_EMAILS];
  int num_emails;
} EmailBox;

// Define functions
void print_email_box(EmailBox *email_box) {
  printf("Email Box:\n");
  for (int i = 0; i < email_box->num_emails; i++) {
    Email email = email_box->emails[i];
    printf("%d. %s\n%s\n\n", i, email.subject, email.body);
  }
}

void add_email(EmailBox *email_box, char *subject, char *body) {
  if (email_box->num_emails >= MAX_EMAILS) {
    printf("Error: Email box is full\n");
    return;
  }
  Email email;
  strcpy(email.subject, subject);
  strcpy(email.body, body);
  email_box->emails[email_box->num_emails++] = email;
}

void remove_email(EmailBox *email_box, int index) {
  if (index < 0 || index >= email_box->num_emails) {
    printf("Error: Invalid email index\n");
    return;
  }
  for (int i = index; i < email_box->num_emails - 1; i++) {
    email_box->emails[i] = email_box->emails[i + 1];
  }
  email_box->num_emails--;
}

int main() {
  EmailBox email_box = {0};
  char subject[MAX_SUBJECT_LEN], body[MAX_BODY_LEN];
  int choice;

  // Print welcome message
  printf("Welcome to the Retro Email Client\n");

  // Loop until user quits
  while (1) {
    // Print menu
    printf("\nMenu:\n");
    printf("1. Print email box\n");
    printf("2. Add email\n");
    printf("3. Remove email\n");
    printf("4. Quit\n");
    scanf("%d", &choice);

    // Handle user input
    switch (choice) {
    case 1:
      print_email_box(&email_box);
      break;
    case 2:
      printf("Enter subject: ");
      scanf("%s", subject);
      printf("Enter body: ");
      scanf("%s", body);
      add_email(&email_box, subject, body);
      break;
    case 3:
      printf("Enter email index: ");
      scanf("%d", &choice);
      remove_email(&email_box, choice);
      break;
    case 4:
      printf("Quitting...\n");
      return 0;
    default:
      printf("Invalid choice\n");
      break;
    }
  }

  return 0;
}