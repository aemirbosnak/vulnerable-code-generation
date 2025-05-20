//FormAI DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>

int main() {
   int choice;
   printf("Welcome to System Administration Example Program\n");
   do {
      printf("\n\nAvailable options:\n");
      printf("1. Create a new user\n");
      printf("2. Delete an existing user\n");
      printf("3. Change password for a user\n");
      printf("4. View all users\n");
      printf("5. Exit the program\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1:
            {
               char username[20], password[20];
               printf("Enter the new username: ");
               scanf("%s", username);
               
               printf("Enter the password: ");
               scanf("%s", password);
               
               // Add new user logic goes here
               
               printf("User %s has been created successfully!\n", username);
               break;
            }
         case 2:
            {
               char username[20];
               printf("Enter the username to delete: ");
               scanf("%s", username);
               
               // Delete user logic goes here
               
               printf("User %s has been deleted successfully!\n", username);
               break;
            }
         case 3:
            {
               char username[20], password[20];
               printf("Enter the username to change password: ");
               scanf("%s", username);
               
               printf("Enter the new password: ");
               scanf("%s", password);
               
               // Change password logic goes here
               
               printf("Password for user %s has been changed successfully!\n", username);
               break;
            }
         case 4:
            {
               // View all users logic goes here
               printf("List of all users:\n");
               break;
            }
         case 5:
            {
               printf("Exiting the program. Goodbye!\n"); 
               break;
            }
         default:
            printf("Invalid choice. Please try again.\n");
      }
   } while(choice != 5);
   return 0;
}