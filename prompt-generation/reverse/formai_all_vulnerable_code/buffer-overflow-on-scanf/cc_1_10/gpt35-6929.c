//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  printf("Welcome to the Crazy Calculator!\n");
  printf("This calculator is unlike any other, it will blow your mind!\n");
  
  int num1, num2, result;
  char operator;
  
  srand(time(NULL));
  
  while(1){
    num1 = rand()%100 + 1;
    num2 = rand()%100 + 1;
    
    printf("\nPlease enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    
    switch(operator){
      case '+':
        result = num1 + num2;
        printf("The sum of %d and %d is %d.\n", num1, num2, result);
        break;
      case '-':
        result = num1 - num2;
        printf("The difference between %d and %d is %d.\n", num1, num2, result);
        break;
      case '*':
        result = num1 * num2;
        printf("The product of %d and %d is %d.\n", num1, num2, result);
        break;
      case '/':
        if(num2==0){
          printf("Oops! Division by zero is not allowed. Please try again.\n");
          break;
        }
        result = num1 / num2;
        printf("The result of %d divided by %d is %d.\n", num1, num2, result);
        break;
      default:
        printf("Invalid operator. Please try again.\n");
        break;
    }
    
    char choice;
    printf("\nDo you want to continue (Y/N)? ");
    scanf(" %c", &choice);
    
    if(choice=='N' || choice=='n'){
      printf("Thank you for using the Crazy Calculator. Goodbye!\n");
      break;
    }
  }
  
  return 0;
}