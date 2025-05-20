//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_EMAIL_LEN 50

typedef struct Record {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
    struct Record* next;
} Record;

typedef struct IndexNode {
    char name[MAX_NAME_LEN];
    Record* recordRef;
    struct IndexNode* next;
} IndexNode;

Record* head = NULL;
IndexNode* indexHead = NULL;

void insertRecord(const char* name, const char* phone, const char* email) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    strcpy(newRecord->name, name);
    strcpy(newRecord->phone, phone);
    strcpy(newRecord->email, email);
    newRecord->next = head;
    head = newRecord;

    // Insert into index
    IndexNode* newIndexNode = (IndexNode*)malloc(sizeof(IndexNode));
    strcpy(newIndexNode->name, name);
    newIndexNode->recordRef = newRecord;
    newIndexNode->next = indexHead;
    indexHead = newIndexNode;
}

Record* searchByName(const char* name) {
    IndexNode* currentIndex = indexHead;
    while (currentIndex != NULL) {
        if (strcmp(currentIndex->name, name) == 0) {
            return currentIndex->recordRef;
        }
        currentIndex = currentIndex->next;
    }
    return NULL;
}

void printAllRecords() {
    Record* current = head;
    while (current != NULL) {
        printf("Name: %s, Phone: %s, Email: %s\n", current->name, current->phone, current->email);
        current = current->next;
    }
}

void deleteDatabase() {
    Record* current = head;
    while (current != NULL) {
        Record* temp = current;
        current = current->next;
        free(temp);
    }

    IndexNode* indexCurrent = indexHead;
    while (indexCurrent != NULL) {
        IndexNode* temp = indexCurrent;
        indexCurrent = indexCurrent->next;
        free(temp);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LEN], phone[MAX_PHONE_LEN], email[MAX_EMAIL_LEN];

    do {
        printf("\nDatabase Indexing System\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Print All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume the newline character

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline

                printf("Enter Phone: ");
                fgets(phone, MAX_PHONE_LEN, stdin);
                phone[strcspn(phone, "\n")] = 0; // Remove trailing newline

                printf("Enter Email: ");
                fgets(email, MAX_EMAIL_LEN, stdin);
                email[strcspn(email, "\n")] = 0; // Remove trailing newline

                insertRecord(name, phone, email);
                printf("Record inserted successfully!\n");
                break;

            case 2:
                printf("Enter Name to search: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline

                Record* foundRecord = searchByName(name);
                if (foundRecord) {
                    printf("Record found:\nName: %s, Phone: %s, Email: %s\n", 
                           foundRecord->name, foundRecord->phone, foundRecord->email);
                } else {
                    printf("Record not found!\n");
                }
                break;

            case 3:
                printf("All Records:\n");
                printAllRecords();
                break;

            case 4:
                deleteDatabase();
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}