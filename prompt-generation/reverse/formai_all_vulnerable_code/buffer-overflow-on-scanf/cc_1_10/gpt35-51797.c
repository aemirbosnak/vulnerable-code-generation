//FormAI DATASET v1.0 Category: Database simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 50

struct Record {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int age;
};

struct Database {
    struct Record records[MAX_RECORDS];
    int numRecords;
};

void clearDatabase(struct Database* database) {
    database->numRecords = 0;
}

void addRecord(struct Database* database, const char* name, const char* address, int age) {
    if (database->numRecords >= MAX_RECORDS) {
        printf("Error: Database is full\n");
        return;
    }

    struct Record newRecord;
    strncpy(newRecord.name, name, MAX_NAME_LENGTH);
    strncpy(newRecord.address, address, MAX_ADDRESS_LENGTH);
    newRecord.age = age;

    database->records[database->numRecords++] = newRecord;

    printf("Record added successfully!\n");
}

void printRecord(const struct Record* record) {
    printf("Name: %s\n", record->name);
    printf("Address: %s\n", record->address);
    printf("Age: %d\n", record->age);
}

void printDatabase(const struct Database* database) {
    for (int i = 0; i < database->numRecords; ++i) {
        const struct Record* record = &database->records[i];
        printf("Record %d:\n", i + 1);
        printRecord(record);
    }
}

int main() {
    struct Database database;
    clearDatabase(&database);

    while (1) {
        printf("1. Add record\n"
               "2. Show all records\n"
               "3. Quit\n"
               "Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH], address[MAX_ADDRESS_LENGTH];
                int age;
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                printf("Enter address: ");
                fgets(address, sizeof(address), stdin);
                address[strcspn(address, "\n")] = '\0'; // Remove newline character
                printf("Enter age: ");
                scanf("%d", &age);
                getchar(); // Consume newline character
                addRecord(&database, name, address, age);
                break;
            }
            case 2:
                printDatabase(&database);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice\n");
        }
    }

    return 0;
}