#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **plugins = NULL;
  int plugin_count = 0;

  // Allocate memory for the plugin list
  plugins = malloc(10 * sizeof(char *));

  // Load the plugins
  plugins[plugin_count++] = "plugin1.so";
  plugins[plugin_count++] = "plugin2.so";
  plugins[plugin_count++] = "plugin3.so";

  // Execute the plugins
  for (int i = 0; i < plugin_count; i++) {
    FILE *fp = fopen(plugins[i], "r");
    if (fp) {
      char line[1024];
      while (fgets(line, 1024, fp) != NULL) {
        printf("%s", line);
      }
      fclose(fp);
    }
  }

  // Free the memory
  free(plugins);

  return 0;
}
