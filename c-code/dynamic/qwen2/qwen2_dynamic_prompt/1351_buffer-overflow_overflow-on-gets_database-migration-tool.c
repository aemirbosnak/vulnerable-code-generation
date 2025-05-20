#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void migrate_database() {
    char source[BUFFER_SIZE];
    char destination[BUFFER_SIZE];

    printf("Enter source database path: ");
    gets(source); // Vulnerable to buffer overflow

    printf("Enter destination database path: ");
    gets(destination); // Vulnerable to buffer overflow

    printf("Migrating from %s to %s\n", source, destination);
}

int main() {
    migrate_database();
    return 0;
}
