#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(const char* input) {
    char source[10];
    char destination[20];

    printf("Migrating database from: ");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = '\0';

    printf("Migrating to: ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = '\0';

    // Vulnerability: Buffer overflow in sscanf
    int result = sscanf(input, "%s %s", source, destination);

    if (result != 2) {
        fprintf(stderr, "Invalid input format\n");
        return;
    }

    printf("Migration successful from %s to %s\n", source, destination);
}

int main() {
    const char* input = "source_path destination_path";
    migrateDatabase(input);
    return 0;
}
