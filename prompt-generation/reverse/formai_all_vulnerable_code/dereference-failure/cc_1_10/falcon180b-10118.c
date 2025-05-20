//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLUGINS 10
#define MAX_NAME_LEN 50
#define MAX_FILE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char file[MAX_FILE_LEN];
    int enabled;
} plugin_t;

plugin_t plugins[MAX_PLUGINS];
int num_plugins = 0;

void load_plugins() {
    FILE *f;
    char line[MAX_FILE_LEN];
    char *name, *file;

    f = fopen("plugins.txt", "r");
    if (f == NULL) {
        printf("Error loading plugins\n");
        exit(1);
    }

    while (fgets(line, MAX_FILE_LEN, f)!= NULL) {
        name = strtok(line, ",");
        file = strtok(NULL, ",");

        strcpy(plugins[num_plugins].name, name);
        strcpy(plugins[num_plugins].file, file);
        plugins[num_plugins].enabled = 1; // default is enabled

        num_plugins++;
    }

    fclose(f);
}

int main() {
    load_plugins();

    printf("Plugins loaded:\n");
    for (int i = 0; i < num_plugins; i++) {
        printf("%s (%s)\n", plugins[i].name, plugins[i].enabled? "Enabled" : "Disabled");
    }

    return 0;
}