#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void copy_data(char *dest, const char *src) {
    strcpy(dest, src);
}

void migrate_data(char *db_file, char *new_db_file) {
    FILE *db_fp = fopen(db_file, "r");
    char db_data[10];
    fscanf(db_fp, "%s", db_data);

    FILE *new_db_fp = fopen(new_db_file, "w");
    copy_data(db_data, "Overwritten data with a buffer overflow");
    fprintf(new_db_fp, "%s", db_data);
    fclose(db_fp);
    fclose(new_db_fp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: migrate_data <old_database> <new_database>\n");
        return 1;
    }

    migrate_data(argv[1], argv[2]);
    printf("Data migration completed successfully!\n");

    return 0;
}
