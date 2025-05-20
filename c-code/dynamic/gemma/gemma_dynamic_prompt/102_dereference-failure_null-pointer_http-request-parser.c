#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char* url = NULL;
  char** headers = NULL;
  char* data = NULL;

  // Malformed pointer dereference
  headers = (char**)malloc(sizeof(char*) * 2);
  headers[0] = "Foo: Bar";
  headers[1] = NULL;
  url = "GET /foo";

  // Attempt to dereference a null pointer
  headers[2] = NULL;
  printf("%s\n", headers[2]);

  return 0;
}
