//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATA_SIZE 1000
#define MAX_NUM_RECORDS 100

typedef struct {
    char data[MAX_DATA_SIZE];
    struct record *next;
} record;

record *head = NULL;
int numRecords = 0;

void displayRecords() {
    record *current = head;
    printf("\n");
    while (current!= NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void addRecord(char *data) {
    record *newRecord = (record *) malloc(sizeof(record));
    strcpy(newRecord->data, data);
    newRecord->next = NULL;
    if (head == NULL) {
        head = newRecord;
    } else {
        record *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newRecord;
    }
    numRecords++;
}

void deleteRecord(char *data) {
    record *current = head;
    record *prev = NULL;
    while (current!= NULL && strcmp(current->data, data)!= 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Record not found.\n");
    } else {
        if (prev == NULL) {
            head = head->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        numRecords--;
    }
}

void updateRecord(char *data, char *newData) {
    record *current = head;
    while (current!= NULL && strcmp(current->data, data)!= 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Record not found.\n");
    } else {
        strcpy(current->data, newData);
        displayRecords();
    }
}

void searchRecord(char *data) {
    record *current = head;
    while (current!= NULL) {
        if (strcmp(current->data, data) == 0) {
            printf("Record found.\n");
        } else {
            printf("Record not found.\n");
        }
        displayRecords();
        current = current->next;
    }
}

int main() {
    addRecord("John Doe");
    addRecord("Jane Doe");
    addRecord("Bob Smith");
    displayRecords();
    deleteRecord("John Doe");
    displayRecords();
    updateRecord("Jane Doe", "Jane Smith");
    displayRecords();
    searchRecord("Bob Smith");
    return 0;
}