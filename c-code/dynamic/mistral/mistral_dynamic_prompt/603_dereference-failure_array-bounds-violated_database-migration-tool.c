#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define FIELD_LENGTH 200

void migrate_data(char *source_file, char *destination_file) {
    FILE *src_fd = fopen(source_file, "r");
    FILE *dst_fd = fopen(destination_file, "w");

    char fields[MAX_FIELDS][FIELD_LENGTH];
    int fields_count = 0;

    char line[FIELD_LENGTH * 2];

    while (fgets(line, sizeof(line), src_fd)) {
        sscanf(line, "%s%*c%s%*c%s%*c%s%*c%s%*c%s%*c%s%*c%s", fields[fields_count], fields[fields_count + 1], fields[fields_count + 2], fields[fields_count + 3], fields[fields_count + 4], fields[fields_count + 5], fields[fields_count + 6], fields[fields_count + 7], fields[fields_count + 8], fields[fields_count + 9]);
        fields_count += 10;
    }

    fprintf(dst_fd, "%s\n", fields[0]);
    fprintf(dst_fd, "%s\n", fields[1]);
    fprintf(dst_fd, "%s\n", fields[2]);

    // Unchecked array access with hardcoded index
    fprintf(dst_fd, "%s\n", fields[fields_count]); // Dereference failure

    fclose(src_fd);
    fclose(dst_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: migrate_data <source_file> <destination_file>\n");
        return 1;
    }

    migrate_data(argv[1], argv[2]);
    return 0;
}
