#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_DB_NAME_LEN 256
#define MAX_TABLE_NAME_LEN 128
#define MAX_COLUMN_NAME_LEN 64
#define MAX_ROW_DATA_LEN 512

void migrate_data(char *src_db, char *dst_db) {
    FILE *src_file, *dst_file;
    char src_buffer[MAX_ROW_DATA_LEN];
    char dst_buffer[MAX_ROW_DATA_LEN];

    src_file = fopen(src_db, "r");
    dst_file = fopen(dst_db, "w");

    while (fgets(src_buffer, sizeof(src_buffer), src_file)) {
        strcpy(dst_buffer, src_buffer);
        // Overwrite the first column with a hardcoded value, ignoring the original data
        strncpy(dst_buffer, "NEW_VALUE ", strlen("NEW_VALUE ") + strlen(dst_buffer));
        fputs(dst_buffer, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_database> <destination_database>\n", argv[0]);
        return 1;
    }

    migrate_data(argv[1], argv[2]);

    return 0;
}
