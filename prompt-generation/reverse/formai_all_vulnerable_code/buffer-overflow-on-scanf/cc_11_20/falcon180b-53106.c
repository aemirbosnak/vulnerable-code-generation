//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 10
#define MAX_KEY_LEN 50
#define MAX_RECORDS 100

typedef struct {
    char *key;
    int value;
} Record;

typedef struct {
    char *key;
    int index;
} Key;

int main() {
    Record records[MAX_RECORDS];
    Key keys[MAX_KEYS];
    int numRecords = 0;
    int numKeys = 0;

    char input[100];
    while(1) {
        printf("Enter a command: ");
        scanf("%s", input);

        if(strcmp(input, "exit") == 0) {
            break;
        } else if(strcmp(input, "add") == 0) {
            Record newRecord;
            printf("Enter key: ");
            scanf("%s", newRecord.key);
            printf("Enter value: ");
            scanf("%d", &newRecord.value);

            for(int i = 0; i < numRecords; i++) {
                if(strcmp(records[i].key, newRecord.key) == 0) {
                    printf("Record already exists.\n");
                    return 1;
                }
            }

            strcpy(records[numRecords].key, newRecord.key);
            records[numRecords].value = newRecord.value;
            numRecords++;
        } else if(strcmp(input, "search") == 0) {
            char searchKey[MAX_KEY_LEN];
            printf("Enter key to search: ");
            scanf("%s", searchKey);

            for(int i = 0; i < numRecords; i++) {
                if(strcmp(records[i].key, searchKey) == 0) {
                    printf("Record found with value %d.\n", records[i].value);
                }
            }
        } else if(strcmp(input, "index") == 0) {
            char indexKey[MAX_KEY_LEN];
            printf("Enter key to index: ");
            scanf("%s", indexKey);

            for(int i = 0; i < numKeys; i++) {
                if(strcmp(keys[i].key, indexKey) == 0) {
                    printf("Key already indexed.\n");
                    return 1;
                }
            }

            strcpy(keys[numKeys].key, indexKey);
            keys[numKeys].index = numRecords;
            numKeys++;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}