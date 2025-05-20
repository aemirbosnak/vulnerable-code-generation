#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *url = "abc";
  char **headers = NULL;
  headers = (char**)malloc(10 * sizeof(char*));
  headers[0] = "Content-Type: application/json";
  headers[1] = "Authorization: Basic YWRtaWdodGVhbmlk";
  headers[2] = "Accept: application/json";

  char **body = NULL;
  body = (char**)malloc(100 * sizeof(char));
  body[0] = '{"name": "John Doe"}';

  printf("URL: %s\n", url);
  printf("Headers:\n");
  for (int i = 0; headers[i] != NULL; i++) {
    printf("%s\n", headers[i]);
  }
  printf("Body:\n");
  printf("%s\n", body[0]);

  free(headers);
  free(body);
  return 0;
}
