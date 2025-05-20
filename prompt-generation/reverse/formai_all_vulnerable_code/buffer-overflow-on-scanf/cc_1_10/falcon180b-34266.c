//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int key;
    int value;
} record;

void insert(record *table, int key, int value) {
    int i = 0;
    while (i < MAX_SIZE && table[i].key!= key) {
        i++;
    }
    if (i == MAX_SIZE) {
        printf("Table is full, cannot insert record\n");
        return;
    }
    table[i].key = key;
    table[i].value = value;
}

int search(record *table, int key) {
    int i = 0;
    while (i < MAX_SIZE && table[i].key!= key) {
        i++;
    }
    if (i == MAX_SIZE) {
        return -1;
    }
    return table[i].value;
}

int main() {
    record table[MAX_SIZE];
    int choice, key, value;

    printf("Enter 1 to insert a record, 2 to search a record, 3 to exit\n");
    while (1) {
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter key and value for the record to be inserted\n");
            scanf("%d %d", &key, &value);
            insert(table, key, value);
        } else if (choice == 2) {
            printf("Enter key for the record to be searched\n");
            scanf("%d", &key);
            value = search(table, key);
            if (value!= -1) {
                printf("Value for key %d is %d\n", key, value);
            } else {
                printf("No record found for key %d\n", key);
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}