//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define KEY_LENGTH 20

typedef struct {
    char key[KEY_LENGTH];
    int value;
} Record;

void createIndex(Record index[], const char key[], int value) {
    int i;

    for (i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(index[i].key, key) == 0) {
            index[i].value = value;
            return;
        }
        if (i == MAX_RECORDS - 1) {
            for (int j = 0; j < i; j++) {
                if (strcmp(index[j].key, key) > 0) {
                    memmove(&index[j + 1], &index[j], sizeof(Record) * (i - j));
                    strcpy(index[j].key, key);
                    index[j].value = value;
                    break;
                }
            }
            break;
        }
    }

    strcpy(index[i].key, key);
    index[i].value = value;
}

int searchIndex(Record index[], const char key[]) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(index[i].key, key) == 0) {
            return index[i].value;
        }
    }

    return -1;
}

int main() {
    Record index[MAX_RECORDS];
    char key[KEY_LENGTH];
    int value, result;

    for (int i = 0; i < 10; i++) {
        scanf("%s %d", key, &value);
        createIndex(index, key, value);
    }

    for (int i = 0; i < 3; i++) {
        scanf("%s", key);
        result = searchIndex(index, key);
        if (result != -1) {
            printf("%d\n", result);
        } else {
            printf("Key not found.\n");
        }
    }

    return 0;
}