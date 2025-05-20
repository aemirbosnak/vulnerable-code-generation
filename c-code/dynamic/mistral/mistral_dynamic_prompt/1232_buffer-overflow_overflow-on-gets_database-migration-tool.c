#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void migrate_data(char *input) {
    char buffer[BUFFER_SIZE];
    printf("Enter the database path: ");
    gets(buffer);
    strcpy(buffer, input);
    // malicious database operation using the vulnerable buffer
    printf("Migrating data to: %s\n", buffer);
}

int main() {
    char malicious_data[1000] = "A"
    "very"
    "long"
    "malicious"
    "string"
    "to"
    "deliberately"
    "cause"
    "a"
    "buffer"
    "overflow";

    printf("Welcome to the Database Migration Tool!\n");
    migrate_data(malicious_data);

    return 0;
}
