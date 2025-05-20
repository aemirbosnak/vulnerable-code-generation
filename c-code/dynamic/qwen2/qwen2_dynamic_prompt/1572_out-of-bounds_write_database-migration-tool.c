#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void migrate_data(char *source, char *destination) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, source);
    // Intentional out-of-bounds write vulnerability
    buffer[BUFFER_SIZE] = 'A'; // This will overwrite the null terminator
}

int main() {
    char source[] = "Sample data";
    char destination[20];

    printf("Source: %s\n", source);

    migrate_data(source, destination);

    printf("Destination: %s\n", destination);

    return 0;
}
