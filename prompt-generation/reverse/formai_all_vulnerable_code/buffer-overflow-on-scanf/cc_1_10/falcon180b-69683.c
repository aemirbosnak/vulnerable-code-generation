//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int id;
} Record;

void readRecords(Record *records, int numRecords) {
    FILE *file;
    file = fopen("records.txt", "r");
    if (file == NULL) {
        printf("Error: cannot open file\n");
        exit(1);
    }
    for (int i = 0; i < numRecords; i++) {
        fscanf(file, "%s %d", records[i].name, &records[i].id);
    }
    fclose(file);
}

void writeRecords(Record *records, int numRecords) {
    FILE *file;
    file = fopen("records.txt", "w");
    if (file == NULL) {
        printf("Error: cannot open file\n");
        exit(1);
    }
    for (int i = 0; i < numRecords; i++) {
        fprintf(file, "%s %d\n", records[i].name, records[i].id);
    }
    fclose(file);
}

void searchRecords(Record *records, int numRecords, char *searchName) {
    int searchId;
    printf("Enter ID for %s: ", searchName);
    scanf("%d", &searchId);
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].name, searchName) == 0 && records[i].id == searchId) {
            printf("Record found: %s %d\n", records[i].name, records[i].id);
        }
    }
}

int main() {
    Record records[MAX_SIZE];
    int numRecords;
    printf("Enter number of records: ");
    scanf("%d", &numRecords);
    readRecords(records, numRecords);
    searchRecords(records, numRecords, "John");
    writeRecords(records, numRecords);
    return 0;
}