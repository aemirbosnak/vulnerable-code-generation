#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGINS 10

typedef struct {
    void (*init)();
    void (*run)();
} Plugin;

Plugin plugins[MAX_PLUGINS];
int plugin_count = 0;

void load_plugin(void* plugin_data) {
    if (plugin_count >= MAX_PLUGINS) return;
    plugins[plugin_count].init = ((Plugin*)plugin_data)->init;
    plugins[plugin_count].run = ((Plugin*)plugin_data)->run;
    plugin_count++;
}

void run_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        plugins[i].init();
        plugins[i].run();
    }
}

void malicious_init() {
    printf("Malicious init function called\n");
}

void malicious_run() {
    printf("Malicious run function called\n");
}

int main() {
    // Create a buffer to hold the malicious plugin data
    char buffer[sizeof(Plugin)];
    
    // Overwrite the function pointers with malicious ones
    ((Plugin*)buffer)->init = malicious_init;
    ((Plugin*)buffer)->run = malicious_run;
    
    // Load the malicious plugin
    load_plugin(buffer);
    
    // Run all plugins
    run_plugins();
    
    return 0;
}
