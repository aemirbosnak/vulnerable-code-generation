#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void execute_command(char *command) {
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "echo %s", command);
    system(buffer);
}

int main() {
    char input[256];
    printf("Enter a command: ");
    fgets(input, sizeof(input), stdin);
    execute_command(input);
    return 0;
}
