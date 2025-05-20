#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void migrate_data(char *input) {
    char data[BUFFER_SIZE];
    printf("Enter data to migrate (up to %d characters):\n", BUFFER_SIZE);
    scanf("%s", data);

    // Simulate database migration process
    printf("Migrating data: %s\n", data);

    // Vulnerable code: no bounds checking on input size
    char output[BUFFER_SIZE];
    strcpy(output, data);
}

int main() {
    char user_input[BUFFER_SIZE];
    printf("Welcome to the Database Migration Tool v1.0\n");
    printf("Enter your administrator password to continue:\n");
    scanf("%s", user_input);

    if (strcmp(user_input, "secret_password") == 0) {
        migrate_data(user_input);
    } else {
        printf("Incorrect password. Exiting...\n");
    }

    return 0;
}
