#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void *loadPlugin(char *name) {
  // Allocate memory for the plugin module
  void *plugin = malloc(1024);

  // Access an array element beyond the bounds of the allocated memory
  (*(int *)plugin) = 10;

  return plugin;
}

int main() {
  loadPlugin("foo.so");

  return 0;
}
