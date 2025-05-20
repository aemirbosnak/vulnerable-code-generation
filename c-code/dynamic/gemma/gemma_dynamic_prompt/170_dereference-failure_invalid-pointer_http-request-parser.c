#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *url = malloc(1024);
  scanf("%s", url);

  // Malformed pointer dereference
  void *ptr = (void *)url + 10;
  int value = *(int *)ptr;

  printf("Value: %d", value);

  free(url);
  return 0;
}
