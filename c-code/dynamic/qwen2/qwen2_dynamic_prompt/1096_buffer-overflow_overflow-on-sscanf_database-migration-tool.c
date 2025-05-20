#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(const char* input) {
    char source[10];
    char destination[20];

    // Vulnerable line: buffer overflow due to insufficient space in 'source'
    sscanf(input, "%s %s", source, destination);

    printf("Migrating data from %s to %s\n", source, destination);
}

int main() {
    const char* maliciousInput = "verylongstringthatwillcausebufferoverflow verylongdestination";

    migrateDatabase(maliciousInput);

    return 0;
}
