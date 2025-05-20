#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(const char* input) {
    char source[10];
    char destination[20];

    // Vulnerable sscanf call
    if (sscanf(input, "%s %s", source, destination) != 2) {
        fprintf(stderr, "Invalid input format\n");
        return;
    }

    printf("Migrating data from %s to %s\n", source, destination);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return 1;
    }

    migrateDatabase(argv[1]);

    return 0;
}
