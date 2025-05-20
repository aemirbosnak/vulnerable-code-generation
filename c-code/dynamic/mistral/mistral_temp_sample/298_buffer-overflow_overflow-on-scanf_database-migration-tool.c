#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void copy_data(char *dest, char *src) {
    strcpy(dest, src);
}

void migrate_database() {
    char table_name[10];
    char query[1000];

    printf("Enter table name to migrate: ");
    scanf("%s", table_name);

    copy_data(query, "SELECT * FROM ");
    copy_data(query + strlen(query), table_name);
    copy_data(query + strlen(query), ";");

    system(query);
}

int main() {
    migrate_database();
    return 0;
}
