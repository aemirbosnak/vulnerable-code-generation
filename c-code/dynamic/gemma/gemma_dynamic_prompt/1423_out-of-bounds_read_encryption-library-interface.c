#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *key = "SECRET KEY";
  char *message = "HELLO WORLD!";

  int key_length = strlen(key);
  int message_length = strlen(message);

  int out_of_bounds_index = key_length + message_length;

  // Write beyond the bounds of the key and message arrays
  key[out_of_bounds_index] = 'A';
  message[out_of_bounds_index] = 'B';

  printf("Encrypeted message: %s", message);

  return 0;
}
