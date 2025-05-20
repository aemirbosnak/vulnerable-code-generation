#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void migrateDatabase(char* data) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, data);
    printf("Migrating data: %s\n", buffer);
}

int main() {
    char largeData[20] = "This is a very large string that will cause an out-of-bounds read.";
    migrateDatabase(largeData);
    return 0;
}
