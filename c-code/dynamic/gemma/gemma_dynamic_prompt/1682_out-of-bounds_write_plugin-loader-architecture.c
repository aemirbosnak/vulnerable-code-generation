#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* plugin_name) {
  void* plugin = NULL;

  // Out-of-bounds write vulnerability
  *(int*)plugin = 0xdeadbeef;

  return plugin;
}

int main() {
  plugin_loader("foo.plugin");

  return 0;
}
