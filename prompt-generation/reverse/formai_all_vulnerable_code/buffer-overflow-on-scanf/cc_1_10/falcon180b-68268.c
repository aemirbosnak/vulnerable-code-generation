//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct entry {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    time_t timestamp;
    int index;
} Entry;

int main() {
    FILE *db_file;
    db_file = fopen("database.txt", "a+");

    if (db_file == NULL) {
        printf("Error: Could not open database file.\n");
        return 1;
    }

    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (true) {
        printf("Enter name: ");
        scanf("%s", entries[num_entries].name);

        printf("Enter value: ");
        scanf("%s", entries[num_entries].value);

        entries[num_entries].timestamp = time(NULL);
        entries[num_entries].index = num_entries;

        if (fwrite(&entries[num_entries], sizeof(Entry), 1, db_file)!= 1) {
            printf("Error: Failed to write entry to database.\n");
            return 1;
        }

        num_entries++;
        if (num_entries >= MAX_ENTRIES) {
            printf("Error: Maximum number of entries reached.\n");
            return 1;
        }
    }

    fclose(db_file);
    return 0;
}