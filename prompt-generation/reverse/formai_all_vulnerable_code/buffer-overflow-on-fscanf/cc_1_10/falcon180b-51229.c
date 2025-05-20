//Falcon-180B DATASET v1.0 Category: Database querying ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_DATA_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char data[MAX_DATA_LENGTH];
} Record;

int main() {
    FILE* database = fopen("database.txt", "r");
    if (database == NULL) {
        printf("Error opening database file.\n");
        return 1;
    }

    Record* records = NULL;
    int record_count = 0;

    while (fscanf(database, "%s %s\n", records[record_count].name, records[record_count].data)!= EOF) {
        record_count++;
        records = realloc(records, sizeof(Record) * record_count);
    }

    fclose(database);

    printf("Total records: %d\n", record_count);

    char query[MAX_NAME_LENGTH];
    printf("Enter query: ");
    scanf("%s", query);

    int result_count = 0;
    Record* results = NULL;

    for (int i = 0; i < record_count; i++) {
        if (strstr(records[i].name, query)!= NULL || strstr(records[i].data, query)!= NULL) {
            results = realloc(results, sizeof(Record) * ++result_count);
            strcpy(results[result_count - 1].name, records[i].name);
            strcpy(results[result_count - 1].data, records[i].data);
        }
    }

    printf("Results:\n");
    for (int i = 0; i < result_count; i++) {
        printf("%s - %s\n", results[i].name, results[i].data);
    }

    free(records);
    free(results);

    return 0;
}