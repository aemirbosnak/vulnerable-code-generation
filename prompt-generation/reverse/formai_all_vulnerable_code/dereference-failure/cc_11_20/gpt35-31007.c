//FormAI DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
   int *ptr1, *ptr2, *ptr3, *ptr4;

   // allocate memory for ptr1
   ptr1 = (int*) malloc(5 * sizeof(int));

   if (ptr1 == NULL) {
      printf("Memory Allocation Error!");
      exit(0);
   }

   // allocate memory for ptr2
   ptr2 = (int*) malloc(3 * sizeof(int));

   if (ptr2 == NULL) {
      printf("Memory Allocation Error!");
      exit(0);
   }

   // allocate memory for ptr3
   ptr3 = (int*) calloc(2, sizeof(int));

   if (ptr3 == NULL) {
      printf("Memory Allocation Error!");
      exit(0);
   }

   // reallocating memory for ptr2
   ptr2 = (int*) realloc(ptr2, 5 * sizeof(int));

   if (ptr2 == NULL) {
      printf("Memory Allocation Error!");
      exit(0);
   }

   // set values for ptr1
   for (int i = 0; i < 5; i++) {
      ptr1[i] = i;
   }

   // set values for ptr2
   for (int i = 0; i < 5; i++) {
      ptr2[i] = i * i;
   }

   // set values for ptr3
   ptr3[0] = 10;
   ptr3[1] = 20;

   // allocate memory for ptr4
   ptr4 = (int*) malloc(3 * sizeof(int));

   if (ptr4 == NULL) {
      printf("Memory Allocation Error!");
      exit(0);
   }

   // set values for ptr4
   for (int i = 0; i < 3; i++) {
      ptr4[i] = i * i * i;
   }

   // print values for ptr1
   printf("Values for ptr1: ");
   for (int i = 0; i < 5; i++) {
      printf("%d ", ptr1[i]);
   }

   printf("\n");

   // print values for ptr2
   printf("Values for ptr2: ");
   for (int i = 0; i < 5; i++) {
      printf("%d ", ptr2[i]);
   }

   printf("\n");

   // print values for ptr3
   printf("Values for ptr3: ");
   for (int i = 0; i < 2; i++) {
      printf("%d ", ptr3[i]);
   }

   printf("\n");

   // print values for ptr4
   printf("Values for ptr4: ");
   for (int i = 0; i < 3; i++) {
      printf("%d ", ptr4[i]);
   }

   printf("\n");

   // free memory for ptr1
   free(ptr1);

   // free memory for ptr2
   free(ptr2);

   // free memory for ptr3
   free(ptr3);

   // free memory for ptr4
   free(ptr4);

   return 0;
}