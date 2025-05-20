//FormAI DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1000

/* Struct to hold email message metadata */
typedef struct {
   char sender[50];
   char receiver[50];
   char subject[100];
   char body[MAX_EMAIL_LENGTH];
} Email;

/* Function to display menu options */
void displayMenu() {
   printf("\n==== Email Client Menu ====\n");
   printf("1. Compose Email\n");
   printf("2. View Inbox\n");
   printf("3. View Sent Items\n");
   printf("4. Exit\n\n");
}

/* Function to create and send email message */
void composeEmail(Email *inbox, int *inboxSize, Email *sent, int *sentSize) {
   /* Prompt user for email details */
   printf("\nEnter sender email address: ");
   scanf("%s", inbox[*inboxSize].sender);
   printf("Enter recipient email address: ");
   scanf("%s", inbox[*inboxSize].receiver);
   printf("Enter email subject line: ");
   scanf("%s", inbox[*inboxSize].subject);
   printf("Enter email message text: ");
   getchar(); // flush stdin
   fgets(inbox[*inboxSize].body, MAX_EMAIL_LENGTH, stdin);
   
   /* Copy email to sent folder */
   memcpy(&sent[*sentSize], &inbox[*inboxSize], sizeof(Email));
   *sentSize += 1;
   
   /* Increment inbox size and notify user that email was sent */
   *inboxSize += 1;
   printf("\nEmail Sent!\n");
   printf("=======================\n");
}

/* Function to display inbox emails */
void viewInbox(Email *inbox, int inboxSize) {
   printf("\n**** INBOX (%d) ****\n", inboxSize);
   for (int i=0; i<inboxSize; i++) {
      printf("From: %s\n", inbox[i].sender);
      printf("Subject: %s\n", inbox[i].subject);
      printf("Message: %s\n", inbox[i].body);
      printf("=======================\n");
   }
}

/* Function to display sent emails */
void viewSent(Email *sent, int sentSize) {
   printf("\n**** SENT ITEMS (%d) ****\n", sentSize);
   for (int i=0; i<sentSize; i++) {
      printf("To: %s\n", sent[i].receiver);
      printf("Subject: %s\n", sent[i].subject);
      printf("Message: %s\n", sent[i].body);
      printf("=======================\n");
   }
}

int main() {
   /* Initialize inbox and sent folders */
   Email inbox[MAX_EMAILS];
   int inboxSize = 0;
   Email sent[MAX_EMAILS];
   int sentSize = 0;
   
   /* Display menu and prompt for user input */
   displayMenu();
   int choice = 0;
   do {
      printf("Enter your choice (1-4): ");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            composeEmail(inbox, &inboxSize, sent, &sentSize);
            break;
         case 2:
            viewInbox(inbox, inboxSize);
            break;
         case 3:
            viewSent(sent, sentSize);
            break;
         case 4:
            printf("\nGoodbye!\n");
            break;
         default:
            printf("\nInvalid choice. Please try again.\n");
            break;
      }
      if (choice != 4) {
         displayMenu();
      }
   } while(choice != 4);
   
   return 0;
}