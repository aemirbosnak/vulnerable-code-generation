//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

#define MAX_EMAIL_SIZE 1000
#define MAX_USER_NAME_SIZE 50
#define MAX_DOMAIN_NAME_SIZE 50

typedef struct {
  char user_name[MAX_USER_NAME_SIZE];
  char domain_name[MAX_DOMAIN_NAME_SIZE];
} email_address;

typedef struct {
  char from[MAX_EMAIL_SIZE];
  char to[MAX_EMAIL_SIZE];
  char subject[MAX_EMAIL_SIZE];
  char body[MAX_EMAIL_SIZE];
} email;

void print_email(email *email) {
  printf("From: %s\n", email->from);
  printf("To: %s\n", email->to);
  printf("Subject: %s\n", email->subject);
  printf("Body: %s\n", email->body);
}

int send_email(email *email) {
  // Send the email using some SMTP library or service
  // For the purpose of this example, we will just print the email
  print_email(email);
  return 0;
}

int get_email_from_user(email *email) {
  printf("Enter email address (from): ");
  scanf("%s", email->from);

  printf("Enter email address (to): ");
  scanf("%s", email->to);

  printf("Enter subject: ");
  scanf("%s", email->subject);

  printf("Enter body: ");
  scanf("%s", email->body);

  // Validate the email address
  if (!validate_email_address(email->from) || !validate_email_address(email->to)) {
    printf("Invalid email address\n");
    return -1;
  }

  return 0;
}

int validate_email_address(char *email_address) {
  // Check if the email address is in the correct format
  int at_sign_count = 0;
  int dot_count = 0;
  for (int i = 0; i < strlen(email_address); i++) {
    if (email_address[i] == '@') {
      at_sign_count++;
    } else if (email_address[i] == '.') {
      dot_count++;
    }
  }

  if (at_sign_count != 1 || dot_count < 1) {
    return false;
  }

  // Check if the user name and domain name are valid
  char *user_name = strtok(email_address, "@");
  char *domain_name = strtok(NULL, ".");

  if (!validate_user_name(user_name) || !validate_domain_name(domain_name)) {
    return false;
  }

  return true;
}

int validate_user_name(char *user_name) {
  // Check if the user name is valid
  for (int i = 0; i < strlen(user_name); i++) {
    if (!isalnum(user_name[i]) && user_name[i] != '_' && user_name[i] != '-') {
      return false;
    }
  }

  return true;
}

int validate_domain_name(char *domain_name) {
  // Check if the domain name is valid
  for (int i = 0; i < strlen(domain_name); i++) {
    if (!isalnum(domain_name[i]) && domain_name[i] != '.' && domain_name[i] != '-') {
      return false;
    }
  }

  return true;
}

int main() {
  email email;

  while (true) {
    int choice;
    printf("1. Send email\n");
    printf("2. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (get_email_from_user(&email) == 0) {
          send_email(&email);
        }
        break;
      case 2:
        return 0;
      default:
        printf("Invalid choice\n");
        break;
    }
  }

  return 0;
}