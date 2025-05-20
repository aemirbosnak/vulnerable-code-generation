#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *plugin_loader(char *plugin_name) {
  FILE *fp = fopen(plugin_name, "r");
  if (!fp) {
    return NULL;
  }

  char buffer[1024];
  fscanf(fp, "%s", buffer);
  fclose(fp);

  return (void *)buffer;
}

int main() {
  char *plugin_name = "test.txt";
  void *plugin_data = plugin_loader(plugin_name);

  if (plugin_data) {
    printf("%s", (char *)plugin_data);
  } else {
    printf("Error loading plugin");
  }

  return 0;
}
