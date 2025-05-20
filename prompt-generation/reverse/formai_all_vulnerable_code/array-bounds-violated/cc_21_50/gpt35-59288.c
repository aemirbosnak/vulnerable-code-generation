//FormAI DATASET v1.0 Category: Data validation ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char name[100], password[100], email[100], address[100], age[3], phoneNumber[20], gender;
  int valid = 1, i;

  // Let's start the program by taking inputs and validating them one by one
  // First, let's validate the name
  printf("Enter your full name: ");
  fgets(name, sizeof(name), stdin);
  name[strlen(name)-1] = '\0'; // Remove the newline character

  for(i = 0; i < strlen(name); i++) {
    if(!isalpha(name[i]) && name[i] != ' ') {
      valid = 0; // If any character is not an alphabet or space, it's not valid
      break;
    }
  }

  if(!valid) {
    printf("Invalid name. Please enter only alphabets and spaces.\n");
    exit(0);
  }

  // Next, let's validate the password
  printf("Enter your password (at least 8 characters and must contain at least one uppercase letter and one lowercase letter): ");
  fgets(password, sizeof(password), stdin);
  password[strlen(password)-1] = '\0';

  if(strlen(password) < 8) {
    printf("Invalid password. Password must be at least 8 characters.\n");
    exit(0);
  }

  int upper = 0, lower = 0;
  for(i = 0; i < strlen(password); i++) {

    if(isupper(password[i])) {
      upper++;
    }
    else if(islower(password[i])) {
      lower++;
    }
  }

  if(upper == 0 || lower == 0) {
    printf("Invalid password. Password must contain at least one uppercase letter and one lowercase letter.\n");
    exit(0);
  }

  // Next, let's validate the email
  printf("Enter your email address: ");
  fgets(email, sizeof(email), stdin);
  email[strlen(email)-1] = '\0';

  int at = 0, dot = 0;
  for(i = 0; i < strlen(email); i++) {
    if(email[i] == '@') {
      at++;
    }
    else if(email[i] == '.') {
      dot++;
    }
  }

  if(at != 1 || dot == 0) {
    printf("Invalid email address. Please enter a valid email address.\n");
    exit(0);
  }

  // Next, let's validate the address
  printf("Enter your address: ");
  fgets(address, sizeof(address), stdin);
  address[strlen(address)-1] = '\0';

  // There's no specific validation for the address, so we can just check if it's not empty
  if(strlen(address) == 0) {
    printf("Invalid address. Please enter a non-empty address.\n");
    exit(0);
  }

  // Next, let's validate the age
  printf("Enter your age: ");
  fgets(age, sizeof(age), stdin);
  age[strlen(age)-1] = '\0';

  for(i = 0; i < strlen(age); i++) {
    if(!isdigit(age[i])) {
      valid = 0; // If any character is not a digit, it's not valid
      break;
    }
  }

  if(!valid) {
    printf("Invalid age. Please enter a valid age.\n");
    exit(0);
  }

  // Next, let's validate the phone number
  printf("Enter your phone number: ");
  fgets(phoneNumber, sizeof(phoneNumber), stdin);
  phoneNumber[strlen(phoneNumber)-1] = '\0';

  for(i = 0; i < strlen(phoneNumber); i++) {
    if(!isdigit(phoneNumber[i]) && phoneNumber[i] != ' ') {
      valid = 0; // If any character is not a digit or space, it's not valid
      break;
    }
  }

  if(!valid) {
    printf("Invalid phone number. Please enter only digits and spaces.\n");
    exit(0);
  }

  // Next, let's validate the gender
  printf("Enter your gender (M/F/O): ");
  scanf("%c", &gender);

  if(gender != 'M' && gender != 'F' && gender != 'O') {
    printf("Invalid gender. Please enter either M, F or O.\n");
    exit(0);
  }

  // If we made it this far, that means everything is valid!
  printf("Congratulations! you have entered all the data correctly.\n");

  return 0;
}