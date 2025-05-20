//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>

#define MAX 100

void print_Array(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int main() {
  int i, j, size, temp, sum = 0, array[MAX];

  printf("Enter the size of the array: ");
  scanf("%d", &size);

  printf("Enter the elements of the array: ");
  for (i = 0; i < size; i++)
    scanf("%d", &array[i]);

  printf("\nOriginal Array: ");
  print_Array(array, size);

  //SORTING THE ARRAY IN DESCENDING ORDER
  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
      if (array[i] < array[j]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }

  printf("\nSorted (Descending) Array: ");
  print_Array(array, size);

  //COMPUTING THE SUM OF THE ARRAY ELEMENTS
  for (i = 0; i < size; i++) {
    sum += array[i];
  }

  //GREEDILY SELECTING THE LARGEST POSSIBLE SUBSET OF THE ARRAY
  int sub_set = 0, counter = 0;
  for (i = 0; i < size; i++) {
    sub_set += array[i];
    counter++;
    if (sub_set > (sum / 2)) {
      break;
    }
  }

  printf("\nLargest possible subset: ");
  for (i = 0; i < counter; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");
  return 0;
}