//FormAI DATASET v1.0 Category: Email Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#define MAX 300

struct Email {
  char sender[MAX];
  char recipient[MAX];
  char subject[MAX];
  char message[MAX];
};

void send_email(char* recipient, char* subject, char* message) {
  // Send email using a library
}

void receive_email(char* username, char* password) {
  // Get emails from a server using a library
}

int main() {
  int choice;
  char recipient[MAX], subject[MAX], message[MAX];
  char username[MAX], password[MAX];
  while (1) {
    printf("1. Send email\n");
    printf("2. Receive email\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Recipient: ");
        scanf("%s", recipient);
        printf("Subject: ");
        scanf("%s", subject);
        printf("Message: ");
        scanf("%s", message);
        send_email(recipient, subject, message);
        break;
      case 2:
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        receive_email(username, password);
        break;
      case 3:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}