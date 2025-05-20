#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_TABLES 10
#define TABLE_NAME_LENGTH 50

typedef struct {
    char name[TABLE_NAME_LENGTH];
    int num_columns;
} Table;

Table tables[MAX_TABLES];

void migrate_database() {
    FILE *src_file = fopen("source_database.txt", "r");
    if (!src_file) {
        printf("Error opening source file\n");
        return;
    }

    FILE *dest_file = fopen("destination_database.bin", "wb");
    if (!dest_file) {
        printf("Error opening destination file\n");
        fclose(src_file);
        return;
    }

    int table_count;
    fscanf(src_file, "%d", &table_count);

    if (table_count > MAX_TABLES) {
        printf("Too many tables\n");
        goto cleanup;
    }

    for (int i = 0; i < table_count; i++) {
        fscanf(src_file, "%s %d", tables[i].name, &tables[i].num_columns);
    }

    fwrite(tables, sizeof(Table), table_count, dest_file);

cleanup:
    fclose(src_file);
    fclose(dest_file);
}

int main() {
    migrate_database();
    return 0;
}
