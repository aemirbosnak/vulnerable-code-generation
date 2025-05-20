//FormAI DATASET v1.0 Category: Data mining ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// function to find the mean of the given array
float mean(float *arr, int size) {
   float sum = 0, avg;
   for(int i = 0; i < size; i++) {
      sum += arr[i];
   }
   avg = sum / size;
   return avg;
}

// function to find the standard deviation of the given array
float standard_deviation(float *arr, int size, float mean) {
   float sum = 0, sd;
   for(int i = 0; i < size; i++) {
      sum += (arr[i] - mean) * (arr[i] - mean);
   }
   sd = sqrt(sum / size);
   return sd;
}

int main() {
   int choice, size, i;
   float arr[MAX], avg, sd;

   printf("Data Mining Program\n");
   printf("-------------------\n");

   // menu to choose the operation
   while(1) {
      printf("\nChoose the operation you want to perform:\n");
      printf("1. Calculate mean\n");
      printf("2. Calculate standard deviation\n");
      printf("3. Exit\n");
      printf("\nEnter your choice (1-3): ");
      scanf("%d", &choice);

      switch(choice) {
         case 1: // Calculate mean
            printf("\nEnter the number of elements in the array: ");
            scanf("%d", &size);

            if(size > MAX) {
               printf("\nMaximum number of elements allowed is %d. Please try again.\n", MAX);
               break;
            }

            printf("\nEnter the elements:\n");
            for(i = 0; i < size; i++) {
               scanf("%f", &arr[i]);
            }

            avg = mean(arr, size);

            printf("\nThe mean of the given array is: %f", avg);
            break;

         case 2: // Calculate standard deviation
            printf("\nEnter the number of elements in the array: ");
            scanf("%d", &size);

            if(size > MAX) {
               printf("\nMaximum number of elements allowed is %d. Please try again.\n", MAX);
               break;
            }

            printf("\nEnter the elements:\n");
            for(i = 0; i < size; i++) {
               scanf("%f", &arr[i]);
            }

            avg = mean(arr, size);
            sd = standard_deviation(arr, size, avg);

            printf("\nThe standard deviation of the given array is: %f", sd);
            break;

         case 3: // Exit
            printf("\nExiting the program.\n");
            exit(0);

         default: // Invalid choice
            printf("\nInvalid choice. Please try again.\n");
      }
   }

   return 0;
}