//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_FIELD_SIZE 100
#define MAX_LINE_SIZE 1024

typedef struct {
    char *field[MAX_FIELD_SIZE];
    int num_fields;
} Record;

typedef struct {
    Record *records;
    int num_records;
} Database;

void initialize_database(Database *db) {
    db->records = NULL;
    db->num_records = 0;
}

void add_record(Database *db, char *line) {
    Record *record = malloc(sizeof(Record));
    char *token = strtok(line, ",");
    int i = 0;
    while(token!= NULL) {
        if(i >= MAX_FIELD_SIZE) {
            printf("Error: Record has too many fields.\n");
            exit(1);
        }
        record->field[i] = strdup(token);
        token = strtok(NULL, ",");
        i++;
    }
    record->num_fields = i;
    db->records = realloc(db->records, sizeof(Record) * (db->num_records + 1));
    db->records[db->num_records] = *record;
    db->num_records++;
}

void print_record(Record *record) {
    for(int i = 0; i < record->num_fields; i++) {
        printf("%s ", record->field[i]);
    }
    printf("\n");
}

void print_database(Database *db) {
    for(int i = 0; i < db->num_records; i++) {
        print_record(db->records + i);
    }
}

void filter_database(Database *db, char *field_name, char *value) {
    for(int i = 0; i < db->num_records; i++) {
        Record *record = db->records + i;
        for(int j = 0; j < record->num_fields; j++) {
            if(strcmp(record->field[j], field_name) == 0) {
                if(strcmp(record->field[j + 1], value) == 0) {
                    print_record(record);
                }
            }
        }
    }
}

int main() {
    Database db;
    initialize_database(&db);
    FILE *fp = fopen("database.csv", "r");
    char line[MAX_LINE_SIZE];
    while(fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        add_record(&db, line);
    }
    fclose(fp);
    print_database(&db);
    filter_database(&db, "Name", "John");
    return 0;
}