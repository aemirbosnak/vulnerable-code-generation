#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(const char* source, const char* destination) {
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "mysqldump -u root -p %s | mysql -u root -p %s", source, destination);
    system(buffer);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_database> <destination_database>\n", argv[0]);
        return 1;
    }

    const char* source = argv[1];
    const char* destination = argv[2];

    migrateDatabase(source, destination);

    printf("Migration completed successfully.\n");
    return 0;
}
