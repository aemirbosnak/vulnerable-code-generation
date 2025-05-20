//FormAI DATASET v1.0 Category: Searching algorithm ; Style: happy
#include<stdio.h>
#include<stdlib.h>

int main()
{
  printf("Welcome everyone!\n");
  printf("Today, we are going to learn about searching algorithms!\n");
  printf("First, let's create an array of 10 happy numbers: \n");
  
  int arr[10] = {1, 3, 7, 9, 10, 13, 14, 17, 19, 20};
  int n = 10;
  
  printf("\nHere are the happy numbers in our array: \n");
  
  for(int i=0; i<n; i++)
  {
    printf("%d ", arr[i]);
  }
  
  printf("\n\nNow, let's search for a happy number in our array! \n");
  
  int happy_number;
  printf("\nEnter the happy number you want to search: ");
  scanf("%d", &happy_number);
  
  int low=0, high=n-1, mid;
  
  while(low<=high)
  {
    mid = (low+high)/2;
    
    if(arr[mid] == happy_number)
    {
      printf("\nHooray! We found the happy number at index %d! \n", mid);
      return 0;
    }
    else if(arr[mid]<happy_number)
    {
      low = mid+1;
    }
    else
    {
      high = mid-1;
    }
  }
  
  printf("\nOops! The happy number is not in our array. Better luck next time!\n");
  
  return 0;
}