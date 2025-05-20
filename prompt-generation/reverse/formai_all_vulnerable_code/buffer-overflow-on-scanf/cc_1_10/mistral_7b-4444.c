//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void swap(int *a, int *b) {
 int temp;
 temp = *a;
 *a = *b;
 *b = temp;
}

void happyBubbleSort(int arr[], int n) {
 int i, j, flag;
 for (i = 0; i < n - 1; i++) {
 for (j = 0; j < n - i - 1; j++) {
 if (arr[j] > arr[j + 1]) {
 swap(&arr[j], &arr[j + 1]);
 printf("\033[1;32mSwapped arr[%d] and arr[%d]\n", j, j + 1);
 }
 flag = 1;
 for (int k = 0; k < n - i - 1; k++) {
 if (arr[k] > arr[k + 1]) {
 flag = 0;
 break;
 }
 }
 if (flag) {
 printf("\033[1;32mNo swaps in this pass, arr[] is sorted.\n");
 break;
 }
 }
 }
}

int main() {
 int arr[MAX], n, i;
 printf("\033[1;31mHappy Sorting Program\n");
 printf("Enter number of elements: ");
 scanf("%d", &n);
 printf("Enter %d elements: ", n);
 for (i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 happyBubbleSort(arr, n);
 printf("\033[1;32mSorted array: \n");
 for (i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 return 0;
}