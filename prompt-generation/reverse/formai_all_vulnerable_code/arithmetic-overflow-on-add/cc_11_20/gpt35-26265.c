//FormAI DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int num1, num2, num3, num4, num5, num6, largest, smallest, sum, average;
  
  printf("Enter six integers:\n");
  scanf("%d%d%d%d%d%d", &num1, &num2, &num3, &num4, &num5, &num6);
  
  // Find the largest number
  largest = num1;
  if(largest < num2) {
    largest = num2;
  }
  if(largest < num3) {
    largest = num3;
  }
  if(largest < num4) {
    largest = num4;
  }
  if(largest < num5) {
    largest = num5;
  }
  if(largest < num6) {
    largest = num6;
  }
  printf("\nThe largest number is %d\n", largest);
  
  // Find the smallest number
  smallest = num1;
  if(smallest > num2) {
    smallest = num2;
  }
  if(smallest > num3) {
    smallest = num3;
  }
  if(smallest > num4) {
    smallest = num4;
  }
  if(smallest > num5) {
    smallest = num5;
  }
  if(smallest > num6) {
    smallest = num6;
  }
  printf("The smallest number is %d\n", smallest);
  
  // Find the sum of all the numbers
  sum = num1 + num2 + num3 + num4 + num5 + num6;
  printf("The sum of all the numbers is %d\n", sum);
  
  // Find the average of all the numbers
  average = sum / 6;
  printf("The average of all the numbers is %d\n", average);
  
  // Find the square root of the largest number
  double square_root = sqrt(largest);
  printf("The square root of the largest number is %f\n", square_root);
  
  // Find the absolute value of the smallest number
  int absolute_value = abs(smallest);
  printf("The absolute value of the smallest number is %d\n", absolute_value);
  
  return 0;
}