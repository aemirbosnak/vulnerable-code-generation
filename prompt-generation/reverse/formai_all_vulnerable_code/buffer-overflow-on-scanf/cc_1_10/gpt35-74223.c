//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>

int main() {
  int num;
  
  printf("Enter a number: ");
  scanf("%d", &num);
  
  if(num % 2 == 0) {
    printf("The number is even!");
  } else {
    printf("The number is odd!");
  }
  
  printf("\nThe first %d numbers in the fibonacci sequence are: ", num);
  
  int i, a = 0, b = 1, c;
  
  for(i = 1; i <= num; i++) {
    printf("%d ", a);
    c = a + b;
    a = b;
    b = c;
  }
  
  printf("\nThe sum of %d numbers from 1 to %d is: ", num, num);
  
  int sum = 0;
  
  for(i = 1; i <= num; i++) {
    sum += i;
  }
  
  printf("%d ", sum);
  
  printf("The prime numbers from 1 to %d are: ", num);
  
  int j, isPrime;
  
  for(i = 2; i <= num; i++) {
    isPrime = 1;
    for(j = 2; j < i; j++) {
      if(i % j == 0) {
        isPrime = 0;
        break;
      }
    }
    if(isPrime) {
      printf("%d ", i);
    }
  }
  
  printf("The factorial of %d is: ", num);
  
  int factorial = 1;
  
  for(i = num; i > 0; i--) {
    factorial *= i;
  }
  
  printf("%d", factorial);
  
  return 0;
}