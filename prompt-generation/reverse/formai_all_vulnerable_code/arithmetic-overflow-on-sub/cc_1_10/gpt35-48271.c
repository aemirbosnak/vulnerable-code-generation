//FormAI DATASET v1.0 Category: Sorting ; Style: careful
#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int n); 
void selectionSort(int arr[], int n); 
void insertionSort(int arr[], int n); 

int main()
{
   int n, i;
   
   printf("Enter the number of elements in the array: ");
   scanf("%d",&n);
   
   int arr[n];
   
   printf("Enter the elements of the array:\n");
   
   for(i = 0; i < n; i++)
      scanf("%d",&arr[i]);
   
   printf("\n\nOriginal Array:\n");
   
   for(i = 0; i < n; i++)
      printf("%d ",arr[i]);
   
   bubbleSort(arr, n);
   
   printf("\nBubble Sorted Array:\n");
   
   for(i = 0; i < n; i++)
      printf("%d ",arr[i]);
   
   printf("\n\nOriginal Array:\n");
   
   for(i = 0; i < n; i++)
      printf("%d ",arr[i]);
   
   selectionSort(arr, n);
   
   printf("\nSelection Sorted Array:\n");
   
   for(i = 0; i < n; i++)
      printf("%d ",arr[i]);
   
   printf("\n\nOriginal Array:\n");
   
   for(i = 0; i < n; i++)
      printf("%d ",arr[i]);
   
   insertionSort(arr, n);
   
   printf("\nInsertion Sorted Array:\n");
   
   for(i = 0; i < n; i++)
      printf("%d ",arr[i]);
   
   printf("\n");
   
   return 0;
}

void bubbleSort(int arr[], int n)
{
   int i, j, temp;
   
   for(i = 0; i < n-1; i++)
   {
      for(j = 0; j < n-i-1; j++)
      {
         if(arr[j] > arr[j+1])
         {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}

void selectionSort(int arr[], int n)
{
   int i, j, min, temp;
   
   for(i = 0; i < n-1; i++)
   {
      min = i;
      
      for(j = i+1; j < n; j++)
      {
         if(arr[j] < arr[min])
         {
            min = j;
         }
      }
      
      temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
   }   
}

void insertionSort(int arr[], int n)
{
   int i, j, key;
   
   for(i = 1; i < n; i++)
   {
      key = arr[i];
      j = i-1;
      
      while(j >= 0 && arr[j] > key)
      {
         arr[j+1] = arr[j];
         j--;
      }
      
      arr[j+1] = key;
   }
}