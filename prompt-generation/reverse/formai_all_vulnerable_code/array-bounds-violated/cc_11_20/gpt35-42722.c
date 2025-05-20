//FormAI DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
  char name[20];
  char thankfulMessage[100];

  printf("Hello there! What's your name? ");
  scanf("%s", name);

  printf("\nGreat to meet you, %s!\n\n", name);

  printf("Please enter a message that you are grateful for: ");
  getchar(); // to remove the \n character from the input buffer after scanf
  fgets(thankfulMessage, 100, stdin);

  // Removing the trailing newline character from the input
  if(thankfulMessage[strlen(thankfulMessage) - 1] == '\n') {
     thankfulMessage[strlen(thankfulMessage) - 1] = '\0';
  }

  printf("\nYour message is: \"%s\"\n\n", thankfulMessage);

  // Reversing the message
  printf("Reversed message: \"");
  for(int i = strlen(thankfulMessage) - 1; i >= 0; i--) {
    printf("%c", thankfulMessage[i]);
  }
  printf("\"\n");

  // Converting the message to uppercase
  printf("Uppercase message: \"");
  for(int i = 0; i < strlen(thankfulMessage); i++) {
    printf("%c", toupper(thankfulMessage[i]));
  }
  printf("\"\n");

  // Converting the message to lowercase
  printf("Lowercase message: \"");
  for(int i = 0; i < strlen(thankfulMessage); i++) {
    printf("%c", tolower(thankfulMessage[i]));
  }
  printf("\"\n");

  // Counting the number of vowels in the message
  int vowelsCount = 0;
  for(int i = 0; i < strlen(thankfulMessage); i++) {
    if(thankfulMessage[i] == 'a' || thankfulMessage[i] == 'e' || thankfulMessage[i] == 'i' || thankfulMessage[i] == 'o' || thankfulMessage[i] == 'u' || thankfulMessage[i] == 'A' || thankfulMessage[i] == 'E' || thankfulMessage[i] == 'I' || thankfulMessage[i] == 'O' || thankfulMessage[i] == 'U') {
      vowelsCount++;
    }
  }
  printf("\nNumber of vowels in the message: %d\n", vowelsCount);

  printf("\nThanks for using our program, %s!\n\n", name);

  return 0;
}