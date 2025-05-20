//FormAI DATASET v1.0 Category: Recursive ; Style: unmistakable
#include <stdio.h>

//Function to calculate factorial recursively
int factorial(int n){
  // Base case
  if (n == 0){
    return 1;
  }
  // Recursive case
  else{
    return n * factorial(n-1);
  }
}

//Function to calculate fibonacci sequence recursively
int fibonacci(int n){
  // Base case
  if (n == 0 || n == 1){
    return n;
  }
  // Recursive case
  else{
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main(){
  int num, choice;

  printf("Enter a positive integer: ");
  scanf("%d", &num);

  printf("\nChoose an option:\n1. Find factorial\n2. Generate fibonacci sequence\n");
  scanf("%d", &choice);

  switch(choice){
    case 1:
      printf("\nFactorial of %d is %d\n", num, factorial(num));
      break;

    case 2:
      printf("\nFibonacci sequence:\n");
      for (int i = 0; i < num; i++){
        printf("%d ", fibonacci(i));
      }
      printf("\n");
      break;

    default:
      printf("\nInvalid input\n");
      break;
  }

  return 0;
}