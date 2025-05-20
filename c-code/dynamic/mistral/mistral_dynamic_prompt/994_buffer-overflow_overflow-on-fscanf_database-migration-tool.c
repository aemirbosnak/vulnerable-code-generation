#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void migrate_database(char *file_path) {
    FILE *fp;
    char input[BUFFER_SIZE];

    if (!(fp = fopen(file_path, "r"))) {
        printf("Error: Unable to open file.\n");
        return;
    }

    printf("Reading database migration script...\n");

    while (fgets(input, BUFFER_SIZE, fp)) {
        if (strstr(input, "DROP TABLE")) {
            // Perform drop table action here
            printf("Executing DROP TABLE command.\n");
        } else if (strstr(input, "CREATE TABLE")) {
            // Perform create table action here
            printf("Executing CREATE TABLE command.\n");
        } else if (strstr(input, "INSERT INTO")) {
            // Perform insert into action here
            printf("Executing INSERT INTO command.\n");
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: db_migrate <path_to_script>\n");
        return 1;
    }

    migrate_database(argv[1]);

    return 0;
}
