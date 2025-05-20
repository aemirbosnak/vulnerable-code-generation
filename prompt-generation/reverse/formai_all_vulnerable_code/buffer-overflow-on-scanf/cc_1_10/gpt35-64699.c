//FormAI DATASET v1.0 Category: Email Client ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EMAILS 1000
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 500

typedef struct Email {
  char subject[MAX_SUBJECT_LEN];
  char body[MAX_BODY_LEN];
  char sender[MAX_SUBJECT_LEN];
  char recipient[MAX_SUBJECT_LEN];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void get_user_input() {
  char option;
  while(1) {
    printf("Welcome to the email client. Enter 'c' to compose an email, 'v' to view all emails, 's' to search emails, or 'q' to quit: ");
    scanf(" %c", &option);
    option = tolower(option);
    switch(option) {
      case 'c':
        printf("Enter the email subject: ");
        scanf("%s", emails[num_emails].subject);
        printf("Enter the email body: ");
        scanf("%s", emails[num_emails].body);
        printf("Enter the sender email: ");
        scanf("%s", emails[num_emails].sender);
        printf("Enter the recipient email: ");
        scanf("%s", emails[num_emails].recipient);
        num_emails++;
        break;
      case 'v':
        if(num_emails == 0) {
          printf("No emails found.\n");
          break;
        }
        for(int i = 0; i < num_emails; i++) {
          printf("Email #%d:\n", i+1);
          printf("Subject: %s\n", emails[i].subject);
          printf("Body: %s\n", emails[i].body);
          printf("Sent from: %s\n", emails[i].sender);
          printf("Sent to: %s\n", emails[i].recipient);
        }
        break;
      case 's':
        if(num_emails == 0) {
          printf("No emails found.\n");
          break;
        }
        char search_query[MAX_SUBJECT_LEN];
        int num_results = 0;
        printf("Enter the search query: ");
        scanf("%s", search_query);
        for(int i = 0; i < num_emails; i++) {
          if(strstr(emails[i].subject, search_query) != NULL) {
            printf("Search Result #%d:\n", num_results+1);
            printf("Subject: %s\n", emails[i].subject);
            printf("Body: %s\n", emails[i].body);
            printf("Sent from: %s\n", emails[i].sender);
            printf("Sent to: %s\n", emails[i].recipient);
            num_results++;
          }
        }
        if(num_results == 0) {
          printf("No emails found.\n");
        }
        break;
      case 'q':
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid option.\n");
        break;
    }
    printf("\n");
  }
}

int main() {
  get_user_input();
  return 0;
}