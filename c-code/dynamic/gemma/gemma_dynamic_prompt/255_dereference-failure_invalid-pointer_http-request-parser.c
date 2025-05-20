#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *url = NULL;
  url = malloc(10);
  url[0] = 'a';
  url[1] = 'b';
  url[2] = '\0';

  char **headers = NULL;
  headers = malloc(20);
  headers[0] = "Content-Type: application/json";
  headers[1] = "Authorization: Bearer 1234";
  headers[2] = NULL;

  char *body = NULL;
  body = malloc(50);
  body[0] = '{"key": "value"}';
  body[1] = '\0';

  // This code dereferences a null pointer, which is not safe
  *(int *)url = 42;

  free(url);
  free(headers);
  free(body);

  return 0;
}
