#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void (*plugin_function)();
} Plugin;

void load_plugin(Plugin *plugin) {
    if (plugin == NULL) {
        printf("Error: Plugin is NULL\n");
        return;
    }
    plugin->plugin_function();
}

int main() {
    Plugin my_plugin = {NULL};
    load_plugin(&my_plugin);
    return 0;
}
