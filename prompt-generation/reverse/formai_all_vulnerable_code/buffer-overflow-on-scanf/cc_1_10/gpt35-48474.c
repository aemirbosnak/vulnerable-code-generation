//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

int main(){
  
  int *ptr = NULL;
  int n, i;

  /* Asking user to enter the number of elements */
  printf("Enter number of elements: ");
  scanf("%d", &n);

  /* Memory allocation dynamically */
  ptr = (int*) malloc(n * sizeof(int));

  if(ptr == NULL){
    printf("Memory not allocated.\n");
    exit(0);
  }
  else{
    printf("Memory successfully allocated using malloc.\n");
  }

  /* Storing the elements entered by user */
  for(i=0; i<n; i++){
    printf("Enter element %d: ", i+1);
    scanf("%d", ptr+i);
  }

  /* Printing the elements entered by user */
  printf("The elements entered are: ");
  for(i=0; i<n; i++){
    printf("%d ", *(ptr+i));
  }

  /* Resizing the memory location */
  printf("\nResizing the memory location...\n");

  /* Asking user to enter new number of elements */
  printf("Enter the new number of elements: ");
  scanf("%d", &n);

  /* Re-allocating memory */
  ptr = realloc(ptr, n * sizeof(int));
  
  /* Storing new elements entered by user */
  for(i=0; i<n; i++){
    printf("Enter new element %d: ", i+1);
    scanf("%d", ptr+i);
  }

  /* Printing new elements entered by user */
  printf("New elements are: ");
  for(i=0; i<n; i++){
    printf("%d ", *(ptr+i));
  }

  /* Freeing up the memory */
  free(ptr);

  return 0;
}