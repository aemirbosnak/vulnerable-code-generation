//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50
#define MAX_RECORD_SIZE 500

typedef struct {
    char *fields[MAX_FIELDS];
    int num_fields;
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void init_database(Database *db) {
    db->records = (Record *)malloc(MAX_RECORDS * sizeof(Record));
    db->num_records = 0;
}

void add_record(Database *db, char *fields[]) {
    Record *record = (Record *)malloc(sizeof(Record));
    record->num_fields = 0;

    for (int i = 0; i < MAX_FIELDS; i++) {
        if (fields[i] == NULL) {
            break;
        }

        record->fields[i] = (char *)malloc(MAX_FIELD_SIZE);
        strncpy(record->fields[i], fields[i], MAX_FIELD_SIZE - 1);
        record->fields[i][MAX_FIELD_SIZE - 1] = '\0';

        record->num_fields++;
    }

    db->records[db->num_records++] = *record;
    free(record);
}

void print_record(Record *record) {
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s ", record->fields[i]);
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

    char *fields[MAX_FIELDS];
    int num_fields;

    while (1) {
        printf("Enter number of fields: ");
        scanf("%d", &num_fields);

        if (num_fields > MAX_FIELDS) {
            printf("Error: Too many fields.\n");
            continue;
        }

        for (int i = 0; i < num_fields; i++) {
            printf("Enter field %d: ", i + 1);
            scanf("%s", fields[i]);

            if (strlen(fields[i]) > MAX_FIELD_SIZE) {
                printf("Error: Field too long.\n");
                i--;
                continue;
            }
        }

        add_record(&db, fields);
    }

    print_database(&db);

    return 0;
}