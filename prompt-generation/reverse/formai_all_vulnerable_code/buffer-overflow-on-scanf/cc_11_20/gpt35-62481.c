//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(){
  int length, uppercase, lowercase, digits, special, count;
  char password[100];
  char chars[94] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
  
  srand(time(NULL));

  printf("Welcome to the Secure Password Generator!\n");

  printf("\nPlease enter the desired length of your password (must be between 8 and 20 characters): ");
  scanf("%d", &length);

  if(length < 8 || length > 20){
    printf("Invalid length. Please enter a length between 8 and 20 characters.");
    return 1;
  }

  printf("\nPlease enter the number of uppercase letters you would like in your password: ");
  scanf("%d", &uppercase);

  if(uppercase < 0 || uppercase > length){
    printf("Invalid input. Uppercase letters must be between 0 and the length of the password.");
    return 1;
  }

  printf("\nPlease enter the number of lowercase letters you would like in your password: ");
  scanf("%d", &lowercase);

  if(lowercase < 0 || lowercase > length){
    printf("Invalid input. Lowercase letters must be between 0 and the length of the password.");
    return 1;
  }

  printf("\nPlease enter the number of digits you would like in your password: ");
  scanf("%d", &digits);

  if(digits < 0 || digits > length){
    printf("Invalid input. Digits must be between 0 and the length of the password.");
    return 1;
  }

  printf("\nPlease enter the number of special characters you would like in your password: ");
  scanf("%d", &special);

  if(special < 0 || special > length){
    printf("Invalid input. Special characters must be between 0 and the length of the password.");
    return 1;
  }

  // Fill array with uppercase letters
  for(count = 0; count < uppercase; count++){
    password[count] = chars[rand() % 26];
  }

  // Fill array with lowercase letters
  for(count = uppercase; count < uppercase + lowercase; count++){
    password[count] = chars[rand() % 26 + 26];
  }

  // Fill array with digits
  for(count = uppercase + lowercase; count < uppercase + lowercase + digits; count++){
    password[count] = chars[rand() % 10 + 52];
  }

  // Fill array with special characters
  for(count = uppercase + lowercase + digits; count < length; count++){
    password[count] = chars[rand() % 14 + 62];
  }

  // Shuffle the array
  for(count = 0; count < length; count++){
    int temp = password[count];
    int random = rand() % length;

    password[count] = password[random];
    password[random] = temp;
  }

  printf("\nYour password is: %s", password);

  return 0;
}