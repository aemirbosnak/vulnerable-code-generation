#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase() {
    char source[10];
    char destination[20];

    printf("Enter source path: ");
    gets(source); // Vulnerable to buffer overflow

    printf("Enter destination path: ");
    gets(destination); // Vulnerable to buffer overflow

    printf("Migrating from %s to %s\n", source, destination);
}

int main() {
    migrateDatabase();
    return 0;
}
