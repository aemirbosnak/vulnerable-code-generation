#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE* file_ptr = NULL;
  char* filename = "/etc/passwd";
  int offset = 0xdeadbeef;

  file_ptr = fopen(filename, "r");
  if (file_ptr == NULL)
  {
    perror("Error opening file");
    exit(1);
  }

  fseek(file_ptr, offset, SEEK_SET);
  char data = fgetc(file_ptr);
  fclose(file_ptr);

  printf("Data at offset 0xdeadbeef: %c", data);

  return 0;
}
