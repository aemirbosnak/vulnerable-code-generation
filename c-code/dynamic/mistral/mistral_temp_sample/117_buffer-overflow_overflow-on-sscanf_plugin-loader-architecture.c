#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[256];
    void (*func)();
} Plugin;

Plugin plugins[10];
int num_plugins = 0;

void load_plugin(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    Plugin p;
    fscanf(fp, "%s", p.name);
    fscanf(fp, " %*s %p\n", &p.func);
    plugins[num_plugins++] = p;
    fclose(fp);
}

void run_plugins() {
    for (int i = 0; i < num_plugins; ++i) {
        printf("%s\n", plugins[i].name);
        (plugins[i].func)();
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <plugin_file>\n", argv[0]);
        return 1;
    }

    load_plugin(argv[1]);

    // Maliciously large input to overflow the buffer
    load_plugin("bad_plugin.txt");
    load_plugin("bad_plugin.txt");
    load_plugin("bad_plugin.txt");
    load_plugin("bad_plugin.txt");
    load_plugin("bad_plugin.txt");

    run_plugins();

    return 0;
}

// Example plugin function
void example_plugin() {
    char buffer[16];
    printf("Executing example plugin...\n");
    sscanf("This is an example plugin!", "%s", buffer);
    printf("Buffer contents: %s\n", buffer);
}
