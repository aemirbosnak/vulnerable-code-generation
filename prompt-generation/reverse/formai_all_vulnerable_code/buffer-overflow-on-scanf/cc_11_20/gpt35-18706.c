//FormAI DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
  char password[50];
  char repeat[50];
  int strength = 0;
  
  // Introduction
  printf("Hail traveler!\n");
  printf("In order to enter the castle, you must prove yourself by setting a secure password.\n");
  printf("Your password must be at least 8 characters long, contain at least one uppercase letter, one lowercase letter, one digit and one special character.\n");
  
  // Get user input for password
  while (1) {
    printf("\nEnter your password: ");
    scanf("%s", password);
    
    // Check password strength
    for (int i = 0; i < strlen(password); i++) {
      if ('A' <= password[i] && password[i] <= 'Z') {
        strength |= 1;
      } else if ('a' <= password[i] && password[i] <= 'z') {
        strength |= 2;
      } else if ('0' <= password[i] && password[i] <= '9') {
        strength |= 4;
      } else {
        strength |= 8;
      }
    }
    
    // Check password length
    if (strlen(password) < 8) {
      printf("Your password is too short! It must be at least 8 characters long.\n");
    }
    
    // Check password strength
    if (strength != 15) {
      printf("Your password is not strong enough! It must contain at least one uppercase letter, one lowercase letter, one digit and one special character.\n");
    } else {
      // Get user input for repeat password
      while (1) {
        printf("Enter your password again to confirm: ");
        scanf("%s", repeat);
        
        // Check if passwords match
        if (strcmp(password, repeat) == 0) {
          printf("Your password has been set! Welcome to the castle!\n");
          return 0;
        } else {
          printf("Your passwords do not match! Please try again.\n");
        }
      }
    }
    
    // Reset password strength and repeat password for new attempt
    strength = 0;
    memset(repeat, 0, sizeof(repeat));
  }
}