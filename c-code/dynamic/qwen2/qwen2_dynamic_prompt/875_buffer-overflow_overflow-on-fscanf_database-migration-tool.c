#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 10

void migrate_data() {
    char old_name[MAX_NAME_LENGTH];
    char new_name[20];

    printf("Enter old name: ");
    fscanf(stdin, "%s", old_name);

    printf("Enter new name: ");
    fscanf(stdin, "%s", new_name);

    // Vulnerability: No bounds checking on new_name
    printf("Migrating data from %s to %s\n", old_name, new_name);
}

int main() {
    migrate_data();
    return 0;
}
