//FormAI DATASET v1.0 Category: Email Client ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct email {
   char to[100];
   char from[100];
   char subject[100];
   char message[1000];
};

void display_menu() {
   printf("\n*************");
   printf("\nEmail Client");
   printf("\n*************");
   printf("\n1. Compose Email");
   printf("\n2. Inbox");
   printf("\n3. Sent Items");
   printf("\n4. Exit");
}

void compose_email() {
   struct email new_email;
   printf("\nEnter recipient:");
   scanf("%s", new_email.to);
   printf("\nEnter subject:");
   scanf("%s", new_email.subject);
   printf("\nEnter message:");
   scanf("%s", new_email.message);

   // Write new email to file
   FILE* fp;
   fp = fopen("inbox.txt", "a");
   fprintf(fp,"\n*************\nFrom: %s\nTo: %s\nSubject: %s\nMessage: %s\n*************", new_email.from, new_email.to, new_email.subject, new_email.message);
   fclose(fp);

   printf("\nEmail sent successfully!");
}

void view_inbox() {
   char buffer[1000];
   FILE* fp;
   fp = fopen("inbox.txt", "r");
   while(fgets(buffer, 1000, fp)) {
      printf("\n%s", buffer);
   }
   fclose(fp);
}

void view_sent_items() {
   char buffer[1000];
   FILE* fp;
   fp = fopen("sent.txt", "r");
   while(fgets(buffer, 1000, fp)) {
      printf("\n%s", buffer);
   }
   fclose(fp);
}

int main() {
   int choice;
   do {
      display_menu();
      printf("\nEnter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            compose_email();
            break;
         case 2:
            view_inbox();
            break;
         case 3:
            view_sent_items();
            break;
         case 4:
            printf("\nGoodbye!");
            break;
         default:
            printf("\nInvalid Choice");
      }
   } while(choice != 4);

   return 0;
}