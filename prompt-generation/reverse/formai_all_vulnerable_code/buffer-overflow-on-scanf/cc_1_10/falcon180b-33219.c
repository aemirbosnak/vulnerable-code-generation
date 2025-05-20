//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int key;
    int value;
} Record;

Record database[MAX_SIZE];
int numRecords;

int binarySearch(int key) {
    int left = 0;
    int right = numRecords - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (database[mid].key == key) {
            return mid;
        } else if (database[mid].key > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

void insertRecord(int key, int value) {
    int index = binarySearch(key);

    if (index == -1) {
        if (numRecords == MAX_SIZE) {
            printf("Error: Database is full.\n");
            return;
        }

        index = numRecords;
        numRecords++;
    }

    database[index].key = key;
    database[index].value = value;
}

void deleteRecord(int key) {
    int index = binarySearch(key);

    if (index == -1) {
        printf("Error: Record not found.\n");
        return;
    }

    for (int i = index; i < numRecords - 1; i++) {
        database[i] = database[i + 1];
    }

    numRecords--;
}

void printDatabase() {
    for (int i = 0; i < numRecords; i++) {
        printf("%d -> %d\n", database[i].key, database[i].value);
    }
}

int main() {
    int choice;

    do {
        printf("1. Insert record\n");
        printf("2. Delete record\n");
        printf("3. Print database\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int key, value;
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertRecord(key, value);
                break;
            }

            case 2: {
                int key;
                printf("Enter key: ");
                scanf("%d", &key);
                deleteRecord(key);
                break;
            }

            case 3:
                printDatabase();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}