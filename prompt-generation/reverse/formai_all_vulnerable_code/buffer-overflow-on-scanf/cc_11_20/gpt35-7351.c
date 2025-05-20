//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
  char string[100];
  char newstring1[100];
  char newstring2[100];
  
  printf("Please input a string:\n");
  scanf("%s", string);
  
  printf("Your string: %s\n", string);
  
  printf("Let's manipulate your string in a funny way!\n");
  
  // Reverse string
  printf("Here's your string backwards:\n");
  for (int i = strlen(string) - 1; i >= 0; i--) {
    printf("%c", string[i]);
  }
  printf("\n");
  
  // Mix case
  printf("Here's your string with mixed case:\n");
  for (int i = 0; i < strlen(string); i++) {
    if (i % 2 == 0) {
      printf("%c", toupper(string[i]));
    } else {
      printf("%c", tolower(string[i]));
    }
  }
  printf("\n");
  
  // Replace vowels with "00"
  printf("Here's your string with vowels replaced by 00:\n");
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u') {
      printf("00");
    } else {
      printf("%c", string[i]);
    }
  }
  printf("\n");
  
  // Remove spaces
  printf("Here's your string without spaces:\n");
  int j = 0;
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] != ' ') {
      newstring1[j] = string[i];
      j++;
    }
  }
  printf("%s\n", newstring1);
  
  // Replace "hello" with "goodbye"
  printf("Here's your string with \"hello\" replaced by \"goodbye\":\n");
  char* p = string;
  while (p = strstr(p, "hello")) {
    strncpy(newstring2, string, p - string);
    newstring2[p - string] = '\0';
    strcat(newstring2, "goodbye");
    strcat(newstring2, p+5);
    p++;
  }
  if (newstring2[0] == '\0') {
    printf("%s\n", string);
  } else {
    printf("%s\n", newstring2);
  }
  
  printf("Congratulations, your string has been hilariously manipulated!\n");
  
  return 0;
}