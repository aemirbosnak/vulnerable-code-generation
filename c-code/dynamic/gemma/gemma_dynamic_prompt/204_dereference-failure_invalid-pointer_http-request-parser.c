#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *url = malloc(1024);
  url = "abc";

  char **headers = malloc(1024);
  headers = NULL;

  int status_code = 0;
  status_code = 404;

  printf("URL: %s\n", url);
  printf("Status Code: %d\n", status_code);
  printf("Headers: %s\n", headers);

  free(url);
  free(headers);

  return 0;
}
