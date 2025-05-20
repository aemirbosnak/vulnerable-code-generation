#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256

void migrate_database(char* db_name) {
    char user_input[MAX_SIZE];
    printf("Enter the path to the new database: \n");
    gets(user_input);

    // Dangerous code! Buffer overflow due to use of gets()
    strcpy(user_input, "path/to/new_database/");
    strcat(user_input, db_name);
    strcat(user_input, "/migrate.sql");

    FILE *file = fopen(user_input, "r");
    if (file == NULL) {
        printf("Error: Could not open the new database.\n");
        return;
    }

    // The rest of the code (parsing and executing the SQL file) is intentionally omitted
    // for the sake of brevity and focusing on the buffer overflow vulnerability
}

int main() {
    char db_name[MAX_SIZE];
    printf("Enter the old database name: \n");
    gets(db_name);

    migrate_database(db_name);

    return 0;
}
