//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

int main() {
    FILE *db_file;
    Record records[MAX_RECORDS];
    int num_records = 0;

    // Open the database file
    db_file = fopen("database.txt", "r");
    if (db_file == NULL) {
        printf("Error: could not open database file.\n");
        return 1;
    }

    // Read the records from the database file
    while (fscanf(db_file, "%s", records[num_records].fields[0])!= EOF) {
        num_records++;
        if (num_records >= MAX_RECORDS) {
            printf("Error: too many records in the database file.\n");
            return 2;
        }
        int i = 1;
        while (fscanf(db_file, " %s", records[num_records].fields[i])!= EOF) {
            i++;
            if (i >= MAX_FIELD_SIZE) {
                printf("Error: too many fields in a record.\n");
                return 3;
            }
        }
        records[num_records].num_fields = i;
    }

    fclose(db_file);

    // Do some funny stuff with the records
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        for (int j = 0; j < records[i].num_fields; j++) {
            printf("Field %d: %s\n", j + 1, records[i].fields[j]);
        }
        printf("\n");
    }

    return 0;
}