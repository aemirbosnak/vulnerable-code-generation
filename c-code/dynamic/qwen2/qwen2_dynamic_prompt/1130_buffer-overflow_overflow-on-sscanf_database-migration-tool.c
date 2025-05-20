#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(const char* input) {
    char source[10];
    char destination[20];

    printf("Migrating database from: %s\n", input);
    
    // Vulnerable line - buffer overflow possible if input is too long
    sscanf(input, "%9s %19s", source, destination);

    printf("Source: %s, Destination: %s\n", source, destination);
}

int main() {
    const char* userInput = "very_long_source_path very_long_destination_path";
    migrateDatabase(userInput);
    return 0;
}
