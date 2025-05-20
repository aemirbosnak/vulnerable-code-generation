//FormAI DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>

#define MAX_SIZE 10

int main() {
  char passwords[MAX_SIZE][30];
  char master_password[30];
  int num_passwords = 0;
  
  // Ask the user to input the master password
  printf("Please enter your master password: ");
  scanf("%s", master_password);
  
  // Loop through until the user enters the correct master password
  while (1) {
    char input[30];
    printf("Enter 'p' to add a new password, 'r' to retrieve a password, or 'q' to quit: ");
    scanf("%s", input);
    
    // If the user enters 'q', terminate the program
    if (input[0] == 'q') {
      printf("Goodbye!");
      return 0;
    } 
    
    // If the user enters 'p', add a new password
    else if (input[0] == 'p') {
      if (num_passwords >= MAX_SIZE) {
        printf("You have reached the maximum number of passwords.\n");
      } else {
        char new_password[30];
        printf("Enter the new password: ");
        scanf("%s", new_password);
        strcpy(passwords[num_passwords], new_password);
        num_passwords++;
        printf("Password added successfully!\n");
      }
    } 
    
    // If the user enters 'r', retrieve an existing password
    else if (input[0] == 'r') {
      char check_password[30];
      printf("Please enter your master password to retrieve a password: ");
      scanf("%s", check_password);
      if (strcmp(check_password, master_password) != 0) {
        printf("Incorrect master password.\n");
      } else {
        int password_index;
        printf("Which password would you like to retrieve? (Enter a number 1-%d): ", num_passwords);
        scanf("%d", &password_index);
        if (password_index < 1 || password_index > num_passwords) {
          printf("Invalid input.\n");
        } else {
          printf("Password for index %d: %s\n", password_index, passwords[password_index-1]);
        }
      }
    } 
    
    // If the user enters an invalid input, ask again
    else {
      printf("Invalid input.\n");
    }
  }
  return 0;
}