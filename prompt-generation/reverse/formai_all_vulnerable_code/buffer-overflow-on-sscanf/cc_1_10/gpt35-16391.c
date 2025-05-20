//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_DATA_LENGTH 100
#define MAX_RECORDS 1000

typedef struct record {
    char key[MAX_KEY_LENGTH];
    char data[MAX_DATA_LENGTH];
} Record;

typedef struct index {
    char key[MAX_KEY_LENGTH];
    int recordNum;
} Index;

int compareIndex(const void *p1, const void *p2) {
    return strcmp(((const Index *) p1)->key, ((const Index *) p2)->key);
}

int compareRecord(const void *p1, const void *p2) {
    return strcmp(((const Record *) p1)->key, ((const Record *) p2)->key);
}

int main() {
    Index index[MAX_RECORDS];
    Record records[MAX_RECORDS];
    int numRecords = 0;
    int numIndex = 0;
    char input[MAX_DATA_LENGTH];
    char command[MAX_DATA_LENGTH];
    int i;
    
    while (1) {
        printf("Enter a command: ");
        fgets(input, MAX_DATA_LENGTH, stdin);

        if (sscanf(input, "%s", command) == 1) {
            if (strcmp(command, "add") == 0) {
                char key[MAX_KEY_LENGTH];
                char data[MAX_DATA_LENGTH];
                sscanf(input, "add %s %[^\n]", key, data);
                if (numRecords < MAX_RECORDS) {
                    strcpy(records[numRecords].key, key);
                    strcpy(records[numRecords++].data, data);
                    strcpy(index[numIndex].key, key);
                    index[numIndex++].recordNum = numRecords - 1;
                } else {
                    printf("Error: database full.\n");
                }
            } else if (strcmp(command, "find") == 0) {
                char key[MAX_KEY_LENGTH];
                sscanf(input, "find %s", key);
                Index *result = bsearch(key, index, numIndex, sizeof(Index), compareIndex);
                if (result) {
                    Record *record = &records[result->recordNum];
                    printf("%s: %s\n", record->key, record->data);
                } else {
                    printf("Error: record not found.\n");
                }
            } else if (strcmp(command, "list") == 0) {
                qsort(records, numRecords, sizeof(Record), compareRecord);
                for (i = 0; i < numRecords; i++) {
                    printf("%s: %s\n", records[i].key, records[i].data);
                }
            } else if (strcmp(command, "quit") == 0) {
                break;
            } else {
                printf("Error: invalid command.\n");
            }
        }
    }

    return 0;
}