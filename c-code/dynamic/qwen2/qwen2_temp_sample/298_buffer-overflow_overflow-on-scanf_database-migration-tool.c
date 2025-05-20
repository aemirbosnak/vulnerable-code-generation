#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 10

void migrateDatabase() {
    char buffer[MAX_BUFFER_SIZE];
    
    printf("Enter your migration script: ");
    scanf("%s", buffer); // Buffer overflow vulnerability
    
    printf("Migrating database with script: %s\n", buffer);
}

int main() {
    printf("Welcome to the Database Migration Tool\n");
    migrateDatabase();
    return 0;
}
