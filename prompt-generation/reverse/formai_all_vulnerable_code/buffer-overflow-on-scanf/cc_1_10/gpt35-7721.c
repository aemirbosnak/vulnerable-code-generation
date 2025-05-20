//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int option; 
   printf("Welcome to the Curious System Administration Example Program!\n");
   printf("Please select an option: \n");
   printf("1. Create a new user\n");
   printf("2. Delete a user\n");
   printf("3. Change user password\n");
   printf("4. View system information\n");
   printf("5. Exit program\n");

   scanf("%d", &option);

   while (option != 5) 
   {
       if (option == 1) 
       {
           printf("\nYou have chosen to create a new user. \n");
           printf("\nPlease enter the username: ");
           char username[20];
           scanf("%s", username);
           printf("The user %s has been successfully created.\n", username);
       } 
       else if (option == 2) 
       {
           printf("\nYou have chosen to delete a user. \n");
           printf("\nPlease enter the username: ");
           char username[20];
           scanf("%s", username);
           printf("Are you sure you want to delete the user %s? (y/n): ", username);
           char response;
           scanf(" %c", &response);
           if (response == 'y' || response == 'Y') 
           {
               printf("The user %s has been successfully deleted.\n", username);
           } else 
           {
               printf("User deletion cancelled.\n");
           }
       } 
       else if (option == 3) 
       {
           printf("\nYou have chosen to change a user's password. \n");
           printf("\nPlease enter the username: ");
           char username[20];
           scanf("%s", username);
           printf("Please enter the new password: ");
           char password[20];
           scanf("%s", password);
           printf("The password for user %s has been successfully updated.\n", username);
       } 
       else if (option == 4) 
       {
           printf("\nYou have chosen to view system information. \n");
           printf("Operating System: Windows 10\n");
           printf("Processor: Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz\n");
           printf("Memory: 8 GB\n");
           printf("Storage: 256 GB SSD\n");
           printf("Graphics: Intel(R) HD Graphics 520\n");
       }

       printf("\nPlease select an option: \n");
       printf("1. Create a new user\n");
       printf("2. Delete a user\n");
       printf("3. Change user password\n");
       printf("4. View system information\n");
       printf("5. Exit program\n");

       scanf("%d", &option);
   }

   printf("Thank you for using the Curious System Administration Example Program! Goodbye.\n");

   return 0;
}