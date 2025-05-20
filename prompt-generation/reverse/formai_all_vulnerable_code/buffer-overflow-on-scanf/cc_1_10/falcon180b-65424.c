//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    char *key;
    int value;
} record_t;

record_t database[MAX_SIZE];
int num_records = 0;

void insert_record(char *key, int value) {
    if (num_records >= MAX_SIZE) {
        printf("Error: database is full.\n");
        return;
    }
    database[num_records].key = strdup(key);
    database[num_records].value = value;
    num_records++;
}

int search_record(char *key) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i].key, key) == 0) {
            return database[i].value;
        }
    }
    return -1;
}

int main() {
    char input[100];
    int choice;

    printf("Welcome to the database program!\n");
    printf("1. Insert record\n");
    printf("2. Search record\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    while (choice!= 3) {
        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%s", input);
            printf("Enter value: ");
            scanf("%d", &database[num_records].value);
            insert_record(input, database[num_records].value);
            break;
        case 2:
            printf("Enter key to search: ");
            scanf("%s", input);
            printf("Record found with value %d\n", search_record(input));
            break;
        default:
            printf("Invalid choice.\n");
        }
        printf("\n");
        printf("1. Insert record\n");
        printf("2. Search record\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
    }

    return 0;
}