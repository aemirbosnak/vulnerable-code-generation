//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Define variables
  int length, num_digit, num_special, i, num;
  int digits[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
  int uppercase[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
  int lowercase[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
  int special[] = {33, 35, 36, 37, 38, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125, 126};
  char password[100];
  
  // Get user inputs for password requirements
  printf("Enter the length of the password (6-50): ");
  scanf("%d", &length);
  printf("Enter the minimum number of digits required: ");
  scanf("%d", &num_digit);
  printf("Enter the minimum number of special characters required: ");
  scanf("%d", &num_special);
  
  // Check if user inputs are valid
  if (length < 6 || length > 50) {
    printf("Password length must be between 6 and 50. Please try again.\n");
    return 1;
  }
  
  if (num_digit < 0 || num_digit > length) {
    printf("Number of digits must be between 0 and the length of the password. Please try again.\n");
    return 1;
  }
  
  if (num_special < 0 || num_special > length) {
    printf("Number of special characters must be between 0 and the length of the password. Please try again.\n");
    return 1;
  }
  
  // Generate random password
  srand(time(NULL));
  
  for (i = 0; i < length; i++) {
    num = rand() % 4;
    
    switch (num) {
      case 0:
        // Add uppercase letter
        password[i] = uppercase[rand() % 26];
        break;
      case 1:
        // Add lowercase letter
        password[i] = lowercase[rand() % 26];
        break;
      case 2:
        // Add digit
        if (num_digit > 0) {
          password[i] = digits[rand() % 10];
          num_digit--;
        } else {
          i--;
        }
        break;
      case 3:
        // Add special character
        if (num_special > 0) {
          password[i] = special[rand() % 28];
          num_special--;
        } else {
          i--;
        }
        break;
    }
  }
  
  password[length] = '\0';
  printf("Your randomly generated password is: %s\n", password);
  
  return 0;
}