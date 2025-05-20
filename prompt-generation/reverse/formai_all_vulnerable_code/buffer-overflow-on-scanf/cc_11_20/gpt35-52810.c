//FormAI DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {
  char str1[100];
  char str2[100];
  int option;

  printf("Enter a string: ");
  fgets(str1, sizeof(str1), stdin);

  printf("\nSelect an option from the menu:\n");
  printf("1. Convert to uppercase\n");
  printf("2. Convert to lowercase\n");
  printf("3. Reverse the string\n");
  printf("4. Calculate the length of the string\n");
  printf("5. Compare with another string\n");
  printf("6. Exit\n");
  scanf("%d", &option);

  switch(option) {
    case 1:
      for(int i=0; i<strlen(str1); i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z') {
          str1[i] = str1[i] - 32;
        }
      }
      printf("\n%s\n", str1);
      break;

    case 2:
      for(int i=0; i<strlen(str1); i++) {
        if(str1[i] >= 'A' && str1[i] <= 'Z') {
          str1[i] = str1[i] + 32;
        }
      }
      printf("\n%s\n", str1);
      break;

    case 3:
      for(int i=strlen(str1)-1; i>=0; i--) {
        printf("%c", str1[i]);
      }
      break;

    case 4:
      printf("\nLength of the string is %ld\n", strlen(str1)-1);
      break;

    case 5:
      printf("\nEnter another string: ");
      getchar();
      fgets(str2, sizeof(str2), stdin);
      if(strcmp(str1, str2) == 0) {
        printf("\nStrings are equal\n");
      } else {
        printf("\nStrings are not equal\n");
      }
      break;

    case 6:
      printf("\nGoodbye!\n");
      break;

    default:
      printf("\nInvalid option, try again.\n");
  }

  return 0;
}