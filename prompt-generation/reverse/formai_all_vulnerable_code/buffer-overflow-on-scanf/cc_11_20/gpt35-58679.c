//FormAI DATASET v1.0 Category: Data validation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
  // Welcome message
  printf("Welcome to the Data Validation Program! Let's validate some input!\n");

  // Prompt user for phone number input
  printf("Please enter your phone number (format: XXX-XXX-XXXX):\n");

  // Validate phone number input
  char phone_number[12];
  int i;

  for(i = 0; i < 12; i++) {
    scanf("%c", &phone_number[i]);
  }

  // Check format of phone number
  if(phone_number[3] != '-' || phone_number[7] != '-')
    printf("Invalid phone number format! Please try again.\n");

  // Prompt user for email address input
  printf("Great! Now please enter your email address:\n");

  // Validate email address input
  char email_address[50];

  scanf("%s", email_address);

  int email_length = strlen(email_address);

  int at_counter = 0;
  int dot_counter = 0;

  for(i = 0; i < email_length; i++) {
    if(email_address[i] == '@')
      at_counter++;
    if(email_address[i] == '.')
      dot_counter++;
  }

  if(at_counter != 1 || dot_counter < 1 || dot_counter > 2)
    printf("Invalid email address! Please try again.\n");

  // Prompt user for age input
  printf("Awesome! Finally, please enter your age:\n");

  // Validate age input
  int age;

  scanf("%d", &age);

  if(age < 0 || age > 150)
    printf("Invalid age! Please try again.\n");

  // Congratulate user
  printf("Congratulations! You have successfully validated your input!\n");

  return 0;
}