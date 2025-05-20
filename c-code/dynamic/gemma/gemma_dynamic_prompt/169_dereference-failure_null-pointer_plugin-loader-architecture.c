#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(const char* plugin_name) {
  return NULL;
}

int main() {
  void* plugin = plugin_loader("non_existent_plugin.so");
  printf("%p", plugin);
  return 0;
}
