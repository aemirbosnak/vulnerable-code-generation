//FormAI DATASET v1.0 Category: Email Client ; Style: irregular
#include<stdio.h>

int main()
{
   // Welcome message for the user
   printf("Welcome to my custom email client!\n");

   // Declarations for username and password
   char username[50];
   char password[50];

   // Prompt user to enter their username and password
   printf("Please enter your email username:\n");
   scanf("%s", username);

   printf("Please enter your email password:\n");
   scanf("%s", password);

   // Connection to server
   printf("Connecting to email server....\n");
   printf("Connection Successful!\n");

   // Show email inbox
   printf("Your email inbox contains the following messages:\n");

   // Hardcoded email message objects
   char email1_subject[] = "Important Meeting Reminder";
   char email1_from[] = "john@doe.com";
   char email1_body[] = "Just a friendly reminder that we have a meeting tomorrow at 2pm in the conference room.";

   char email2_subject[] = "Birthday Invitation";
   char email2_from[] = "jane@smith.com";
   char email2_body[] = "Hey, I'm having my birthday party this weekend. You're invited!";

   // Print out email messages
   printf("\nFrom: %s\nSubject: %s\n\n%s\n", email1_from, email1_subject, email1_body);
   printf("\nFrom: %s\nSubject: %s\n\n%s\n", email2_from, email2_subject, email2_body);

   // Prompt user to select an email to view
   int email_choice;
   printf("\nEnter the number of the email you would like to view: ");
   scanf("%d", &email_choice);

   // Display selected email message
   printf("\nFrom: ");
   if(email_choice == 1)
      printf("%s", email1_from);
   else
      printf("%s", email2_from);

   printf("\nSubject: ");
   if(email_choice == 1)
      printf("%s", email1_subject);
   else
      printf("%s", email2_subject);

   printf("\n\nBody: ");
   if(email_choice == 1)
      printf("%s", email1_body);
   else
      printf("%s", email2_body);

   // End of program message
   printf("\n\nThank you for using my custom email client! Goodbye.\n");

   return 0;
}