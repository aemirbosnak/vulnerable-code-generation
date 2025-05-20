//FormAI DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>

int main() {
  // Declare variables
  int num1, num2, num3;
  float avg;
  
  // Read input numbers
  printf("Enter three numbers: ");
  scanf("%d%d%d", &num1, &num2, &num3);
  
  // Calculate the average
  avg = (num1 + num2 + num3) / 3.0;
  
  // Print the average
  printf("The average of %d, %d, and %d is %.2f\n", num1, num2, num3, avg);
  
  // Check if any of the numbers is negative
  if (num1 < 0 || num2 < 0 || num3 < 0) {
    printf("At least one of the numbers is negative!\n");
  }
  
  // Check if the numbers are in ascending order
  if (num1 < num2 && num2 < num3) {
    printf("The numbers are in ascending order.\n");
  } else {
    printf("The numbers are not in ascending order.\n");
  }
  
  // Calculate the product of the numbers
  long long product = (long long) num1 * num2 * num3;
  
  // Print the product
  printf("The product of %d, %d, and %d is %lld\n", num1, num2, num3, product);
  
  // Check if the product is divisible by 5
  if (product % 5 == 0) {
    printf("The product is divisible by 5!\n");
  } else {
    printf("The product is not divisible by 5.\n");
  }
  
  // Check if the product is a perfect square
  for (int i = 1; i <= product; i++) {
    if (i * i == product) {
      printf("The product is a perfect square!\n");
      return 0;
    }
  }
  printf("The product is not a perfect square.\n");
  
  return 0;
}