#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char* plugin_data = (char*)malloc(1024);
  plugin_data[1023] = 0xDEADBEEF;
  printf("%x", plugin_data[1023]);
  free(plugin_data);
  return 0;
}
