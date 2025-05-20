//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[20];
    int age;
    struct Record* next;
} Record;

Record* insertRecord(Record* head) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    scanf("Enter name: ", newRecord->name);
    scanf("Enter age: ", &newRecord->age);
    newRecord->next = head;
    head = newRecord;
    return head;
}

void searchRecord(Record* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\n", head->name);
            printf("Age: %d\n", head->age);
            return;
        }
        head = head->next;
    }
    printf("Record not found.\n");
}

int main() {
    Record* head = NULL;
    char name[20];

    printf("Enter 'add' to add a record, 'search' to search for a record, or 'exit' to exit: ");
    scanf("%s", name);

    while (strcmp(name, "exit") != 0) {
        if (strcmp(name, "add") == 0) {
            head = insertRecord(head);
        } else if (strcmp(name, "search") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            searchRecord(head, name);
        } else {
            printf("Invalid command.\n");
        }

        printf("Enter 'add', 'search', or 'exit': ");
        scanf("%s", name);
    }

    return 0;
}