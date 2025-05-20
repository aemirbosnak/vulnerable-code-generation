//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// The mind-bending part starts here...
#define BUCKETS 10
struct bucket {
   int min, max;
   int *data;
   int size;
};

void insert(struct bucket *b, int val) {
   if (b->size == 0) { b->min = val; b->max = val; }
   else { if (val < b->min) b->min = val; if (val > b->max) b->max = val; }
   b->data = realloc(b->data, sizeof(int) * ++b->size);
   b->data[b->size - 1] = val;
}

void sort(struct bucket *b) {
   for (int i = 0; i < b->size - 1; i++) {
      for (int j = 0; j < b->size - 1 - i; j++) {
         if (b->data[j] > b->data[j + 1]) {
            int tmp = b->data[j];
            b->data[j] = b->data[j + 1];
            b->data[j + 1] = tmp;
         }
      }
   }
}

int main() {
   int n, *arr;
   printf("Enter the size of the array: ");
   scanf("%d", &n);
   arr = malloc(sizeof(int) * n);
   printf("Enter the elements of the array: ");
   for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
   
   struct bucket buckets[BUCKETS];
   for (int i = 0; i < BUCKETS; i++) { buckets[i].size = 0; }
   
   for (int i = 0; i < n; i++) insert(&buckets[arr[i] % BUCKETS], arr[i]);
   
   for (int i = 0; i < BUCKETS; i++) sort(&buckets[i]);
   
   printf("Sorted array: ");
   for (int i = 0; i < BUCKETS; i++)
      for (int j = 0; j < buckets[i].size; j++)
         printf("%d ", buckets[i].data[j]);
   
   printf("\n");
   
   free(arr);
   for (int i = 0; i < BUCKETS; i++) free(buckets[i].data);
   
   return 0;
}