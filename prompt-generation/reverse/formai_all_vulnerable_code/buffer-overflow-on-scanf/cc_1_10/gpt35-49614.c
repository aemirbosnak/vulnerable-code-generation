//FormAI DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Index {
    int key;
    int index_pos;
};

struct Record {
    int id;
    char name[MAX_SIZE];
    int age;
    char address[MAX_SIZE];
};

void displayRecords(struct Record records[], int size) {
    int i;
    printf("ID\tName\tAge\tAddress\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t%s\n", records[i].id, records[i].name, records[i].age, records[i].address);
    }
    printf("\n");
}

int getIndexPosition(struct Index indexTable[], int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (indexTable[i].key == key) {
            return indexTable[i].index_pos;
        }
    }
    return -1;
}

void addRecord(struct Record records[], struct Index indexTable[], int *size, int *capacity) {
    if (*size >= *capacity) {
        printf("Error: Database is full.");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &records[*size].id);
    printf("Enter Name: ");
    scanf("%s", records[*size].name);
    printf("Enter Age: ");
    scanf("%d", &records[*size].age);
    printf("Enter Address: ");
    scanf("%s", records[*size].address);
    indexTable[*size].key = records[*size].id;
    indexTable[*size].index_pos = *size;
    (*size)++;
    printf("Record added successfully!\n\n");
}

void searchRecord(struct Record records[], struct Index indexTable[], int size) {
    int id, index_pos;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    index_pos = getIndexPosition(indexTable, size, id);
    if (index_pos == -1) {
        printf("Record with ID %d not found.\n\n", id);
    } else {
        printf("ID\tName\tAge\tAddress\n");
        printf("%d\t%s\t%d\t%s\n", records[index_pos].id,
               records[index_pos].name,
               records[index_pos].age,
               records[index_pos].address);
    }
}

int main() {
    int capacity = 100, size = 0, choice;
    struct Record records[capacity];
    struct Index indexTable[capacity];

    do {
        printf("C Database Indexing System\n");
        printf("--------------------------\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Display Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, indexTable, &size, &capacity);
                break;
            case 2:
                searchRecord(records, indexTable, size);
                break;
            case 3:
                displayRecords(records, size);
                break;
            case 4:
                printf("Exiting...Thanks for using the C Database Indexing System.\n");
                break;
            default:
                printf("Invalid choice. Try Again!\n");
        }
    } while (choice != 4);
    return 0;
}