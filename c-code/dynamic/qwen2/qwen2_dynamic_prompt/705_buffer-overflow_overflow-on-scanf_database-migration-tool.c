#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 10

void migrateDatabase() {
    char oldName[MAX_NAME_LENGTH];
    char newName[20];

    printf("Enter old database name: ");
    scanf("%s", oldName);

    printf("Enter new database name: ");
    scanf("%s", newName);

    // Vulnerability: No bounds checking on newName
    strcpy(newName, oldName);
}

int main() {
    migrateDatabase();
    return 0;
}
