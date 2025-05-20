#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[100];
    void (*func)();
    struct Plugin *next;
} Plugin;

Plugin *head = NULL;

void load_plugin(Plugin *new) {
    new->next = head;
    head = new;
}

void run_plugins() {
    Plugin *current = head;

    while (current) {
        current->func();
        current = current->next;
    }
}

void plugin_func_A() {
    printf("Executing plugin function A\n");
}

void plugin_func_B() {
    printf("Executing plugin function B\n");
}

int main(int argc, char **argv) {
    Plugin plugin_A, plugin_B;

    strcpy(plugin_A.name, "Plugin A");
    plugin_A.func = plugin_func_A;

    strcpy(plugin_B.name, "Plugin B");
    plugin_B.func = plugin_func_B;

    load_plugin(&plugin_A);
    load_plugin(&plugin_B);

    printf("Enter the number of the plugin to execute (1 for A, 2 for B): ");

    Plugin temp;
    fscanf(stdin, "%s", temp.name);

    run_plugins(); // Vulnerable line with potential buffer overflow

    return 0;
}
