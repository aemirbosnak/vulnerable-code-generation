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
}

int main() {
    char largeData[20] = "This is a very large string that will cause an out-of-bounds write.";
    migrateDatabase(largeData);
    return 0;
}
