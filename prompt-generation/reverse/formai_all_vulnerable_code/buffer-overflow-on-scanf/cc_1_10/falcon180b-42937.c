//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} entry_t;

entry_t database[MAX_ENTRIES];
int num_entries = 0;

void surrealist_indexing_system() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Key: %s\n", database[i].key);
        printf("Value: %s\n\n", database[i].value);
    }
}

int main() {
    int choice;
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    do {
        printf("Surrealist Database Indexing System\n");
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%s", value);

            if (num_entries >= MAX_ENTRIES) {
                printf("Database is full!\n");
            } else {
                strcpy(database[num_entries].key, key);
                strcpy(database[num_entries].value, value);
                num_entries++;
            }
            break;

        case 2:
            printf("Enter key to search: ");
            scanf("%s", key);

            surrealist_indexing_system();

            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }

    } while (1);

    return 0;
}