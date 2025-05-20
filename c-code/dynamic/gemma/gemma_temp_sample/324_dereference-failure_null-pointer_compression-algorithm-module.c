#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr = NULL;
  int value = 0;

  printf("Enter a value: ");
  scanf("%d", &value);

  // Deliberate null pointer dereference
  ptr = (char *)malloc(value);
  if (ptr == NULL) {
    printf("Error allocating memory.\n");
    return 1;
  }

  // This line will cause a null pointer dereference
  *(ptr + value) = value;

  free(ptr);
  return 0;
}
