#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(const char* input) {
    char source[10];
    char destination[20];

    // Simulate reading from an external file or user input
    if (sscanf(input, "%s %s", source, destination) != 2) {
        printf("Invalid input format.\n");
        return;
    }

    // Perform the migration logic
    printf("Migrating data from %s to %s\n", source, destination);
}

int main() {
    char userInput[100];

    printf("Enter source and destination databases: ");
    fgets(userInput, sizeof(userInput), stdin);

    // Remove newline character if present
    size_t len = strlen(userInput);
    if (len > 0 && userInput[len - 1] == '\n') {
        userInput[len - 1] = '\0';
    }

    migrateDatabase(userInput);

    return 0;
}
