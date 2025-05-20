//FormAI DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000

struct Email {
   char recipient[50];
   char sender[50];
   char subject[100];
   char message[500];
};

void addEmail(struct Email emails[], int *numEmails) {
   if (*numEmails == MAX_EMAILS) {
      printf("Error: mailing list full.\n");
      return;
   }
   
   printf("Enter recipient's email address: ");
   scanf("%s", emails[*numEmails].recipient);
   printf("Enter sender's email address: ");
   scanf("%s", emails[*numEmails].sender);
   printf("Enter email subject: ");
   getchar(); // to clear out newline character from scanf
   fgets(emails[*numEmails].subject, 100, stdin);
   printf("Enter message: ");
   fgets(emails[*numEmails].message, 500, stdin);
   
   (*numEmails)++;
}

void printEmails(struct Email emails[], int numEmails) {
   if (numEmails == 0) {
      printf("Mailing list is empty.\n");
      return;
   }
   
   printf("Mailing List:\n");
   printf("%-20s %-20s %-40s\n", "Recipient", "Sender", "Subject");
   for (int i = 0; i < numEmails; i++) {
      printf("%-20s %-20s %-40s\n", emails[i].recipient, emails[i].sender, emails[i].subject);
   }
}

void searchEmails(struct Email emails[], int numEmails) {
   char searchStr[100];
   int found = 0;
   
   printf("Enter search string: ");
   getchar(); // to clear out newline character from previous input
   fgets(searchStr, 100, stdin);
   
   for (int i = 0; i < numEmails; i++) {
      if (strstr(emails[i].message, searchStr) != NULL ||
          strstr(emails[i].subject, searchStr) != NULL) {
         printf("Email #%d:\n", i+1);
         printf("Recipient: %s\n", emails[i].recipient);
         printf("Sender:    %s\n", emails[i].sender);
         printf("Subject:   %s", emails[i].subject);
         printf("Message:   %s", emails[i].message);
         found = 1;
      }
   }
   
   if (!found) {
      printf("No emails found.\n");
   }
}

int main(void) {
   struct Email emails[MAX_EMAILS];
   int numEmails = 0;
   int choice;
   
   do {
      // print menu
      printf("\nEmail Mailing List Manager\n");
      printf("==========================\n");
      printf("1. Add email\n");
      printf("2. Print all emails\n");
      printf("3. Search emails\n");
      printf("4. Exit\n");
      printf("Enter choice (1-4): ");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1:
            addEmail(emails, &numEmails);
            break;
         case 2:
            printEmails(emails, numEmails);
            break;
         case 3:
            searchEmails(emails, numEmails);
            break;
         case 4:
            printf("Exiting program...\n");
            break;
         default:
            printf("Invalid choice. Try again.\n");
            break;
      }
   } while(choice != 4);
   
   return 0;
}