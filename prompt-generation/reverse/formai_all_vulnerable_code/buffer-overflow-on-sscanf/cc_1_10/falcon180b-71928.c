//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    Record records[1000];
    int numRecords;
} Database;

int compareRecords(const void *a, const void *b) {
    Record *recordA = (Record *) a;
    Record *recordB = (Record *) b;

    return strcmp(recordA->name, recordB->name);
}

void readDatabase(FILE *file, Database *db) {
    char line[1024];
    Record record;
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (i >= 1000) {
            printf("Error: Maximum number of records reached.\n");
            exit(1);
        }

        if (sscanf(line, "%s %s", record.name, record.value)!= 2) {
            printf("Error: Invalid record format.\n");
            exit(1);
        }

        strcpy(db->records[i].name, record.name);
        strcpy(db->records[i].value, record.value);
        i++;
    }

    db->numRecords = i;
    qsort(db->records, i, sizeof(Record), compareRecords);
}

void writeDatabase(FILE *file, Database *db) {
    for (int i = 0; i < db->numRecords; i++) {
        fprintf(file, "%s %s\n", db->records[i].name, db->records[i].value);
    }
}

void searchDatabase(Database *db, char *query) {
    Record *result = bsearch(query, db->records, db->numRecords, sizeof(Record), compareRecords);

    if (result == NULL) {
        printf("Record not found.\n");
    } else {
        printf("Name: %s\nValue: %s\n", result->name, result->value);
    }
}

int main() {
    Database db;
    FILE *file;
    char filename[100];
    char query[MAX_NAME_LEN];

    printf("Enter database filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    readDatabase(file, &db);
    fclose(file);

    while (1) {
        printf("Enter search query or type 'exit' to quit: ");
        scanf("%s", query);

        if (strcmp(query, "exit") == 0) {
            break;
        }

        searchDatabase(&db, query);
    }

    return 0;
}