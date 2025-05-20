//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 1000
#define MAX_INDEX_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

typedef struct {
    Record record;
    int index;
} Index;

void createIndex(Index *index, char *key) {
    strcpy(index->record.key, key);
    index->record.value[0] = '\0';
    index->index = 0;
}

void addRecord(Index *index, char *value) {
    strcat(index->record.value, value);
    index->index++;
}

void searchIndex(Index *index, char *key) {
    if (strcmp(index->record.key, key) == 0) {
        printf("Record found:\nKey: %s\nValue: %s\n", index->record.key, index->record.value);
    } else {
        printf("Record not found.\n");
    }
}

int main() {
    Index index;
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];

    printf("Enter key: ");
    scanf("%s", key);

    createIndex(&index, key);

    while (1) {
        printf("\n1. Add record\n2. Search record\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%s", value);
                addRecord(&index, value);
                break;
            case 2:
                searchIndex(&index, key);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}