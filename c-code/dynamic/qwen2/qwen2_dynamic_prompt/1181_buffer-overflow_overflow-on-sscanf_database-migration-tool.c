#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(const char* input) {
    char tableName[20];
    int version;
    
    if (sscanf(input, "%19s %d", tableName, &version) != 2) {
        printf("Invalid input format.\n");
        return;
    }
    
    // Simulate database migration logic
    printf("Migrating table: %s to version: %d\n", tableName, version);
}

int main() {
    const char* maliciousInput = "very_long_table_name_that_exceeds_20_characters_to_trigger_buffer_overflow 1";
    migrateDatabase(maliciousInput);
    return 0;
}
