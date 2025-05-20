//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to create random array of numbers
void generate_array(int array[], int size) {
   srand(time(NULL)); // Seed for random number generation
   for(int i=0; i<size; i++) {
      array[i] = rand() % 100 + 1; // Generates random numbers between 1 and 100
   }
}

// Function to print array of numbers
void print_array(int array[], int size) {
   for(int i=0; i<size; i++) {
      printf("%d ", array[i]); // Prints each element of the array separated by a space
   }
   printf("\n"); // Prints a new line character after the array is printed
}

// Function to sort the array of numbers using bubble sort algorithm
void bubble_sort(int array[], int size) {
   int temp; // Temporary variable to hold value during swap
   for(int i=0; i<size-1; i++) {
      for(int j=0; j<size-i-1; j++) {
         if(array[j] > array[j+1]) {
            // Swaps the values at position j and j+1 to put them in ascending order
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
         }
      }
   }
}

int main() {
   int size; // Variable to hold size of the array
   
   printf("How many numbers do you want to sort? ");
   scanf("%d", &size); // Takes input from the user for array size
   
   int array[size]; // Declares an array of size specified by the user
   
   generate_array(array, size); // Calls function to generate the array of random numbers
   
   printf("Before sorting: ");
   print_array(array, size); // Prints the unsorted array
   
   bubble_sort(array, size); // Calls function to sort the array using bubble sort algorithm
   
   printf("After sorting: ");
   print_array(array, size); // Prints the sorted array
   
   printf("Congratulations, you have successfully sorted %d numbers!\n", size); // Prints a message of accomplishment
   
   return 0;
}