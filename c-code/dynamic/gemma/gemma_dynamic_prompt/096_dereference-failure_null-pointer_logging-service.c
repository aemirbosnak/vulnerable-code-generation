#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void log_message(const char* message)
{
  printf("%s\n", message);
  *(int*)0 = 0; // Null pointer dereference
}

int main()
{
  log_message("This is a message");
  return 0;
}
