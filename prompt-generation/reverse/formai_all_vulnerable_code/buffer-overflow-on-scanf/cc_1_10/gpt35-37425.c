//FormAI DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
  char message[100];
  char reverse[100];
  printf("Welcome to the exciting String Manipulation Program!\n");
  printf("Enter a message: ");
  scanf("%[^\n]", message);

  // Remove any spaces from the message
  char no_spaces[100];
  int i, j = 0;
  for (i = 0; message[i] != '\0'; i++) {
    if (message[i] != ' ') {
      no_spaces[j++] = message[i];
    }
  }
  no_spaces[j] = '\0';
  printf("Your message without spaces is: %s\n", no_spaces);

  // Convert all letters to uppercase
  char uppercase[100];
  for (i = 0; no_spaces[i] != '\0'; i++) {
    uppercase[i] = toupper(no_spaces[i]);
  }
  uppercase[i] = '\0';
  printf("Your message in all uppercase is: %s\n", uppercase);

  // Reverse the message
  int length = strlen(no_spaces);
  for (i = length - 1, j = 0; i >= 0; i--, j++) {
    reverse[j] = no_spaces[i];
  }
  reverse[j] = '\0';
  printf("Your message reversed is: %s\n", reverse);

  // Check if message is a palindrome
  if (strcmp(no_spaces, reverse) == 0) {
    printf("Your message is a palindrome! Wow!\n");
  } else {
    printf("Your message is not a palindrome. Keep trying!\n");
  }

  // Add exclamation marks to the end of the message
  int num_exclamations;
  printf("How many exclamation marks do you want to add to the end of your message? ");
  scanf("%d", &num_exclamations);
  if (num_exclamations > 0) {
    char exclamations[100];
    for (i = 0; i < num_exclamations; i++) {
      exclamations[i] = '!';
    }
    exclamations[i] = '\0';
  
    char final_message[200];
    sprintf(final_message, "%s%s", uppercase, exclamations);
    printf("Your final message is: %s\n", final_message);
  }

  printf("Thank you for using the String Manipulation Program! Have a great day!\n");

  return 0;
}