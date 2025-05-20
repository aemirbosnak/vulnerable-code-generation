//FormAI DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *a, *b, *c;

  //Using malloc to allocate memory of 10 integers
  a = (int *)malloc(10*sizeof(int));
  b = (int *)malloc(10*sizeof(int));
  c = (int *)malloc(10*sizeof(int));

  //Checking if malloc succeeded
  if (a == NULL || b == NULL || c == NULL) {
    printf("Malloc failed!");
    exit(1);
  } else {
    printf("Memory allocation successful!\n");
  }

  //Populating arrays
  for (int i = 0; i < 10; i++) {
    a[i] = i*2;
    b[i] = i*3;
    c[i] = i*4;
  }

  //Printing arrays
  printf("Array a: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  printf("Array b: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", b[i]);
  }
  printf("\n");

  printf("Array c: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", c[i]);
  }
  printf("\n");
  
  //Using realloc to increase size of array a
  a = (int *)realloc(a, 20*sizeof(int));
  
  //Checking if realloc succeeded
  if (a == NULL) {
    printf("Realloc failed!");
    exit(1);
  } else {
    printf("Reallocation successful!\n");
  }
  
  //Populating new elements of array a
  for (int i = 10; i < 20; i++) {
    a[i] = i*2;
  }
  
  printf("Array a after reallocation: ");
  for (int i = 0; i < 20; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  //Using free to release memory
  free(a);
  free(b);
  free(c);
  
  printf("Memory Freed successfully!\n");

  return 0;
}