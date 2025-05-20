//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_STR_LEN 50

typedef struct {
    char *key;
    int value;
} Record;

int main() {
    Record database[MAX_SIZE];
    int numRecords = 0;
    char choice;
    char searchKey[MAX_STR_LEN];
    int searchResult;

    do {
        printf("Cyberpunk Database\n");
        printf("-------------------\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter the key: ");
            scanf("%s", searchKey);
            printf("Enter the value: ");
            scanf("%d", &database[numRecords].value);
            strcpy(database[numRecords].key, searchKey);
            numRecords++;
            printf("Record added successfully.\n");
            break;
        case '2':
            printf("Enter the key to search: ");
            scanf("%s", searchKey);
            searchResult = binarySearch(database, numRecords, searchKey);

            if (searchResult == -1) {
                printf("Record not found.\n");
            } else {
                printf("Record found at position %d.\n", searchResult);
            }
            break;
        case '3':
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '3');

    return 0;
}

int binarySearch(Record arr[], int n, char key[MAX_STR_LEN]) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (strcmp(arr[mid].key, key) == 0) {
            return mid;
        } else if (strcmp(arr[mid].key, key) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}