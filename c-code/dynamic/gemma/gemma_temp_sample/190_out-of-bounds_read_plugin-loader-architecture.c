#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* plugin_path) {
  FILE* file = fopen(plugin_path, "r");
  if (file == NULL) {
    return NULL;
  }

  // Read the plugin code from the file
  char* plugin_code = malloc(1024);
  int read_size = fread(plugin_code, 1, 1024, file);
  fclose(file);

  // Create a new executable from the plugin code
  char* executable = "/tmp/plugin.exe";
  FILE* executable_file = fopen(executable, "w");
  fwrite(plugin_code, read_size, 1, executable_file);
  fclose(executable_file);

  // Run the plugin executable
  system(executable);

  return NULL;
}

int main() {
  plugin_loader("/path/to/plugin.so");
  return 0;
}
