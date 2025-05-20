//FormAI DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 10
#define MAX_RECORDS 5
#define MAX_DATA_LENGTH 50

struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    char data[MAX_DATA_LENGTH];
};

void saveRecord(FILE* file, struct Record* record) {
    fwrite(&record->id, sizeof(record->id), 1, file);
    fwrite(record->name, sizeof(record->name), 1, file);
    fwrite(record->data, sizeof(record->data), 1, file);
}

void loadRecord(FILE* file, struct Record* record) {
    fread(&record->id, sizeof(record->id), 1, file);
    fread(&record->name, sizeof(record->name), 1, file);
    fread(&record->data, sizeof(record->data), 1, file);
}

void printRecord(struct Record* record) {
    printf("ID: %d, Name: %s, Data: %s\n", record->id, record->name, record->data);
}

int main() {
    char filename[MAX_NAME_LENGTH];
    printf("Please enter the filename to save the database: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "wb");
    if(file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    struct Record records[MAX_RECORDS];
    for(int i = 0; i < MAX_RECORDS; i++) {
        records[i].id = i + 1;
        snprintf(records[i].name, MAX_NAME_LENGTH, "%d", i + 1);
        snprintf(records[i].data, MAX_DATA_LENGTH, "Record %d data", i + 1);
        saveRecord(file, &records[i]);
    }

    fclose(file);

    file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    struct Record loadedRecords[MAX_RECORDS];
    for(int i = 0; i < MAX_RECORDS; i++) {
        loadRecord(file, &loadedRecords[i]);
        printRecord(&loadedRecords[i]);
    }

    fclose(file);

    return 0;
}