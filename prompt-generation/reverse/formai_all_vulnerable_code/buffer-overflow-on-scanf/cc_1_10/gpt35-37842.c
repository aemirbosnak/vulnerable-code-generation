//FormAI DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 30

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

void insertRecord(Record records[], int *size, int id, char name[MAX_NAME_LENGTH]);
void printRecords(Record records[], int size);
void searchRecord(Record records[], int size, char name[MAX_NAME_LENGTH]);

int main() {
    Record records[MAX_RECORDS];
    int size = 0;
    int option;
    char name[MAX_NAME_LENGTH];
    int id;

    do {
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Print All Records\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                insertRecord(records, &size, id, name);
                printf("Record added successfully\n\n");
                break;
            case 2:
                printf("Enter Name to search: ");
                scanf("%s", name);
                searchRecord(records, size, name);
                break;
            case 3:
                printRecords(records, size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, try again\n\n");
        }
    } while(option != 4);

    return 0;
}

void insertRecord(Record records[], int *size, int id, char name[MAX_NAME_LENGTH]) {
    if(*size < MAX_RECORDS) {
        records[*size].id = id;
        strncpy(records[*size].name, name, MAX_NAME_LENGTH);
        (*size)++;
    }
    else {
        printf("Error: Max Records reached\n");
    }
}

void printRecords(Record records[], int size) {
    if(size == 0) {
        printf("No records found\n\n");
    }
    else {
        printf("%-10s %s\n", "ID", "NAME");
        for(int i=0; i<size; i++) {
            printf("%-10d %s\n", records[i].id, records[i].name);
        }
        printf("\n");
    }
}

void searchRecord(Record records[], int size, char name[MAX_NAME_LENGTH]) {
    int found = 0;
    for(int i=0; i<size; i++) {
        if(strncmp(records[i].name, name, MAX_NAME_LENGTH) == 0) {
            printf("Record found:\n");
            printf("%-10s %s\n", "ID", "NAME");
            printf("%-10d %s\n\n", records[i].id, records[i].name);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Record not found\n\n");
    }
}