#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void migrateDatabase() {
    char oldData[10];
    char newData[20];

    printf("Enter old data: ");
    scanf("%s", oldData);

    // Buffer overflow vulnerability here
    strcpy(newData, oldData);

    printf("Migrated data: %s\n", newData);
}

int main() {
    migrateDatabase();
    return 0;
}
