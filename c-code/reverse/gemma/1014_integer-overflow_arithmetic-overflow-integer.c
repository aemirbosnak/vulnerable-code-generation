#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int n, i, sum = 0;
  scanf("Enter the number of elements: ", &n);
  int arr[n];
  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n; i++) {
    sum += arr[i];
  }
  printf("The sum of the elements is: %d", sum);
  return 0;
}
