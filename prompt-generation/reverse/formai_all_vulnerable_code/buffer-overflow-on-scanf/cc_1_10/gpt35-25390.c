//FormAI DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    int age;
    char email[30];
} Record;

void saveRecord(Record records[], int *recordCount) {
    if(*recordCount >= MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }
    Record record;
    printf("Enter ID: ");
    scanf("%d", &record.id);
    printf("Enter name: ");
    scanf("%s", record.name);
    printf("Enter age: ");
    scanf("%d", &record.age);
    printf("Enter email: ");
    scanf("%s", record.email);
    records[*recordCount] = record;
    *recordCount += 1;
    printf("Record saved successfully.\n");
}

void deleteRecord(Record records[], int *recordCount) {
    int id;
    printf("Enter ID of the record to delete: ");
    scanf("%d", &id);
    int index = -1;
    for(int i = 0; i < *recordCount; i++) {
        if(records[i].id == id) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Record with ID %d not found.\n", id);
        return;
    }
    for(int i = index; i < *recordCount-1; i++) {
        records[i] = records[i+1];
    }
    *recordCount -= 1;
    printf("Record deleted successfully.\n");
}

void listRecords(Record records[], int recordCount) {
    printf("ID\tName\tAge\tEmail\n");
    for(int i = 0; i < recordCount; i++) {
        printf("%d\t%s\t%d\t%s\n", records[i].id, records[i].name, records[i].age, records[i].email);
    }
}

int main() {
    Record records[MAX_RECORDS];
    int recordCount = 0;
    char choice;
    while(1) {
        printf("\nEnter your choice:\n");
        printf("1. Save record\n");
        printf("2. Delete record\n");
        printf("3. List records\n");
        printf("4. Exit\n");
        fflush(stdin);
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                saveRecord(records, &recordCount);
                break;
            case '2':
                deleteRecord(records, &recordCount);
                break;
            case '3':
                listRecords(records, recordCount);
                break;
            case '4':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}