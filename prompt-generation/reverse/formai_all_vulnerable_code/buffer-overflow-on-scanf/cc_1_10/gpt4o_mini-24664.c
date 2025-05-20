//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define INDEX_SIZE 500

typedef struct {
    int id;
    char name[50];
    char email[50];
} Record;

typedef struct {
    int id;
    int record_index;
} IndexEntry;

Record database[MAX_RECORDS];
IndexEntry indexTable[INDEX_SIZE];
int record_count = 0;
int index_count = 0;

void addRecord(int id, const char* name, const char* email) {
    if (record_count >= MAX_RECORDS) {
        printf("Database is full, cannot add more records.\n");
        return;
    }
    database[record_count].id = id;
    strcpy(database[record_count].name, name);
    strcpy(database[record_count].email, email);
    indexTable[index_count].id = id;
    indexTable[index_count].record_index = record_count;
    index_count++;
    record_count++;
    printf("Record added successfully.\n");
}

int searchRecord(int id) {
    for (int i = 0; i < index_count; i++) {
        if (indexTable[i].id == id) {
            return indexTable[i].record_index;
        }
    }
    return -1;
}

void deleteRecord(int id) {
    int index = searchRecord(id);
    if (index == -1) {
        printf("Record not found.\n");
        return;
    }
    // Shift records left
    for (int i = index; i < record_count - 1; i++) {
        database[i] = database[i + 1];
    }
    record_count--;

    // Update index
    for (int i = 0; i < index_count; i++) {
        if (indexTable[i].record_index == index) {
            for (int j = i; j < index_count - 1; j++) {
                indexTable[j] = indexTable[j + 1];
            }
            index_count--;
            break;
        } else if (indexTable[i].record_index > index) {
            indexTable[i].record_index--;
        }
    }
    printf("Record deleted successfully.\n");
}

void displayRecords() {
    printf("ID\tName\tEmail\n");
    for (int i = 0; i < record_count; i++) {
        printf("%d\t%s\t%s\n", database[i].id, database[i].name, database[i].email);
    }
}

int main() {
    int choice, id;
    char name[50];
    char email[50];

    while (1) {
        printf("\n=== Database Indexing System ===\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. Display Records\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);
                addRecord(id, name, email);
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                int index = searchRecord(id);
                if (index != -1) {
                    printf("Found Record: ID=%d, Name=%s, Email=%s\n",
                           database[index].id, database[index].name, database[index].email);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 3:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
            case 4:
                displayRecords();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}