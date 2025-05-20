//FormAI DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  printf("Welcome to System Administration Tool!\n");
  printf("--------------------------------------\n");
  printf("Please choose an option:\n");
  printf("1. Create a new user\n");
  printf("2. Delete an existing user\n");
  printf("3. Change user password\n");
  printf("4. List all users\n");
  printf("5. Exit program\n");

  int choice;
  printf("Enter your choice: ");
  scanf("%d",&choice);

  switch(choice){
    case 1:
      printf("\nYou have chosen to create a new user.\n");
      char username[20];
      char password[20];
      printf("Enter a username: ");
      scanf("%s",username);
      printf("Enter a password: ");
      scanf("%s",password);
      char command[100];
      sprintf(command,"sudo useradd -p %s %s",password,username);
      system(command);
      printf("\nNew user created successfully!\n");
      break;
    case 2:
      printf("\nYou have chosen to delete an existing user.\n");
      char del_username[20];
      printf("Enter username to delete: ");
      scanf("%s",del_username);
      char del_command[100];
      sprintf(del_command,"sudo userdel %s",del_username);
      system(del_command);
      printf("\nUser %s deleted successfully!\n",del_username);
      break;
    case 3:
      printf("\nYou have chosen to change a user's password.\n");
      char change_username[20];
      char new_password[20];
      printf("Enter username to change password: ");
      scanf("%s",change_username);
      printf("Enter new password: ");
      scanf("%s",new_password);
      char change_command[100];
      sprintf(change_command,"sudo passwd %s %s",change_username,new_password);
      system(change_command);
      printf("\nPassword for user %s changed successfully!\n",change_username);
      break;
    case 4:
      printf("\nYou have chosen to list all users on the system.\n");
      system("cut -d: -f1 /etc/passwd");
      break;
    case 5:
      printf("\nExiting System Administration Tool...\n");
      break;
    default:
      printf("\nInvalid choice, please try again.\n");
      break;
  }

  return 0;
}