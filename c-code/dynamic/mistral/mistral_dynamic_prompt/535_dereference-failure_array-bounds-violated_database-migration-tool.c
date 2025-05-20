#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_DB_NAME_LEN 20
#define MAX_TABLE_NAME_LEN 50
#define MAX_COLUMN_NAME_LEN 30
#define MAX_RECORD_LEN 100

void main() {
    char dbName[MAX_DB_NAME_LEN];
    char tableName[MAX_TABLE_NAME_LEN];
    char columnName[MAX_COLUMN_NAME_LEN];
    char record[MAX_RECORD_LEN];

    printf("Enter database name: ");
    fgets(dbName, MAX_DB_NAME_LEN, stdin);
    printf("Enter table name: ");
    fgets(tableName, MAX_TABLE_NAME_LEN, stdin);
    printf("Enter column name: ");
    fgets(columnName, MAX_COLUMN_NAME_LEN, stdin);

    printf("Enter record to insert:\n");
    fgets(record, MAX_RECORD_LEN, stdin);

    int numColumns = strlen(columnName);
    int numRecords = strlen(record);

    char **data = malloc((numColumns + 1) * numRecords * sizeof(char*));

    int i, j;
    for (i = 0; i < numColumns; ++i) {
        data[i] = strtok(columnName, " ");
    }

    for (i = 0; i < numRecords; ++i) {
        data[numColumns + i] = strtok(NULL, " ");
        for (j = numColumns; j < numColumns + i; ++j) {
            printf("%s ", data[j]);
        }
        printf("\n");
    }

    free(data);
}
