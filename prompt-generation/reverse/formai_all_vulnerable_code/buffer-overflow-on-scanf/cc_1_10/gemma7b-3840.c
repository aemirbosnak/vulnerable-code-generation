//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[50];
    int age;
    struct Record* next;
} Record;

void insertRecord(Record** head) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    printf("Enter name: ");
    scanf("%s", newRecord->name);
    printf("Enter age: ");
    scanf("%d", &newRecord->age);

    if (*head == NULL) {
        *head = newRecord;
    } else {
        (*head)->next = newRecord;
    }
    *head = newRecord;
}

void searchRecord(Record* head) {
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    Record* currentRecord = head;
    while (currentRecord) {
        if (strcmp(currentRecord->name, searchName) == 0) {
            printf("Name: %s\n", currentRecord->name);
            printf("Age: %d\n", currentRecord->age);
            break;
        }
        currentRecord = currentRecord->next;
    }

    if (currentRecord == NULL) {
        printf("Record not found.\n");
    }
}

int main() {
    Record* head = NULL;

    while (1) {
        int choice;
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertRecord(&head);
                break;
            case 2:
                searchRecord(head);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}