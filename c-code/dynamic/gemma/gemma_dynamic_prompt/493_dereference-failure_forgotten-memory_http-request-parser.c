#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char *url = "example.com";
  char *request_line = "GET /foo HTTP/1.1";
  char **headers = NULL;
  char **cookies = NULL;

  // Parse the request line
  char *method = strtok(request_line, " ");
  char *path = strtok(request_line, " ") + 1;
  char *protocol = strtok(request_line, "/") + 1;

  // Allocate memory for headers and cookies
  headers = malloc(10);
  cookies = malloc(10);

  // Parse the headers
  char *header_key = NULL;
  char *header_value = NULL;
  while ((header_key = strtok(NULL, ":")) != NULL)
  {
    header_value = strtok(NULL, ";");
    headers[0] = header_key;
    headers[1] = header_value;
  }

  // Parse the cookies
  char *cookie_key = NULL;
  char *cookie_value = NULL;
  while ((cookie_key = strtok(NULL, ";")) != NULL)
  {
    cookie_value = strtok(NULL, ";");
    cookies[0] = cookie_key;
    cookies[1] = cookie_value;
  }

  // Print the parsed information
  printf("Method: %s\n", method);
  printf("Path: %s\n", path);
  printf("Protocol: %s\n", protocol);
  printf("Headers:\n");
  for (int i = 0; headers[i] != NULL; i++)
  {
    printf("%s: %s\n", headers[i], headers[i + 1]);
  }
  printf("Cookies:\n");
  for (int i = 0; cookies[i] != NULL; i++)
  {
    printf("%s: %s\n", cookies[i], cookies[i + 1]);
  }

  // Free the allocated memory
  free(headers);
  free(cookies);

  return 0;
}
