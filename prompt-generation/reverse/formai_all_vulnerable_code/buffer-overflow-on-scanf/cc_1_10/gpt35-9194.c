//FormAI DATASET v1.0 Category: Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  float num_1, num_2, result;
  char operator;

  printf("Wow! You stumbled upon the coolest Calculator program ever!\n\n");

  printf("Please enter the first number: ");
  scanf("%f", &num_1);
  
  printf("Which mathematical operator would you like to use? (+, -, *, /, %%) ");
  scanf(" %c", &operator);

  printf("Now enter the second number: ");
  scanf("%f", &num_2);

  switch(operator) {
    case '+':
      result = num_1 + num_2;
      printf("The sum of %.2f and %.2f is %.2f!\n", num_1, num_2, result);
      break;
      
    case '-':
      result = num_1 - num_2;
      printf("The difference between %.2f and %.2f is %.2f!\n", num_1, num_2, result);
      break;

    case '*':
      result = num_1 * num_2;
      printf("The product of %.2f and %.2f is %.2f!\n", num_1, num_2, result);
      break;

    case '/':
      if(num_2 == 0) {
        printf("Error! Division by zero is not possible!\n");
        exit(EXIT_FAILURE);
      }
      else {
        result = num_1 / num_2;
        printf("The quotient of %.2f divided by %.2f is %.2f!\n", num_1, num_2, result);
      }
      break;
      
    case '%':
      if((int)num_2 == 0) {
        printf("Error! Division by zero is not possible!\n");
        exit(EXIT_FAILURE);
      }
      else {
        result = (int)num_1 % (int)num_2;
        printf("The remainder of dividing %.2f by %.2f is %.2f!\n", num_1, num_2, result);
      }
      break;

    default:
      printf("Invalid operator! Please try again.\n");
  }

  printf("\nThank you for using the coolest Calculator program ever! Have a great day!");
  
  return 0;
}