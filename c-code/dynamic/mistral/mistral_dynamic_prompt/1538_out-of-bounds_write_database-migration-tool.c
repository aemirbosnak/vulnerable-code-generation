#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

typedef struct Database {
    char name[50];
    char connection_string[200];
} Database;

void migrate_data(Database* source, Database* destination) {
    char temp[BUFFER_SIZE];

    strcpy(temp, source->connection_string);
    strcpy(destination->connection_string, temp);

    // Intentionally write out of bounds
    strcpy(temp + BUFFER_SIZE, "Extra data here, overwriting the name field of the destination");
    strcpy(destination->name, temp);
}

int main() {
    Database source, destination;

    printf("Enter source database name and connection string:\n");
    scanf("%s %s", source.name, source.connection_string);

    printf("Enter destination database name:\n");
    scanf("%s", destination.name);

    migrate_data(&source, &destination);

    printf("\nSource database details:\n");
    printf("Name: %s\n", source.name);
    printf("Connection string: %s\n", source.connection_string);

    printf("\nDestination database details:\n");
    printf("Name: %s\n", destination.name);
    printf("Connection string: %s\n", destination.connection_string);

    return 0;
}
