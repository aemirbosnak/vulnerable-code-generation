//FormAI DATASET v1.0 Category: Random ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
   int i, j, k, n;
   printf("Enter the size of the array:\n");
   scanf("%d", &n);
   
   int arr[n];
   srand(time(NULL));
   
   for(i=0; i<n; i++){
       arr[i] = rand()%100; //generating random number between 0 and 99
       printf("%d ", arr[i]);
   }
   printf("\n");
   
   //Sorting the array using bubble sort
   for(i=0; i<n-1; i++){
       for(j=0; j<n-i-1; j++){
           if(arr[j]>arr[j+1]){
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
       }
   }
   
   printf("The sorted array:\n");
   for(i=0; i<n; i++){
       printf("%d ", arr[i]);
   }
   printf("\n");
   
   //Printing the largest and smallest number from the array
   int largest = arr[0];
   int smallest = arr[0];
   
   for(i=0; i<n; i++){
       if(arr[i]>largest){
           largest = arr[i];
       }
       if(arr[i]<smallest){
           smallest = arr[i];
       }
   }
   
   printf("The largest number in the array is: %d\n", largest);
   printf("The smallest number in the array is: %d\n", smallest);
   
   //Reversing the array
   int tempArr[n];
   k=0;
   
   for(i=n-1; i>=0; i--){
       tempArr[k] = arr[i];
       k++;
   }
   
   printf("The reversed array:\n");
   for(i=0; i<n; i++){
       printf("%d ", tempArr[i]);
   }
   
   return 0;
}