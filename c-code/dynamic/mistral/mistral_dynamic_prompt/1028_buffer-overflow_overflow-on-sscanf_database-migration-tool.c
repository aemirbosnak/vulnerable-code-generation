#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MAX_PASSWORD_LENGTH 20

void migrate_data(char *source_database, char *destination_database) {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password for administrator access: ");
    sscanf(gets(password), "%s", password); // VULNERABLE LINE

    if (strcmp(password, "admin1234") == 0) {
        printf("Migration started...\n");
        // Migration logic goes here
    } else {
        printf("Incorrect password.\n");
    }
}

int main() {
    char source_database[BUFFER_SIZE], destination_database[BUFFER_SIZE];

    printf("Enter source database file: ");
    scanf("%s", source_database);
    printf("Enter destination database file: ");
    scanf("%s", destination_database);

    migrate_data(source_database, destination_database);

    return 0;
}
