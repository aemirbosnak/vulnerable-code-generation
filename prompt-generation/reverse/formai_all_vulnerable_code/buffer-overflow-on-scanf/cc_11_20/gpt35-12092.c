//FormAI DATASET v1.0 Category: Data mining ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

int main() {
   int i, j, m, n, size;
   int *array;
   int *frequencies;

   printf("Enter the size of the array: ");
   scanf("%d", &size);

   // Allocate memory for dynamic array
   array = (int*) malloc(size * sizeof(int));

   // Take input array elements
   printf("Enter array elements: ");
   for(i=0;i<size;i++){
       scanf("%d", &array[i]);
   }

   // Get unique elements from array
   int *unique_elements;
   unique_elements = (int*) malloc(size * sizeof(int));
   int unique_count = 0;
   for(i=0;i<size;i++){
       for(j=0;j<unique_count;j++){
           if(array[i]==unique_elements[j]){
               break;
           }
       }
       if(j==unique_count){
           unique_elements[unique_count] = array[i];
           unique_count++;
       }
   }

   // Allocate memory for frequency array
   frequencies = (int*) malloc(unique_count * sizeof(int));
   for(i=0;i<unique_count;i++){
       frequencies[i] = 0;
   }

   // Count frequency of each unique element
   for(i=0;i<size;i++){
       for(j=0;j<unique_count;j++){
           if(array[i]==unique_elements[j]){
               frequencies[j]++;
               break;
           }
       }
   }

   // Print frequency of each unique element
   printf("Frequency of each unique element:\n");
   for(i=0;i<unique_count;i++){
       printf("%d: %d\n", unique_elements[i], frequencies[i]);
   }

   free(array);
   free(unique_elements);
   free(frequencies);
   
   return 0;
}