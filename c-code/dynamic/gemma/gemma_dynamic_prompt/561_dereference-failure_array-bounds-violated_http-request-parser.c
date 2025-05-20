#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char *url = "abc[1000]";
  char **headers = NULL;
  int num_headers = 0;

  // Allocate memory for headers
  headers = malloc(sizeof(char *) * 10);

  // Parse the URL and extract the headers
  char *header_start = strstr(url, ":");
  if (header_start)
  {
    char *header_name = header_start + 1;
    char *header_value = strchr(header_name, ";");

    // Iterate over the headers and store them
    while (header_name && header_value)
    {
      headers[num_headers++] = malloc(strlen(header_name) + strlen(header_value) + 1);
      strcpy(headers[num_headers - 1], header_name);
      strcpy(headers[num_headers - 1] + strlen(header_name) + 1, header_value);
      header_name = header_value + 1;
      header_value = strchr(header_name, ";");
    }
  }

  // Print the headers
  for (int i = 0; i < num_headers; i++)
  {
    printf("%s: %s\n", headers[i], headers[i + 1]);
  }

  // Free the memory allocated for headers
  for (int i = 0; i < num_headers; i++)
  {
    free(headers[i]);
  }
  free(headers);

  return 0;
}
