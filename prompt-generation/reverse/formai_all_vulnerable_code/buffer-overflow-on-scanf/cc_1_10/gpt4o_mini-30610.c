//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    int id;
} Record;

void printMenu();
void addRecord(Record records[], int *count);
void displayRecords(Record records[], int count);
int linearSearch(Record records[], int count, const char *searchTerm);
int binarySearch(Record records[], int count, const char *searchTerm);
void sortRecords(Record records[], int count);

int main() {
    Record records[MAX_SIZE];
    int count = 0;
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline

        switch (choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                displayRecords(records, count);
                break;
            case 3: {
                char searchTerm[MAX_LENGTH];
                printf("Enter name to search: ");
                fgets(searchTerm, MAX_LENGTH, stdin);
                searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline character

                int index = linearSearch(records, count, searchTerm);
                if (index != -1) {
                    printf("Record found: %s, ID: %d\n", records[index].name, records[index].id);
                } else {
                    printf("Record not found.\n");
                }
                break;
            }
            case 4:
                sortRecords(records, count);
                break;
            case 5: {
                char searchTerm[MAX_LENGTH];
                printf("Enter name to search: ");
                fgets(searchTerm, MAX_LENGTH, stdin);
                searchTerm[strcspn(searchTerm, "\n")] = 0; // remove newline character

                int index = binarySearch(records, count, searchTerm);
                if (index != -1) {
                    printf("Record found: %s, ID: %d\n", records[index].name, records[index].id);
                } else {
                    printf("Record not found.\n");
                }
                break;
            }
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void printMenu() {
    printf("\n=== Menu ===\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Linear Search by Name\n");
    printf("4. Sort Records\n");
    printf("5. Binary Search by Name\n");
    printf("0. Exit\n");
}

void addRecord(Record records[], int *count) {
    if (*count < MAX_SIZE) {
        printf("Enter name (max %d chars): ", MAX_LENGTH-1);
        fgets(records[*count].name, MAX_LENGTH, stdin);
        records[*count].name[strcspn(records[*count].name, "\n")] = 0; // remove newline

        printf("Enter ID: ");
        scanf("%d", &records[*count].id);
        getchar(); // to consume newline

        (*count)++;
        printf("Record added successfully.\n");
    } else {
        printf("Cannot add more records. Max limit reached.\n");
    }
}

void displayRecords(Record records[], int count) {
    if (count == 0) {
        printf("No records to display.\n");
    } else {
        printf("\n=== Records ===\n");
        for (int i = 0; i < count; i++) {
            printf("Name: %s, ID: %d\n", records[i].name, records[i].id);
        }
    }
}

int linearSearch(Record records[], int count, const char *searchTerm) {
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].name, searchTerm) == 0) {
            return i;
        }
    }
    return -1; // not found
}

void sortRecords(Record records[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(records[j].name, records[j + 1].name) > 0) {
                // Swap
                Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
    printf("Records sorted successfully.\n");
}

int binarySearch(Record records[], int count, const char *searchTerm) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(records[mid].name, searchTerm);
        
        if (cmp == 0) {
            return mid; // found
        }
        else if (cmp < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // not found
}