//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Define the node structure for the buckets
typedef struct Node {
  int value;
  struct Node* next;
} Node;

// Function to insert a value into the linked list at the given bucket
void insert(Node** bucket, int value) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;

  Node* current = *bucket;
  if (current == NULL) {
    *bucket = new_node;
  }
  else {
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Function to sort the given array using Bucket Sort
void bucket_sort(int arr[], int n) {
  // Create an array of pointers to the bucket nodes
  Node* buckets[BUCKET_SIZE];
  for (int i = 0; i < BUCKET_SIZE; i++) {
    buckets[i] = NULL;
  }

  // Insert each element of the array into the appropriate bucket
  for (int i = 0; i < n; i++) {
    int bucket_index = arr[i] / BUCKET_SIZE;
    insert(&buckets[bucket_index], arr[i]);
  }

  // Sort the elements in each bucket
  for (int i = 0; i < BUCKET_SIZE; i++) {
    Node* current = buckets[i];
    while (current != NULL) {
      Node* inner_current = current->next;
      while (inner_current != NULL) {
        if (inner_current->value < current->value) {
          int temp = inner_current->value;
          inner_current->value = current->value;
          current->value = temp;
        }
        inner_current = inner_current->next;
      }
      current = current->next;
    }
  }

  // Copy the sorted values from the buckets back into the original array
  int index = 0;
  for (int i = 0; i < BUCKET_SIZE; i++) {
    Node* current = buckets[i];
    while (current != NULL) {
      arr[index++] = current->value;
      current = current->next;
    }
  }
}

// Driver Program
int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  bucket_sort(arr, n);
  printf("Sorted array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}