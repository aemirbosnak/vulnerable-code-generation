#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void migrate_data(char *db_name) {
    char buffer[10];
    printf("Enter new database name (up to 9 characters): ");
    gets(buffer);
    strcpy(db_name, buffer);

    printf("Database name changed to: %s\n", db_name);

    // Simulate database migration process
    system("/bin/sh -c 'sleep 5; echo 'Database migrated successfully.' > /tmp/migration_status.txt'");
}

int main() {
    char db_name[100];
    migrate_data(db_name);
    return 0;
}
