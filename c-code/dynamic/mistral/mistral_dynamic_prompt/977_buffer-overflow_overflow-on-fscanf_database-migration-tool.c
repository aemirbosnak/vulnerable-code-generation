#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_data(char *buffer, int size) {
    printf("Enter data (up to %d characters):\n", size);
    fscanf(stdin, "%s", buffer);
}

void migrate_data(char *old_db, char *new_db) {
    char buffer[10];
    read_data(buffer, 9);
    strcat(old_db, buffer);
    strcat(new_db, buffer);

    read_data(buffer, 9);
    strcat(old_db, buffer);
    strcat(new_db, buffer);

    read_data(buffer, 9);
    strcat(old_db, buffer);
    strcat(new_db, buffer);
}

int main() {
    char old_db[100] = "initial_database";
    char new_db[100] = "new_database";

    migrate_data(old_db, new_db);

    printf("Old Database:\n%s\n", old_db);
    printf("New Database:\n%s\n", new_db);

    return 0;
}
