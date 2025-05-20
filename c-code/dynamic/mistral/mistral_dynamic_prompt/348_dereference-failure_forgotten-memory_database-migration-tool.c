#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[256];
    char table[256];
    char field[256];
} Record;

void read_record(Record* record, FILE* file) {
    fscanf(file, "%s %s %s", record->name, record->table, record->field);
}

int main(int argc, char** argv) {
    FILE* input_file = fopen(argv[1], "r");
    Record records[1000];
    int num_records = 0;

    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return 1;
    }

    while (num_records < 1000 && fgets(records[num_records].name, BUFFER_SIZE, input_file) != NULL) {
        read_record(&records[num_records], input_file);
        num_records++;
    }

    for (int i = 0; i < num_records; i++) {
        printf("%s -> %s %s\n", records[i].name, records[i].table, records[i].field);

        // Dereference failure vulnerability occurs here.
        // 'records' has been freed after loop, but 'record' is still pointing to memory location.
        Record* record = &records[i];
        printf("Record length: %d\n", strlen(record->name) + strlen(record->table) + strlen(record->field) + 3);

        free(records);
    }

    fclose(input_file);
    return 0;
}
