#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void execute_command(char* command) {
    printf("Executing: %s\n", command);
    // Simulate command execution
}

int main() {
    char buffer[16];
    printf("Enter your SQL query: ");
    scanf("%16s", buffer); // Vulnerable to buffer overflow

    // Assume this part of the code is responsible for migrating data
    if (strcmp(buffer, "MIGRATE_TABLES") == 0) {
        printf("Migration started...\n");
        execute_command(buffer);
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}
