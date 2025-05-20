#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
  char buffer[10];
  scanf("%s", buffer);

  // Overflow the buffer
  char overflow_data[] = "This is a long string that will cause a buffer overflow";
  int len = strlen(overflow_data) + 1;
  memcpy(buffer, overflow_data, len);

  printf("The modified buffer is: %s", buffer);

  return 0;
}
