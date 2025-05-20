//FormAI DATASET v1.0 Category: Educational ; Style: relaxed
#include <stdio.h>

/* This program reads a list of numbers from the user and calculates their average. 
 * It also finds and prints the maximum and minimum numbers. 
 * The user decides how many numbers they want to enter. */

int main() {

  int num, i;
  float avg, sum = 0.0;
  int max, min;
  
  printf("Enter the number of elements: ");
  scanf("%d", &num);
  
  int arr[num];
  
  // loop to read in the numbers and calculate their sum
  for(i = 0; i < num; i++) {
    printf("Enter number %d: ", i+1);
    scanf("%d", &arr[i]);
    
    sum += arr[i];
  }
  
  // calculate the average
  avg = sum / num;
  
  //initialize max and min to the first element of the array
  max = arr[0];
  min = arr[0];
  
  // loop to find the maximum and minimum values in the array
  for(i = 1; i < num; i++) {
    if(arr[i] > max) {
      max = arr[i];
    }
    
    if(arr[i] < min) {
      min = arr[i];
    }
  }
  
  // print out the results
  printf("Average = %.2f\n", avg);
  printf("Maximum = %d\n", max);
  printf("Minimum = %d\n", min);
  
  return 0;
}