//FormAI DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main(){
  
  printf("Welcome to Brave Memory Management Program!\n");

  // allocating memory using malloc
  int *pointer = (int*)malloc(5 * sizeof(int));
  
  if(pointer == NULL){
    printf("Memory allocation failed! Exiting program...\n");
    exit(0);
  }

  printf("Memory allocation successful! Enter 5 integers:\n");

  // taking input from user for integers
  for(int i = 0; i < 5; i++){
    scanf("%d", &pointer[i]);
  }

  printf("Entered integers are: ");

  // printing entered integers
  for(int i = 0; i < 5; i++){
    printf("%d ", pointer[i]);
  }

  printf("\n");

  // reallocating memory using realloc
  pointer = (int*)realloc(pointer, 7 * sizeof(int));

  if(pointer == NULL){
    printf("Memory reallocation failed! Exiting program...\n");
    exit(0);
  }

  printf("Memory reallocation successful! Enter 2 more integers:\n");

  // taking input from user for extra integers
  for(int i = 5; i < 7; i++){
    scanf("%d", &pointer[i]);
  }

  printf("Entered integers (including extra integers) are: ");

  // printing entered integers (including extra integers)
  for(int i = 0; i < 7; i++){
    printf("%d ", pointer[i]);
  }

  printf("\n");

  // freeing allocated memory
  free(pointer);

  printf("Memory freed successfully!\n");

  return 0;
}