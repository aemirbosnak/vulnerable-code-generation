//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 50
#define MAX_VALUE_SIZE 200
#define MAX_NUM_KEYS 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValue;

int numKeys = 0;
KeyValue *keys = NULL;

void createIndex() {
    int i;
    printf("Enter the number of keys: ");
    scanf("%d", &numKeys);
    keys = (KeyValue *)malloc(numKeys * sizeof(KeyValue));
    for (i = 0; i < numKeys; i++) {
        printf("Enter the key for key %d: ", i+1);
        scanf("%s", keys[i].key);
        printf("Enter the value for key %d: ", i+1);
        scanf("%s", keys[i].value);
    }
}

void searchIndex() {
    char searchKey[MAX_KEY_SIZE];
    printf("Enter the key to search for: ");
    scanf("%s", searchKey);
    int i;
    for (i = 0; i < numKeys; i++) {
        if (strcmp(keys[i].key, searchKey) == 0) {
            printf("Value for key '%s': %s\n", searchKey, keys[i].value);
        }
    }
}

int main() {
    printf("Welcome to the C Database Indexing System!\n");
    int choice;
    do {
        printf("1. Create Index\n2. Search Index\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createIndex();
                break;
            case 2:
                searchIndex();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);
    return 0;
}