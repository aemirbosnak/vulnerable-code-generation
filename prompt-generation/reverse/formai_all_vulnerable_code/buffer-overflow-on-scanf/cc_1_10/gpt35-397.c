//FormAI DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main(){
  //Initializing variables
  int num1, num2, sum, sub, mul;
  float div;
  char op = '+';

  //Asking user for input
  printf("Enter first number: ");
  scanf("%d", &num1);

  printf("Enter second number: ");
  scanf("%d", &num2);

  //Calculate sum
  sum = num1 + num2;

  //Print sum
  printf("The sum of %d and %d is %d\n", num1, num2, sum);

  //Calculate subtraction
  sub = num1 - num2;

  //Print subtraction
  printf("The subtraction of %d and %d is %d\n", num1, num2, sub);

  //Calculate multiplication
  mul = num1 * num2;

  //Print multiplication
  printf("The multiplication of %d and %d is %d\n", num1, num2, mul);

  //Check if divisor is 0
  if(num2 == 0){
    printf("Cannot divide by 0\n");
  }
  else{
    //Calculate division
    div = (float)num1 / num2;

    //Print division
    printf("The division of %d and %d is %.2f\n", num1, num2, div);
  }

  //Print protected message
  printf("\nThis program was created by a dedicated developer who truly values their work and strives to protect their code!\n");

  return 0;
}