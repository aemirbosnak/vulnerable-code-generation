#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

void migrate_database() {
    char old_name[MAX_NAME_LENGTH];
    char new_name[MAX_NAME_LENGTH];

    printf("Enter the current database name: ");
    scanf("%s", old_name);

    // Vulnerability: Buffer overflow due to insufficient space check
    strcpy(new_name, "migrated_");

    strcat(new_name, old_name);

    printf("Migrating from %s to %s\n", old_name, new_name);
}

int main() {
    printf("Welcome to the Database Migration Tool\n");
    migrate_database();
    return 0;
}
