//FormAI DATASET v1.0 Category: Email Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 100

typedef struct {
   char to[256];
   char subject[MAX_SUBJECT_LENGTH];
   char body[MAX_BODY_LENGTH];
} Email; 

void sendEmail(Email email) {
   printf("To: %s\n", email.to);
   printf("Subject: %s\n", email.subject);
   printf("%s\n", email.body);
}

void displayEmails(Email emails[], int count) {
   printf("Your emails:\n");
   for (int i = 0; i < count; i++) {
      printf("Email %d:\n", i + 1);
      printf("To: %s\n", emails[i].to);
      printf("Subject: %s\n", emails[i].subject);
      printf("%s\n", emails[i].body);
      printf("\n");
   }
}

int main(void) {
   Email emails[MAX_EMAILS];
   int emailCount = 0;
   int choice = 0;
   while (choice != 3) {
      printf("(1) Compose Email\n(2) View Emails\n(3) Quit\nEnter choice: ");
      scanf("%d", &choice);
      printf("\n");

      switch (choice) {
         case 1: {
            Email email;
            printf("To: ");
            scanf("%s", email.to);
            printf("Subject: ");
            scanf("%s", email.subject);
            printf("Body: ");
            scanf("%s", email.body);
            emails[emailCount++] = email;
            printf("\nEmail sent!\n\n");
            break;
         }
         case 2: {
            displayEmails(emails, emailCount);
            break;
         }
         case 3:
            break;
         default:
            printf("Invalid choice!\n\n");
      }
   }
   return 0;
}