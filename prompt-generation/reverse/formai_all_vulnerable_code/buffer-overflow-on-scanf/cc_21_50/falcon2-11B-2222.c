//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv) {
  char input[100];
  int flag = 0;
  int num1 = 0, num2 = 0, result = 0;

  while (scanf("%s", input)!= EOF) {
    if (strlen(input) == 0) break;

    if (isdigit(input[0])) {
      flag = 0;
      for (int i = 0; input[i]!= '\0'; i++) {
        if (!isdigit(input[i])) {
          flag = 1;
          break;
        }
      }

      if (flag == 0) {
        num1 = atoi(input);
        printf("You have entered %d.\n", num1);
      }
    } else if (input[0] == '-') {
      flag = 0;
      for (int i = 1; input[i]!= '\0'; i++) {
        if (!isdigit(input[i])) {
          flag = 1;
          break;
        }
      }

      if (flag == 0) {
        num2 = atoi(input + 1);
        printf("You have entered %d.\n", num2);
      }
    } else {
      flag = 0;
      for (int i = 0; input[i]!= '\0'; i++) {
        if (!isalpha(input[i])) {
          flag = 1;
          break;
        }
      }

      if (flag == 0) {
        if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/') {
          printf("Operator entered: %c\n", input[0]);
        } else {
          printf("Error: Invalid input.\n");
        }
      }
    }

    if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/') {
      flag = 0;
      for (int i = 0; input[i]!= '\0'; i++) {
        if (!isdigit(input[i])) {
          flag = 1;
          break;
        }
      }

      if (flag == 0) {
        if (input[0] == '+') {
          result = num1 + num2;
          printf("Result: %d\n", result);
        } else if (input[0] == '-') {
          result = num1 - num2;
          printf("Result: %d\n", result);
        } else if (input[0] == '*') {
          result = num1 * num2;
          printf("Result: %d\n", result);
        } else if (input[0] == '/') {
          if (num2 == 0) {
            printf("Error: Division by zero.\n");
          } else {
            result = num1 / num2;
            printf("Result: %d\n", result);
          }
        }
      } else {
        printf("Error: Invalid input.\n");
      }
    } else {
      printf("Error: Invalid input.\n");
    }
  }

  return 0;
}