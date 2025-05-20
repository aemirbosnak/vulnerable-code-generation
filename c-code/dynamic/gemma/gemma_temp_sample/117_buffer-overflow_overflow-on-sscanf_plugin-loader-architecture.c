#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void loadPlugin(char* pluginName) {
  FILE* pluginFile = fopen(pluginName, "r");
  if (pluginFile == NULL) {
    return;
  }

  char buffer[1024];
  fscanf(pluginFile, "%s", buffer);
  fclose(pluginFile);

  // Execute plugin code
  system(buffer);
}

int main() {
  loadPlugin("myplugin.txt");
  return 0;
}
