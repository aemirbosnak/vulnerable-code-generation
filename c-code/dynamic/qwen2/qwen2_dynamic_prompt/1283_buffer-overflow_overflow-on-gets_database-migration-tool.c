#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void migrate_data(char *source, char *destination) {
    char buffer[BUFFER_SIZE];
    printf("Migrating data from %s to %s\n", source, destination);
    gets(buffer); // Vulnerable to buffer overflow
    printf("Data migrated: %s\n", buffer);
}

int main() {
    char source[20] = "Source Database";
    char destination[20] = "Destination Database";
    migrate_data(source, destination);
    return 0;
}
