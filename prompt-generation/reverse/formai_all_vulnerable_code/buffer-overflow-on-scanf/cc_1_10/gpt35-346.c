//FormAI DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d",&n);
  printf("You have entered the number: %d\n",n);
  
  // Checking if the number is even or odd
  if(n % 2 == 0) {
    printf("%d is an even number.\n",n);
  }
  else {
    printf("%d is an odd number.\n",n);
  }
  
  // Sum of numbers upto n
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    sum += i;
  }
  printf("Sum of numbers upto %d is: %d\n",n,sum);
  
  // Calculate Fibonacci Sequence
  int fib1 = 0, fib2 = 1, temp;
  printf("Fibonacci Sequence of %d numbers: ",n);
  for(int i = 1; i <= n; i++) {
    printf("%d ",fib1);
    temp = fib1;
    fib1 = fib2;
    fib2 = temp + fib2;
  }
  printf("\n");
  
  // Calculating prime numbers upto n
  int prime;
  printf("Prime numbers upto %d are: ",n);
  for(int i = 2; i <= n; i++) {
    prime = 1;
    for(int j = 2; j < i; j++) {
      if(i % j == 0) {
        prime = 0;
        break;
      }
    }
    if(prime == 1) {
      printf("%d ",i);
    }
  }
  printf("\n");
  
  return 0;
}