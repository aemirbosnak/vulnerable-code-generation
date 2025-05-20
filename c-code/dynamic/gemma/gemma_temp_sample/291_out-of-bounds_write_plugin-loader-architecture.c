#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  void *plugin_ptr = (void *)0x12345;
  (*(int *)plugin_ptr) = 42;
  return 0;
}
