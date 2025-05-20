//FormAI DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10 // Maximum number of passwords the user can save
#define MAX_PASSWORD_LENGTH 20 // Maximum length of a single password

// Function declaration
void add_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords);
void view_passwords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int num_passwords);
void delete_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords);

int main(){
  char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
  int num_passwords = 0;
  int choice;
  
  while(1) { // Loop through the menu
    printf("---------------\n");
    printf("Password Manager\n");
    printf("---------------\n");
    printf("1. Add a password\n");
    printf("2. View saved passwords\n");
    printf("3. Delete a password\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice){
      case 1:
        add_password(passwords, &num_passwords);
        break;
      case 2:
        view_passwords(passwords, num_passwords);
        break;
      case 3:
        delete_password(passwords, &num_passwords);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  
  return 0;
}

// Function to add a password
void add_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords){
  if(*num_passwords == MAX_PASSWORDS){
    printf("Error: Maximum number of passwords reached\n");
    return;
  }
  
  char new_password[MAX_PASSWORD_LENGTH];
  
  printf("Enter a new password (up to %d characters): ", MAX_PASSWORD_LENGTH-1);
  scanf("%s", new_password);
  
  // Check if password already exists
  for(int i=0; i<*num_passwords; i++){
    if(strcmp(passwords[i], new_password) == 0){
      printf("Error: Password already exists\n");
      return;
    }
  }
  
  // Add the new password to the array
  strcpy(passwords[*num_passwords], new_password);
  *num_passwords += 1;
  
  printf("Password added successfully\n");
}

// Function to view all saved passwords
void view_passwords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int num_passwords){
  if(num_passwords == 0){
    printf("No passwords saved\n");
    return;
  }
  
  printf("\nSaved Passwords:\n");
  for(int i=0; i<num_passwords; i++){
    printf("- %s\n", passwords[i]);
  }
  printf("\n");
}

// Function to delete a password
void delete_password(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *num_passwords){
  if(*num_passwords == 0){
    printf("No passwords saved\n");
    return;
  }
  
  char password_to_delete[MAX_PASSWORD_LENGTH];
  
  printf("Enter the password to delete: ");
  scanf("%s", password_to_delete);
  
  // Find the password to delete and shift the rest of the array over it
  int index_to_delete = -1;
  for(int i=0; i<*num_passwords; i++){
    if(strcmp(passwords[i], password_to_delete) == 0){
      index_to_delete = i;
    }
    if(index_to_delete >= 0 && i < *num_passwords-1){
      strcpy(passwords[i], passwords[i+1]);
    }
  }
  
  if(index_to_delete == -1){
    printf("Error: Password not found\n");
    return;
  }
  
  *num_passwords -= 1;
  
  printf("Password deleted successfully\n");
}