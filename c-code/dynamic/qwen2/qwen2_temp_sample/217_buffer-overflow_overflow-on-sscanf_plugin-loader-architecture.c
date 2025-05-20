#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 10

void load_plugin(const char* plugin_name) {
    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "%s", plugin_name);
}

int main() {
    char input[256];
    printf("Enter plugin name: ");
    scanf("%249s", input); // Safe read up to 249 characters to leave room for null terminator
    load_plugin(input);
    return 0;
}
