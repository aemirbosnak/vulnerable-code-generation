//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: medieval
// In the realm of byte and bit, where logic's might doth wield,
// A tale of sorting unfolds, a quest for truth concealed.

#include <stdio.h>
#include <stdlib.h>

// A humble array, its elements a motley crew,
int arr[10] = {3, 6, 1, 7, 2, 9, 4, 8, 5, 0};

// The Bubble, a gentle breeze, sifts through the numbers' array,
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// The Selection, a keen-eyed hunter, picks the smallest from the throng,
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    int temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}

// The Insertion, a skilled weaver, slots each number in its place,
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// Now, let the knights of sorts display their valiant might,
int main() {
  int choice;
  printf("Hark! Choose thy sorting algorithm:\n");
  printf("1. Bubble (gentle breeze)\n");
  printf("2. Selection (keen-eyed hunter)\n");
  printf("3. Insertion (skilled weaver)\n");
  printf("Enter thy choice, brave traveler: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      bubbleSort(arr, 10);
      break;
    case 2:
      selectionSort(arr, 10);
      break;
    case 3:
      insertionSort(arr, 10);
      break;
    default:
      printf("Thy choice be foul! No sorting shall be done.\n");
      return 1;
  }

  // Behold, the numbers now march in perfect line,
  printf("The sorted array, a testament to thy wisdom:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}