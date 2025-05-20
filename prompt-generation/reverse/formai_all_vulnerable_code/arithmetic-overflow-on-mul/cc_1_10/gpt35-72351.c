//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  int count = 0;
  char word[50];
  printf("Please enter a sentence. \n");
  fgets(word, 50, stdin);
  for (int i = 0; word[i] != '\0'; i++) {
    if (word[i] == ' ') {
      count++;
    }
  }
  printf("Your sentence has %d words in it.\n", count + 1);

  for (int i = 0; word[i] != '\0'; i++) {
    if (isupper(word[i])) {
      printf("%c", tolower(word[i]));
    } else if (islower(word[i])) {
      printf("%c", toupper(word[i]));
    } else {
      printf("%c", word[i]);
    }
  }

  printf("\n");
  char str1[50], str2[50];
  printf("Please enter a string \n");
  scanf("%s", str1);
  printf("Please enter another string \n");
  scanf("%s", str2);
  strcat(str1, str2);
  printf("The concatenated string is: %s \n", str1);

  printf("Please enter a string \n");
  char str3[50];
  scanf("%s", str3);
  int len = strlen(str3);
  for (int i = 0; i < len / 2; i++) {
    char temp = str3[i];
    str3[i] = str3[len - i - 1];
    str3[len - i - 1] = temp;
  }
  printf("The reverse of the string is: %s \n", str3);

  int num1, num2;
  printf("Please enter a number \n");
  scanf("%d", &num1);
  printf("Please enter another number \n");
  scanf("%d", &num2);
  printf("The sum is: %d \n", num1 + num2);
  printf("The difference is: %d \n", num1 - num2);
  printf("The product is: %d \n", num1 * num2);
  printf("The quotient is: %d \n", num1 / num2);
  printf("The remainder is: %d \n", num1 % num2);

  return 0;
}