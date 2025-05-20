#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void migrate_data(char *db_file) {
    char input[MAX_SIZE];
    printf("Enter SQL query to execute during migration:\n");
    gets(input);

    FILE *db = fopen(db_file, "w");
    if (db == NULL) {
        perror("Error opening database file");
        return;
    }

    fprintf(db, "CREATE TABLE users (id INT, name VARCHAR(255));\n");
    fprintf(db, input); // Insert the SQL query from user input here
    fclose(db);

    printf("Migration complete.\n");
}

int main() {
    migrate_data("database.db");
    return 0;
}
