#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void migrate_data() {
    char source[BUFFER_SIZE];
    char destination[2 * BUFFER_SIZE];

    printf("Enter data to migrate: ");
    fscanf(stdin, "%s", source);

    // Intentional buffer overflow vulnerability
    strcpy(destination, source);

    printf("Data migrated successfully.\n");
}

int main() {
    migrate_data();
    return 0;
}
