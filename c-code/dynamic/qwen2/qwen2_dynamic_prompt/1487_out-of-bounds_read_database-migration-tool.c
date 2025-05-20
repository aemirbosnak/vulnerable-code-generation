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
    destination[i] = '\0';
}

int main() {
    char source[BUFFER_SIZE] = "Hello, World!";
    char destination[5];

    migrate_data(source, destination);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
