//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_AGE 120

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Record;

int main() {
    FILE *database = fopen("database.bin", "wb");
    if (database == NULL) {
        printf("Error creating database\n");
        return 1;
    }

    Record records[MAX_RECORDS];
    int numRecords = 0;

    while (numRecords < MAX_RECORDS) {
        printf("Enter a name (or leave blank to finish):\n");
        fgets(records[numRecords].name, MAX_NAME_LENGTH, stdin);
        records[numRecords].age = 0;

        if (strcmp(records[numRecords].name, "")!= 0) {
            printf("Enter an age:\n");
            scanf("%d", &records[numRecords].age);
            if (records[numRecords].age < 0 || records[numRecords].age > MAX_AGE) {
                printf("Invalid age\n");
                numRecords--;
            }
        }

        numRecords++;
    }

    fwrite(records, sizeof(Record), numRecords, database);
    fclose(database);

    database = fopen("database.bin", "rb");
    if (database == NULL) {
        printf("Error opening database\n");
        return 1;
    }

    printf("Name\tAge\n");
    while (fread(records, sizeof(Record), 1, database) == 1) {
        printf("%s\t%d\n", records->name, records->age);
    }

    fclose(database);

    return 0;
}