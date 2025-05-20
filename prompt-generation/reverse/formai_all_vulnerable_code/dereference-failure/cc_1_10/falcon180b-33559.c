//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record *records;
    int num_records;
    int num_fields;
} Database;

void init_database(Database *db) {
    db->records = NULL;
    db->num_records = 0;
    db->num_fields = 0;
}

void add_field(Database *db, char *name) {
    db->num_fields++;
}

void add_record(Database *db, char *name, char *value) {
    Record *rec = malloc(sizeof(Record));
    strcpy(rec->name, name);
    strcpy(rec->value, value);
    db->records = realloc(db->records, sizeof(Record) * (db->num_records + 1));
    db->records[db->num_records++] = *rec;
}

int main() {
    Database db;
    init_database(&db);

    add_field(&db, "name");
    add_field(&db, "age");

    add_record(&db, "Alice", "25");
    add_record(&db, "Bob", "30");
    add_record(&db, "Charlie", "35");

    printf("Name\tAge\n");
    for (int i = 0; i < db.num_records; i++) {
        printf("%s\t%s\n", db.records[i].name, db.records[i].value);
    }

    return 0;
}