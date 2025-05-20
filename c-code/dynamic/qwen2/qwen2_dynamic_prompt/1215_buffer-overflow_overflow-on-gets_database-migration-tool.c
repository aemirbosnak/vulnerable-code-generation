#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 10

void migrate_data(char *source, char *destination) {
    printf("Migrating data from %s to %s\n", source, destination);
    char buffer[MAX_BUFFER_SIZE];
    gets(buffer); // Vulnerable to buffer overflow
    printf("Data migrated: %s\n", buffer);
}

int main() {
    char source[20] = "Source Database";
    char destination[20] = "Destination Database";

    migrate_data(source, destination);

    return 0;
}
