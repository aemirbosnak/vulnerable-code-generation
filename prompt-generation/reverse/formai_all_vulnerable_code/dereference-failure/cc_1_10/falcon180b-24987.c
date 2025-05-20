//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_KEY_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Record;

int compare_key(const void *a, const void *b) {
    Record *rec1 = (Record *)a;
    Record *rec2 = (Record *)b;

    return strcmp(rec1->key, rec2->key);
}

int main() {
    FILE *db;
    Record *records = NULL;
    int num_records = 0;

    db = fopen("database.txt", "rb");
    if (db == NULL) {
        printf("Error opening database.\n");
        exit(1);
    }

    while (fread(&records[num_records], sizeof(Record), 1, db) == 1) {
        num_records++;
    }

    fclose(db);

    // Sort records by key
    qsort(records, num_records, sizeof(Record), compare_key);

    // Print records
    printf("Name\tKey\tValue\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s\t%s\t%s\n", records[i].name, records[i].key, records[i].value);
    }

    // Free memory
    free(records);

    return 0;
}