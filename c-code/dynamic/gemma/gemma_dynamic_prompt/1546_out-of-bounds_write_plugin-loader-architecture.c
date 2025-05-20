#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *plugin_loader(char *plugin_name)
{
  void **plugin_ptr = NULL;
  FILE *fp = fopen(plugin_name, "r");
  if (fp)
  {
    plugin_ptr = (void **)malloc(1024);
    fread(plugin_ptr, 1024, 1, fp);
    fclose(fp);
  }
  return plugin_ptr;
}

int main()
{
  char *plugin_name = "vulnerable_plugin.so";
  void *plugin = plugin_loader(plugin_name);
  if (plugin)
  {
    *(int *)plugin = 42;
    free(plugin);
  }
  return 0;
}
