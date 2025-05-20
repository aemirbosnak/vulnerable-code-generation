#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(char* data, int size) {
    char buffer[10];
    memcpy(buffer, data + size, 20); // Out of bounds read vulnerability
}

int main() {
    char dbData[] = "Sample database data";
    migrateDatabase(dbData, sizeof(dbData));
    return 0;
}
