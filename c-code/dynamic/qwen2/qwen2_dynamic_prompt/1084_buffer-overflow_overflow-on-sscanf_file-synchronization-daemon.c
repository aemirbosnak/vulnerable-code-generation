#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 10

void process_command(const char *command) {
    char buffer[MAX_BUFFER_SIZE];
    if (sscanf(command, "%s", buffer) == 1) {
        printf("Processed command: %s\n", buffer);
    }
}

int main() {
    const char *malicious_input = "A very long string that will cause a buffer overflow";
    process_command(malicious_input);
    return 0;
}
