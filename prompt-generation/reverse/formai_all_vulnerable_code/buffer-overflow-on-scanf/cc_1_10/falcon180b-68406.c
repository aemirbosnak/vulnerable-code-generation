//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    char *key;
    int value;
} Record;

Record records[MAX_SIZE];
int num_records = 0;

void insert_record(char *key, int value) {
    if (num_records >= MAX_SIZE) {
        printf("Error: Maximum capacity reached.\n");
        return;
    }

    strcpy(records[num_records].key, key);
    records[num_records].value = value;
    num_records++;
}

int search_record(char *key) {
    int i;

    for (i = 0; i < num_records; i++) {
        if (strcmp(records[i].key, key) == 0) {
            return records[i].value;
        }
    }

    return -1;
}

int main() {
    char key[50];
    int value, choice;

    printf("Welcome to the Record Manager!\n");
    printf("Enter 1 to insert a record, 2 to search for a record, or 3 to exit.\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key and value for the record, separated by a space:\n");
                scanf("%s %d", key, &value);
                insert_record(key, value);
                break;

            case 2:
                printf("Enter the key to search for:\n");
                scanf("%s", key);
                value = search_record(key);

                if (value == -1) {
                    printf("Record not found.\n");
                } else {
                    printf("Record found with value %d.\n", value);
                }
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}