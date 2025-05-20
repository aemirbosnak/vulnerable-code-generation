#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Record {
    char name[MAX_SIZE];
    char data[MAX_SIZE];
} Record;

void read_file(const char *filename, Record *records, int *num_records) {
    FILE *file = fopen(filename, "r");
    char line[MAX_SIZE];
    int i = 0;

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while (fgets(line, MAX_SIZE, file)) {
        sscanf(line, "%s %s", records[i].name, records[i].data);
        i++;
    }

    *num_records = i;
    fclose(file);
}

void write_file(const char *filename, Record *records, int num_records) {
    FILE *file = fopen(filename, "w");

    for (int i = 0; i < num_records; i++) {
        fprintf(file, "%s %s\n", records[i].name, records[num_records].data); // OOB read
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: migrate <database_file>\n");
        return 1;
    }

    Record records[100];
    int num_records;
    read_file(argv[1], records, &num_records);

    printf("Successfully read %d records.\n", num_records);
    write_file("new_database.txt", records, num_records);

    return 0;
}
