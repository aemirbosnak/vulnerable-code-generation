#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE *file = fopen("/etc/passwd", "w");
  char buffer[1024] = "Hello, world!";
  size_t size = 1024;

  if (file)
  {
    write(fileno(file), buffer, size);
  }

  fclose(file);

  return 0;
}
