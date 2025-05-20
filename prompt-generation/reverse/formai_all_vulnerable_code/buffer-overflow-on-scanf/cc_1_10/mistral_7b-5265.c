//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>

void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}

void selectionSort(int *arr, int n) {
 int i, j, min_idx;
 for (i = 0; i < n - 1; i++) {
 min_idx = i;
 for (j = i + 1; j < n; j++) {
 if (arr[min_idx] > arr[j]) {
 min_idx = j;
 }
 }
 swap(&arr[min_idx], &arr[i]);
 }
}

int main() {
 int fd, i, len, status;
 char filename[100], buffer[10];
 int *arr, n;
 printf("Enter file name: ");
 scanf("%s", filename);
 fd = open(filename, O_RDONLY);
 if (fd == -1) {
 perror("Error opening file");
 exit(EXIT_FAILURE);
 }
 fseek(fd, 0, SEEK_END);
 len = ftell(fd);
 fseek(fd, 0, SEEK_SET);
 arr = malloc(len);
 n = len / sizeof(int);
 for (i = 0; i < n; i++) {
 fscanf(fd, "%s", buffer);
 arr[i] = atoi(buffer);
 }
 close(fd);
 selectionSort(arr, n);
 printf("Sorted array: ");
 for (i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
 free(arr);
 return 0;
}