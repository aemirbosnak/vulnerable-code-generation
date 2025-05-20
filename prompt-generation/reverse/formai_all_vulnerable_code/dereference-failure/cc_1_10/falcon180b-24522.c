//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int numFields;
} Record;

typedef struct {
    Record *records;
    int numRecords;
} Database;

void initDatabase(Database *db) {
    db->records = NULL;
    db->numRecords = 0;
}

void addRecord(Database *db, Record *rec) {
    db->records = realloc(db->records, sizeof(Record) * (db->numRecords + 1));
    db->records[db->numRecords] = *rec;
    db->numRecords++;
}

int main() {
    Database db;
    initDatabase(&db);

    char input[1000];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *token = strtok(input, ",");
        Record rec;
        rec.numFields = 0;

        while (token!= NULL) {
            if (rec.numFields >= MAX_FIELD_SIZE) {
                printf("Error: Record has too many fields.\n");
                exit(1);
            }

            char *field = malloc(strlen(token) + 1);
            strcpy(field, token);
            rec.fields[rec.numFields] = field;
            rec.numFields++;

            token = strtok(NULL, ",");
        }

        addRecord(&db, &rec);
    }

    printf("Number of records: %d\n", db.numRecords);

    for (int i = 0; i < db.numRecords; i++) {
        Record rec = db.records[i];
        printf("Record %d:\n", i+1);
        for (int j = 0; j < rec.numFields; j++) {
            printf("Field %d: %s\n", j+1, rec.fields[j]);
        }
    }

    free(db.records);
    return 0;
}