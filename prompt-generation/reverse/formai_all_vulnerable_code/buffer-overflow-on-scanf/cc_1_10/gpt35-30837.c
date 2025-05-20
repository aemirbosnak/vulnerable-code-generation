//FormAI DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000 // Maximum number of emails that can be stored
#define MAX_EMAIL_LENGTH 50 // Maximum length of an email address

typedef struct {
  char email[MAX_EMAIL_LENGTH];
} Email;

typedef struct {
  Email* emails[MAX_EMAILS]; // Array of pointers to Email structs
  int count; // Number of emails currently in list
} EmailList;

// Function prototypes
EmailList* create_list();
void add_email(EmailList* list, char* email);
void remove_email(EmailList* list, char* email);
void print_list(EmailList* list);
void free_list(EmailList* list);

int main() {
  EmailList* list = create_list();

  while (1) {
    printf("\nMenu:\n"
           "1. Add email\n"
           "2. Remove email\n"
           "3. Print list\n"
           "4. Quit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1: {
        char email[MAX_EMAIL_LENGTH];
        printf("Enter email address: ");
        scanf("%s", email);
        add_email(list, email);
        break;
      }
      case 2: {
        char email[MAX_EMAIL_LENGTH];
        printf("Enter email address to remove: ");
        scanf("%s", email);
        remove_email(list, email);
        break;
      }
      case 3:
        print_list(list);
        break;
      case 4:
        free_list(list);
        return 0;
      default:
        printf("Invalid choice, please try again\n");
        break;
    }
  }
}

// Creates a new empty email list
EmailList* create_list() {
  EmailList* list = malloc(sizeof(EmailList));
  list->count = 0;
  return list;
}

// Adds a new email to the list, returns 1 on success, 0 on failure
void add_email(EmailList* list, char* email) {
  if (list->count == MAX_EMAILS) {
    printf("List is full, cannot add more emails\n");
    return;
  }

  Email* new_email = malloc(sizeof(Email));
  strncpy(new_email->email, email, MAX_EMAIL_LENGTH);

  list->emails[list->count] = new_email;
  list->count++;

  printf("Added email: %s\n", email);
}

// Removes an email from the list, returns 1 on success, 0 on failure
void remove_email(EmailList* list, char* email) {
  int i;
  for (i = 0; i < list->count; i++) {
    if (strcmp(list->emails[i]->email, email) == 0) {
      free(list->emails[i]);

      // Shift remaining emails to fill the gap
      for (; i < list->count - 1; i++) {
        list->emails[i] = list->emails[i + 1];
      }

      list->count--;
      printf("Removed email: %s\n", email);
      return;
    }
  }

  printf("Email not found: %s\n", email);
}

// Prints the current list of emails
void print_list(EmailList* list) {
  printf("Current email list:\n");
  if (list->count == 0) {
    printf(" (empty)\n");
    return;
  }

  int i;
  for (i = 0; i < list->count; i++) {
    printf(" %d. %s\n", i + 1, list->emails[i]->email);
  }
}

// Frees all memory used by the email list
void free_list(EmailList* list) {
  int i;
  for (i = 0; i < list->count; i++) {
    free(list->emails[i]);
  }

  free(list);
}