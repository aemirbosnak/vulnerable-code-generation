//FormAI DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

struct email {
  char recipient[100];
  char sender[100];
  char subject[MAX_SUBJECT_LENGTH];
  char body[MAX_BODY_LENGTH];
};

void send_email();
void display_menu();
void display_inbox();
void display_email(struct email em);
void save_email(struct email em);

int main() {
  display_menu();
  return 0;
}

void display_menu() {
  char choice;
  do {
    printf("\n================\n");
    printf("C Email Client\n");
    printf("================\n");
    printf("1. Send email\n");
    printf("2. View inbox\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    fflush(stdin);
    switch (choice) {
      case '1': send_email(); break;
      case '2': display_inbox(); break;
      case '3': break;
      default: printf("Invalid choice. Try again.\n");
    }
  } while (choice != '3');
}

void send_email() {
  struct email em;
  printf("\n================\n");
  printf("Send Email\n");
  printf("================\n");
  printf("Recipient: ");
  fgets(em.recipient, 100, stdin);
  printf("Sender: ");
  fgets(em.sender, 100, stdin);
  printf("Subject: ");
  fgets(em.subject, MAX_SUBJECT_LENGTH, stdin);
  printf("Body: ");
  fgets(em.body, MAX_BODY_LENGTH, stdin);
  save_email(em);
  printf("Email sent successfully!\n");
}

void display_inbox() {
  FILE *fp;
  struct email em;
  int count = 0;
  fp = fopen("emails.txt", "r");
  if (fp == NULL) {
    printf("No emails yet.\n");
    return;
  }
  while (fread(&em, sizeof(struct email), 1, fp)) {
    display_email(em);
    count++;
  }
  fclose(fp);
  if (count == 0) {
    printf("No emails yet.\n");
  }
}

void display_email(struct email em) {
  printf("\n================\n");
  printf("From: %s", em.sender);
  printf("To: %s", em.recipient);
  printf("Subject: %s", em.subject);
  printf("Body: %s", em.body);
}

void save_email(struct email em) {
  FILE *fp;
  fp = fopen("emails.txt", "a");
  fwrite(&em, sizeof(struct email), 1, fp);
  fclose(fp);
}