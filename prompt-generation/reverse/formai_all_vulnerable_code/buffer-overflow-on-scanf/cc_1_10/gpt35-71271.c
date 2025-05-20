//FormAI DATASET v1.0 Category: String manipulation ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {
  char str1[50], str2[50];
  int choice, i;

  printf("Welcome to the String Manipulation program!\n\n");

  do {
    printf("Select an option to perform a string manipulation:\n");
    printf("1. Concatenate two strings.\n");
    printf("2. Reverse a string.\n");
    printf("3. Check if a string is a palindrome.\n");
    printf("4. Exit the program.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter the first string: ");
        scanf("%s", str1);
        printf("Enter the second string: ");
        scanf("%s", str2);

        strcat(str1, str2);
        printf("\nConcatenated string is: %s\n\n", str1);
        break;

      case 2:
        printf("\nEnter a string to reverse: ");
        scanf("%s", str1);

        printf("Reversed string is: ");
        for(i = strlen(str1) - 1; i >= 0; i--) {
          printf("%c", str1[i]);
        }

        printf("\n\n");
        break;

      case 3:
        printf("\nEnter a string to check for palindrome: ");
        scanf("%s", str1);

        int len = strlen(str1);
        int flag = 1;
        for(i = 0; i < len/2; i++) {
          if(str1[i] != str1[len-i-1]) {
            flag = 0;
            break;
          }
        }

        if(flag) {
          printf("\n%s is a palindrome!\n\n", str1);
        } else {
          printf("\n%s is not a palindrome!\n\n", str1);
        }

        break;

      case 4:
        printf("\nThank you for using this program!\n");
        break;

      default:
        printf("\nInvalid choice! Please enter a valid choice.\n\n");
        break;
    }
  } while(choice != 4);

  return 0;
}