//FormAI DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include <stdio.h>

// function for linear search
int linear_search(int arr[], int size, int search) {
   for(int i=0; i<size; i++) {
      if(arr[i] == search)
         return i;
   }
   return -1;
}

// function for binary search
int binary_search(int arr[], int size, int search) {
   int low=0, high=size-1;
   while(low<=high) {
      int mid = (low+high)/2;
      if(arr[mid]==search)
         return mid;
      else if(arr[mid]<search)
         low = mid+1;
      else
         high = mid-1;
   }
   return -1;
}

int main() {
   int size, search, choice;
   printf("Enter size of array: ");
   scanf("%d", &size);
   int arr[size];
   printf("Enter %d elements in the array: ", size);
   for(int i=0; i<size; i++)
      scanf("%d", &arr[i]);
   printf("\nEnter the element to be searched: ");
   scanf("%d", &search);
   printf("\nChoose the search algorithm:\n");
   printf("1. Linear Search\n2. Binary Search\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);
   int index;
   if(choice==1)
      index = linear_search(arr, size, search);
   else if(choice==2)
      index = binary_search(arr, size, search);
   else {
      printf("Invalid choice.");
      return 0;
   }
   if(index == -1)
      printf("\n%d not found in the array.", search);
   else
      printf("\n%d found at index %d in the array.", search, index);
   return 0;
}