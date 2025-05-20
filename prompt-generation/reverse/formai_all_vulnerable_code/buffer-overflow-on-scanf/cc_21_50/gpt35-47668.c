//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
  char password[50];
  int length, has_lowercase, has_uppercase, has_number, has_special_char;
  
  printf("Enter password: ");
  scanf("%s", password);
  
  length = strlen(password);
  
  // Checking password length
  if(length < 8) {
    printf("Your password is weak. It should contain at least 8 characters.\n");
    return 0;
  }
  
  // Checking password for lowercase characters
  for(int i = 0; i < length; i++) {
    if(password[i] >= 'a' && password[i] <= 'z') {
      has_lowercase = 1;
      break;
    }
  }
  
  if(!has_lowercase) {
    printf("Weak password. It should have at least one lowercase character.\n");
    return 0;
  }
  
  // Checking password for uppercase characters
  for(int i = 0; i < length; i++) {
    if(password[i] >= 'A' && password[i] <= 'Z') {
      has_uppercase = 1;
      break;
    }
  }
  
  if(!has_uppercase) {
    printf("Weak password. It should have at least one uppercase character.\n");
    return 0;
  }
  
  // Checking password for numeric characters
  for(int i = 0; i < length; i++) {
    if(password[i] >= '0' && password[i] <= '9') {
      has_number = 1;
      break;
    }
  }
  
  if(!has_number) {
    printf("Weak password. It should have at least one numeric character.\n");
    return 0;
  }
  
  // Checking password for special characters
  for(int i = 0; i < length; i++) {
    if((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <= '~')) {
      has_special_char = 1;
      break;
    }
  }
  
  if(!has_special_char) {
    printf("Weak password. It should have at least one special character.\n");
    return 0;
  }
  
  printf("Your password is strong!\n");
  
  return 0;
}