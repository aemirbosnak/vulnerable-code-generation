#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 20

void migrateDatabase(const char* srcDbPath, const char* destDbPath) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, srcDbPath);
    strcat(buffer, "/");
    strcat(buffer, destDbPath);

    FILE *srcFile = fopen(buffer, "r");
    if (!srcFile) {
        perror("Error opening source database file");
        return;
    }

    FILE *destFile = fopen(strcat(buffer, ".new"), "w");
    if (!destFile) {
        fclose(srcFile);
        perror("Error opening destination database file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), srcFile)) {
        fputs(line, destFile);
    }

    fclose(srcFile);
    fclose(destFile);

    rename(strcat(buffer, ".new"), buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_db_path> <destination_db_path>\n", argv[0]);
        return 1;
    }

    migrateDatabase(argv[1], argv[2]);

    printf("Database migration completed successfully.\n");

    return 0;
}
