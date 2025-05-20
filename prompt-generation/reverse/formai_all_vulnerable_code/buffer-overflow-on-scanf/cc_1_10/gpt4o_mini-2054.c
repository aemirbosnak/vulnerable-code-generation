//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DESCRIPTION_LENGTH 200

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    double balance;
} BankingRecord;

BankingRecord records[MAX_RECORDS];
int record_count = 0;

void addRecord() {
    if (record_count >= MAX_RECORDS) {
        printf("The record limit has been reached, dear Watson.\n");
        return;
    }

    BankingRecord new_record;
    new_record.id = record_count + 1;

    printf("Enter the account holder's name: ");
    getchar(); // Consume newline left by previous input
    fgets(new_record.name, NAME_LENGTH, stdin);
    new_record.name[strcspn(new_record.name, "\n")] = 0;  // Remove newline character

    printf("Enter a brief description of the account (e.g. savings, checking): ");
    fgets(new_record.description, DESCRIPTION_LENGTH, stdin);
    new_record.description[strcspn(new_record.description, "\n")] = 0;  // Remove newline character

    printf("Enter the initial balance: ");
    scanf("%lf", &new_record.balance);

    records[record_count] = new_record;
    record_count++;
    
    printf("The account for %s has been added, Watson!\n", new_record.name);
}

void displayRecords() {
    if (record_count == 0) {
        printf("There are no records to display, Holmes.\n");
        return;
    }

    printf("\n--- Banking Records ---\n");
    for (int i = 0; i < record_count; i++) {
        printf("ID: %d\n", records[i].id);
        printf("Name: %s\n", records[i].name);
        printf("Description: %s\n", records[i].description);
        printf("Balance: %.2lf\n", records[i].balance);
        printf("----------------------\n");
    }
}

void findRecord() {
    int id;
    printf("Enter the ID of the record you wish to find: ");
    scanf("%d", &id);

    if (id <= 0 || id > record_count) {
        printf("No record found for the given ID, my friend.\n");
        return;
    }

    BankingRecord record = records[id - 1];
    printf("Found the record you seek, Watson:\n");
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Description: %s\n", record.description);
    printf("Balance: %.2lf\n", record.balance);
}

void updateBalance() {
    int id;
    double amount;
    printf("Enter the ID of the record to update the balance: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > record_count) {
        printf("I fear no such record exists, my dear Watson.\n");
        return;
    }

    printf("Enter the amount to add or subtract (use negative to subtract): ");
    scanf("%lf", &amount);

    records[id - 1].balance += amount;
    printf("The balance for %s has been updated to %.2lf.\n", records[id - 1].name, records[id - 1].balance);
}

void deleteRecord() {
    int id;

    printf("Enter the ID of the record you wish to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > record_count) {
        printf("The record cannot be found, Holmes.\n");
        return;
    }

    for (int i = id - 1; i < record_count - 1; i++) {
        records[i] = records[i + 1];
    }
    record_count--;
    printf("The record has been successfully deleted, Watson.\n");
}

void displayMenu() {
    printf("\n--- Sherlock Holmes' Banking Record System ---\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Find Record\n");
    printf("4. Update Balance\n");
    printf("5. Delete Record\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: findRecord(); break;
            case 4: updateBalance(); break;
            case 5: deleteRecord(); break;
            case 6:
                printf("Exiting the system, my dear Watson. Until next time!\n");
                return 0;
            default:
                printf("That option is as elusive as a phantom, my friend.\n");
        }
    }

    return 0;
}