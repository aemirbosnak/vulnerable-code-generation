#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void migrate_data(char *source, char *destination) {
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        destination[i] = source[i];
    }
    // Out-of-bounds write
    destination[BUFFER_SIZE] = 'X';
}

int main() {
    char source[BUFFER_SIZE + 2] = "Hello";
    char destination[BUFFER_SIZE];

    printf("Source: %s\n", source);
    printf("Destination before migration: %s\n", destination);

    migrate_data(source, destination);

    printf("Destination after migration: %s\n", destination);

    return 0;
}
