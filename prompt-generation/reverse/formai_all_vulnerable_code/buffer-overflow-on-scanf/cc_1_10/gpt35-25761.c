//FormAI DATASET v1.0 Category: Browser Plugin ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Plugin {
  char name[100];
  int version;
  int (*function)(int);
};

int plugin1_func(int num) {
  return num * 2;
}

int plugin2_func(int num) {
  return num / 2;
}

void load_plugin(struct Plugin *plugin) {
  char name[100];
  int version;
  printf("Enter plugin name:\n");
  scanf("%s", name);
  printf("Enter plugin version:\n");
  scanf("%d", &version);
  strcpy(plugin->name, name);
  plugin->version = version;
  if (strcmp(name, "plugin1") == 0) {
    plugin->function = &plugin1_func;
  } else if (strcmp(name, "plugin2") == 0) {
    plugin->function = &plugin2_func;
  } else {
    printf("Unknown plugin!\n");
    exit(1);
  }
}

int main() {
  int num, result;
  struct Plugin plugins[10];
  int num_plugins = 0;

  // Load plugins
  while (num_plugins < 10) {
    char choice;
    printf("Do you want to load a plugin? (y/n)\n");
    scanf(" %c", &choice);
    if (choice == 'n') {
      break;
    }
    load_plugin(&plugins[num_plugins]);
    num_plugins++;
  }

  // Use plugins
  printf("Enter a number:\n");
  scanf("%d", &num);
  for (int i = 0; i < num_plugins; i++) {
    result = plugins[i].function(num);
    printf("%s v%d: %d\n", plugins[i].name, plugins[i].version, result);
  }

  return 0;
}