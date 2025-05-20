//FormAI DATASET v1.0 Category: Memory management ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

int main() {

  int *ptr, *q;
  int n, choice, i;

  printf("Enter the number of elements you want to allocate: ");
  scanf("%d", &n);

  ptr = (int*) malloc(n * sizeof(int)); // Allocating memory using malloc

  if(ptr == NULL) {
    printf("Memory allocation failed!");
    exit(0);
  }

  printf("Memory allocated successfully!");

  printf("\nEnter the values of the elements:");

  for(i=0; i<n; i++){
    scanf("%d", ptr+i);
  }

  printf("\nThe elements in the array are:");

  for(i=0; i<n; i++){
    printf("%d ", *(ptr+i));
  }

  printf("\nDo you want to reallocate the memory? Enter 1 for Yes, 0 for No:");
  scanf("%d", &choice);

  if(choice == 1){
    q = (int*) realloc(ptr, n*2*sizeof(int)); // Reallocating memory using realloc

    if(q == NULL) {
      printf("Memory reallocation failed!");
      exit(0);
    }

    ptr = q;

    printf("\nMemory reallocated successfully!");

    printf("\nEnter the new values of the additional elements:");

    for(i=n; i<2*n; i++){
      scanf("%d", ptr+i);
    }

    printf("\nThe new elements in the array are:");

    for(i=0; i<2*n; i++){
      printf("%d ", *(ptr+i));
    }
  }

  free(ptr); // Freeing memory using free

  printf("\nMemory freed successfully!");

  return 0;
}