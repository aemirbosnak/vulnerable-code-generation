//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 10
#define MAX_FIELD_SIZE 50

typedef struct {
    char *field[MAX_FIELDS];
    int num_fields;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

void init_database(Database *db) {
    db->num_records = 0;
}

void add_record(Database *db, Record *rec) {
    db->records[db->num_records++] = *rec;
}

void print_record(Record *rec) {
    for (int i = 0; i < rec->num_fields; i++) {
        printf("%s\t", rec->field[i]);
    }
    printf("\n");
}

void print_database(Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        print_record(&db->records[i]);
    }
}

int main() {
    Database db;
    init_database(&db);

    Record rec;
    char field_buffer[MAX_FIELD_SIZE];

    while (fgets(field_buffer, MAX_FIELD_SIZE, stdin)!= NULL) {
        char *field = strtok(field_buffer, "\t");
        while (field!= NULL) {
            if (rec.num_fields >= MAX_FIELDS) {
                printf("Error: Too many fields in record.\n");
                exit(1);
            }
            rec.field[rec.num_fields++] = strdup(field);
            field = strtok(NULL, "\t");
        }
        add_record(&db, &rec);
        memset(&rec, 0, sizeof(Record));
    }

    print_database(&db);

    return 0;
}