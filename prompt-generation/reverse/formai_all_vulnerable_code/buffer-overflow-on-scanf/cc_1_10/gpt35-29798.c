//FormAI DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int length, i; 

  printf("Enter the length of the array: ");
  scanf("%d", &length);

  int *array = (int *) malloc(length * sizeof(int)); 

  if (array == NULL) { 
    printf("Memory allocation failed.\n");
    return 1; 
  }

  printf("Enter the elements of the array:\n");
  for (i = 0; i < length; i++) {
    printf("Element %d: ", i+1);
    scanf("%d", &array[i]); 
  }

  printf("\nOriginal Array: [ ");
  for (i = 0; i < length; i++) {
      printf("%d ", array[i]);
  }
  printf("]\n");
  
  int sum = 0;
  float average;
  
  for (i = 0; i < length; i++) {
      sum += array[i];
  }
  
  average = (float) sum / length;
  
  printf("\nSum of the array elements: %d\n", sum);
  printf("Average of the array elements: %.2f\n", average);
  
  int max = array[0];
  
  for (i = 1; i < length; i++) {
      if (array[i] > max) {
          max = array[i];
      }
  }
  
  printf("Maximum element in the array: %d\n", max);

  int min = array[0];
  
  for (i = 1; i < length; i++) {
      if (array[i] < min){
          min = array[i];
      }
  }
  
  printf("Minimum element in the array: %d\n", min);
  
  free(array);
  
  return 0;
}