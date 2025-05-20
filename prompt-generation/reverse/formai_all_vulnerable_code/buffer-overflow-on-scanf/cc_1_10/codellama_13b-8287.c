//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: beginner-friendly
// Email Client Program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_EMAILS 100

struct Email {
  char from[100];
  char to[100];
  char subject[100];
  char body[1000];
  char date[100];
  char time[100];
};

struct Email emails[MAX_EMAILS];
int num_emails = 0;

void print_emails() {
  for (int i = 0; i < num_emails; i++) {
    printf("Email %d:\n", i + 1);
    printf("From: %s\n", emails[i].from);
    printf("To: %s\n", emails[i].to);
    printf("Subject: %s\n", emails[i].subject);
    printf("Body: %s\n", emails[i].body);
    printf("Date: %s\n", emails[i].date);
    printf("Time: %s\n", emails[i].time);
  }
}

void send_email() {
  printf("Enter the recipient's email address: ");
  char recipient[100];
  scanf("%s", recipient);

  printf("Enter the subject: ");
  char subject[100];
  scanf("%s", subject);

  printf("Enter the body: ");
  char body[1000];
  scanf("%[^\n]", body);

  struct Email email = {
    .from = "me@example.com",
    .to = recipient,
    .subject = subject,
    .body = body,
    .date = __DATE__,
    .time = __TIME__,
  };

  emails[num_emails++] = email;
}

void receive_email() {
  printf("Enter the recipient's email address: ");
  char recipient[100];
  scanf("%s", recipient);

  for (int i = 0; i < num_emails; i++) {
    if (strcmp(emails[i].to, recipient) == 0) {
      printf("Email %d:\n", i + 1);
      printf("From: %s\n", emails[i].from);
      printf("To: %s\n", emails[i].to);
      printf("Subject: %s\n", emails[i].subject);
      printf("Body: %s\n", emails[i].body);
      printf("Date: %s\n", emails[i].date);
      printf("Time: %s\n", emails[i].time);
    }
  }
}

int main() {
  int choice;
  while (1) {
    printf("1. Send Email\n");
    printf("2. Receive Email\n");
    printf("3. Print Emails\n");
    printf("4. Quit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        send_email();
        break;
      case 2:
        receive_email();
        break;
      case 3:
        print_emails();
        break;
      case 4:
        return 0;
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  }
}