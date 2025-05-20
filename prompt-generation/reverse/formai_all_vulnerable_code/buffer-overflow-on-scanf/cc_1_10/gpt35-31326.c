//FormAI DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
   while (l <= r) {
      int mid = l + (r - l) / 2;
      
      // Check if x is present at mid
      if (arr[mid] == x) return mid;
      
      // If x is greater, ignore left half
      if (arr[mid] < x) l = mid + 1;
      
      // If x is smaller, ignore right half
      else r = mid - 1;
   }
   
   // Element is not present in array
   return -1;
}

// Function to perform linear search
int linearSearch(int arr[], int size, int x) {
   for (int i = 0; i < size; i++) {
      if (arr[i] == x) return i;
   }
   
   // Element is not present in array
   return -1;
}

// Main function
int main() {
   int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
   int size = sizeof(arr) / sizeof(arr[0]);
   
   int x = 50;   // Element to search
   int choice;   // User's choice for search algorithm
   
   printf("Enter the desired search algorithm:\n");
   printf("1. Binary search\n");
   printf("2. Linear search\n");
   printf("> ");
   scanf("%d", &choice);
   
   int index = -1;   // Index of element to be searched
   
   switch (choice) {
      case 1:
         // Perform binary search
         index = binarySearch(arr, 0, size - 1, x);
         break;
      case 2:
         // Perform linear search
         index = linearSearch(arr, size, x);
         break;
      default:
         printf("Invalid choice!\n");
         break;
   }
   
   if (index == -1) printf("Element not found!\n");
   else printf("Element found at index %d\n", index);
   
   return 0;
}