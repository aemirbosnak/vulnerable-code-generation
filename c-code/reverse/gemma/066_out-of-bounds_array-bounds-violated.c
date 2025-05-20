#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buffer[10];
  int server_response_size = 0;
  FILE *fp;

  fp = fopen("localhost:8080/vulnerable", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  server_response_size = fread(buffer, 1, 10, fp);
  fclose(fp);

  printf("Server response: %s", buffer);

  return 0;
}
