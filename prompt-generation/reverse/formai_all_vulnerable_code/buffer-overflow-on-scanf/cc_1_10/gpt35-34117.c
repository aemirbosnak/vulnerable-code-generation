//FormAI DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

int main() {
   printf("Welcome to CyberMail v1.0!\n\n");
   
   //Initialize variables
   char username[20];
   char password[20];
   char recipient[50];
   char subject[50];
   char message[500];
   
   //Get user's login information
   printf("Enter your CyberMail username: ");
   scanf("%s", username);
   printf("Enter your password: ");
   scanf("%s", password);
   
   //Display main menu
   int choice;
   do {
      printf("\n\n===========CYBERMAIL MENU===========\n");
      printf("1. Compose Email\n");
      printf("2. Check Inbox\n");
      printf("3. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      //Compose Email
      if (choice == 1) {
         printf("\n===========COMPOSE EMAIL===========\n");
         printf("Enter recipient's email address: ");
         scanf("%s", recipient);
         printf("Enter email subject: ");
         scanf("%s", subject);
         printf("Enter your message (maximum 500 characters):\n");
         getchar();
         fgets(message, sizeof(message), stdin);
         printf("\nEmail Sent!");
      }
      
      //Check Inbox (empty for now)
      else if (choice == 2) {
         printf("\n===========INBOX============\n");
         printf("You have no new messages.");
      }
      
   } while (choice != 3);
   
   printf("\n\nThank you for using CyberMail v1.0");
   return 0;
}