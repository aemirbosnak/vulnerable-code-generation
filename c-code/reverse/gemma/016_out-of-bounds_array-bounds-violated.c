#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void vuln_func(char *input) {
  int arr[10] = { 0 };
  int i = 0;

  for (; i < 10 && input[i] != '\0'; i++) {
    arr[i] = input[i];
  }

  printf("Content of the array: ");
  for (i = 0; i < 10; i++) {
    printf("%c ", arr[i]);
  }
  printf("\n");
}

int main() {
  char input[1024] = "";

  printf("Enter a command: ");
  fgets(input, 1024, stdin);

  vuln_func(input);

  return 0;
}
