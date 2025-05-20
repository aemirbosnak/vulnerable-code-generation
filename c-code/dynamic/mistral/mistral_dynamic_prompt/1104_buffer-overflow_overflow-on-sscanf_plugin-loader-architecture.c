#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*func)();
} Plugin;

void load_plugin(Plugin *plugin, char *buffer) {
    sscanf(buffer, "%s", plugin->name);
    plugin->func();
}

void evil_plugin_func() {
    char buffer[16];
    setbuf(stdin, NULL);
    printf("Enter the evil command (max 15 chars): ");
    fgets(buffer, sizeof(buffer), stdin);
    setbuf(stdin, NULL);

    // Malicious code here...
}

int main() {
    Plugin plugins[10];
    char input[10][1024];

    int i;
    for (i = 0; i < 10; i++) {
        printf("Enter plugin path and function (example: plugin1.so evil_func)\n");
        fgets(input[i], sizeof(input[i]), stdin);
        sscanf(input[i], "plugin%d.so %s", &plugins[i].func, plugins[i].name);
    }

    for (i = 0; i < 10; i++) {
        load_plugin(&plugins[i], input[i]);
    }

    return 0;
}
