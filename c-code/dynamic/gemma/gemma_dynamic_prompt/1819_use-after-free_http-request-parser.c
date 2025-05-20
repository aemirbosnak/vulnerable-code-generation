#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *url = malloc(1024);
  scanf("%s", url);

  char *method = malloc(64);
  scanf("%s", method);

  char *headers = malloc(2048);
  scanf("%s", headers);

  char *body = malloc(4096);
  scanf("%s", body);

  printf("URL: %s\n", url);
  printf("Method: %s\n", method);
  printf("Headers: %s\n", headers);
  printf("Body: %s\n", body);

  free(url);
  free(method);
  free(headers);
  free(body);

  return 0;
}
