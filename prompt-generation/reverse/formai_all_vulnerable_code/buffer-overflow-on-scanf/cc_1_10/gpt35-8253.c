//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>

// A function to sort an array in ascending order
void sort(int arr[], int n) {
   int i, j, temp;
   for(i = 0; i < n-1; i++) {
      for(j = i+1; j < n; j++) {
         if(arr[i] > arr[j]) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
   }
}

// Function to find the minimum value of two integers
int min(int a, int b) {
   return (a < b) ? a : b;
}

// Function to find the maximum value of two integers
int max(int a, int b) {
   return (a > b) ? a : b;
}

// Function to find the maximum sum of contiguous subarray of size k
int findMaxSum(int arr[], int n, int k) {
   // Sort the array in ascending order
   sort(arr, n);
   // Initialize sum and maxSum variables
   int i, sum = 0, maxSum = 0;
   // Calculate the sum of first k elements
   for(i = 0; i < k; i++) {
      sum += arr[i];
   }
   maxSum = sum;
   // Calculate the sum of next k elements and check if it is greater than previous maximum sum
   for(i = k; i < n; i++) {
      sum += arr[i] - arr[i-k];
      maxSum = max(maxSum, sum);
   }
   // Return the maximum sum of contiguous subarray of size k
   return maxSum;
}

int main() {
   // Declare and initialize variables
   int n, k, i;
   printf("Enter the size of array: ");
   scanf("%d", &n);
   int arr[n];
   printf("Enter the elements of the array: ");
   for(i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
   printf("Enter the size of subarray: ");
   scanf("%d", &k);
   // Find the maximum sum of contiguous subarray of size k
   int maxSum = findMaxSum(arr, n, k);
   printf("Maximum sum of contiguous subarray of size %d is: %d\n", k, maxSum);
   return 0;
}