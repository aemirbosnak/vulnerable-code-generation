#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  char *url = "GET /hello?param=value";
  char *ptr = NULL;
  int length = strlen(url) + 1;
  ptr = malloc(length);
  strcpy(ptr, url);

  char *param = strstr(ptr, "?") + 1;
  char *value = strstr(param, "=");
  char *value_ptr = malloc(strlen(value) + 1);
  strcpy(value_ptr, value + 1);

  printf("Parameter: %s, Value: %s", param, value_ptr);

  free(ptr);
  free(value_ptr);
  return 0;
}
