#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *plugin_loader(int index) {
  return (void *)((int *)index)[0];
}

int main() {
  plugin_loader(10);
  return 0;
}
