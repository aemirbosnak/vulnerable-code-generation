#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(const char* input) {
    char buffer[10];
    int id;
    float balance;

    printf("Migrating database...\n");
    if (sscanf(input, "%d %f", &id, &balance) != 2) {
        fprintf(stderr, "Invalid input format\n");
        return;
    }

    snprintf(buffer, sizeof(buffer), "ID: %d, Balance: %.2f", id, balance);
    printf("%s\n", buffer);

    // Simulate database update
    FILE* file = fopen("database.txt", "a");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    fprintf(file, "%s\n", buffer);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return 1;
    }

    migrateDatabase(argv[1]);

    return 0;
}
