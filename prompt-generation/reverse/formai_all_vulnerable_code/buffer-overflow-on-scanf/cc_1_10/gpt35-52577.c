//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function that generates random integers within a range
int generate_random(int min, int max){
  return min + rand() % (max - min + 1);
}

// Function that sorts an array using bubble sort
void bubble_sort(int arr[], int n){
  int i, j, temp;
  for(i = 0; i < n-1; i++){
    for(j = 0; j < n-i-1; j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main(){
  // Initialize variables and arrays
  int i, n, min, max; 
  int arr[MAX_SIZE];

  // Prompt user for input
  printf("Enter the number of elements (max %d): ", MAX_SIZE);
  scanf("%d", &n);
  printf("Enter the minimum value: ");
  scanf("%d", &min);
  printf("Enter the maximum value: ");
  scanf("%d", &max);

  // Generate random integers and fill array
  srand(time(NULL));
  for(i = 0; i < n; i++){
    arr[i] = generate_random(min, max);
  }

  // Sort the array using bubble sort
  bubble_sort(arr, n);

  // Print out the sorted array
  printf("Sorted Array: ");
  for(i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}