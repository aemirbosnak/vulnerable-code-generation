//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
    #include <stdlib.h>

    int main() {
      // Dynamic Memory Allocation
      int* arr = (int*)malloc(5 * sizeof(int));
      arr[0] = 1;
      arr[1] = 2;
      arr[2] = 3;
      arr[3] = 4;
      arr[4] = 5;

      // Dynamic Memory Deallocation
      free(arr);

      // Using realloc() to resize the memory block
      arr = (int*)realloc(arr, 10 * sizeof(int));
      arr[5] = 6;
      arr[6] = 7;
      arr[7] = 8;
      arr[8] = 9;
      arr[9] = 10;

      // Print the array
      for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
      }
      printf("\n");

      // Using calloc() to allocate memory for an array of structs
      struct Data {
        int a;
        int b;
      };
      struct Data* data = (struct Data*)calloc(10, sizeof(struct Data));
      data[0].a = 1;
      data[0].b = 2;
      data[1].a = 3;
      data[1].b = 4;

      // Print the array of structs
      for (int i = 0; i < 10; i++) {
        printf("{%d, %d} ", data[i].a, data[i].b);
      }
      printf("\n");

      // Using free() to deallocate memory
      free(data);

      return 0;
    }