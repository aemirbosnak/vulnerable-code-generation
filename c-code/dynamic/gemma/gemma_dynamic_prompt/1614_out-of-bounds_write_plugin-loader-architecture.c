#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void *plugin_loader(char *name)
{
  void **plugin = NULL;
  FILE *fp = fopen(name, "r");
  if (fp)
  {
    plugin = (void **)malloc(1024);
    fread(plugin, 1024, 1, fp);
    fclose(fp);
  }
  return plugin;
}

int main()
{
  void *plugin = plugin_loader("vulnerable.so");
  if (plugin)
  {
    (*(int *)plugin) = 42;
    free(plugin);
  }
  return 0;
}
