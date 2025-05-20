#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int req_len = 0;
  char* req_buf = NULL;

  // Allocate memory for the request buffer
  req_buf = malloc(1024);

  // Read the request length from the header
  scanf("Enter the request length: ", &req_len);

  // Allocate memory for the request buffer based on the length
  req_buf = realloc(req_buf, req_len + 1);

  // Read the request data from the input
  scanf("Enter the request data: ", req_buf);

  // Calculate the overflowed integer
  int overflow_int = req_len * 2 + 1;

  // Print the overflowed integer
  printf("The overflowed integer is: %d\n", overflow_int);

  // Free the memory allocated for the request buffer
  free(req_buf);

  return 0;
}
