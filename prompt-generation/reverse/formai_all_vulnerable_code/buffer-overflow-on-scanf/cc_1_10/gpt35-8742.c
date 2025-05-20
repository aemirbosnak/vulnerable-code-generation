//FormAI DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {
  char str1[50];
  char str2[50];
  int choice;

  printf("Welcome! This program allows you to manipulate two C-strings.\n");
  printf("Please enter the first string: ");
  fgets(str1, 50, stdin);
  printf("Please enter the second string: ");
  fgets(str2, 50, stdin);

  printf("Please select a string manipulation option:\n");
  printf("1. Concatenate the two strings.\n");
  printf("2. Compare the two strings.\n");
  printf("3. Copy the second string into the first string.\n");
  printf("4. Find the length of each string.\n");
  printf("5. Exit the program.\n");

  do {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        strcat(str1, str2);
        printf("The concatenated string is: %s\n", str1);
        break;

      case 2:
        if (strcmp(str1, str2) == 0) {
          printf("The two strings are equal.\n");
        }
        else {
          printf("The two strings are not equal.\n");
        }
        break;

      case 3:
        strcpy(str1, str2);
        printf("The first string is now: %s\n", str1);
        break;

      case 4:
        printf("The length of the first string is %d.\n", strlen(str1)-1);
        printf("The length of the second string is %d.\n", strlen(str2)-1);
        break;

      case 5:
        printf("Thank you for using this program! Goodbye.\n");
        break;

      default:
        printf("Invalid input. Please try again.\n");
        break;
    }
  } while(choice != 5);

  return 0;
}