//FormAI DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to the System Administration Program\n");
  printf("Please enter your username: ");
  char username[25];
  scanf("%s", username);
  
  printf("\nWelcome, %s! What would you like to do today?\n", username);
  printf("1. Restart the system\n2. Check system status\n3. Add a new user\n");
  printf("Please enter a number from the option above: ");
  
  int option;
  scanf("%d", &option);
  
  switch(option) {
    case 1:
      system("sudo shutdown -r now");
      break;
      
    case 2:
      system("top");
      break;
      
    case 3:
      printf("Please enter the username of the new user: ");
      char new_user[25];
      scanf("%s", new_user);
      
      printf("Please enter the password for the new user: ");
      char password[25];
      scanf("%s", password);
      
      printf("Creating new user...\n");
      char command[50] = "sudo adduser ";
      strcat(command, new_user);
      strcat(command, " --gecos ");
      strcat(command, new_user);
      strcat(command, " --disabled-password");
      system(command);
      
      char command1[50] = "sudo echo '";
      strcat(command1, new_user);
      strcat(command1, ":");
      strcat(command1, password);
      strcat(command1, "' | sudo chpasswd");
      system(command1);
      printf("New user created successfully!\n");
      break;
      
    default:
      printf("Invalid option selected. Please try again.\n");
      break;
  }
  
  return 0;
}