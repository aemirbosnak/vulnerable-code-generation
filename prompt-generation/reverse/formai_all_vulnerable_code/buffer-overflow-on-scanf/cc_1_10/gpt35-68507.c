//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store bank record data
struct BankRecord {
    char name[50];
    int account_no;
    float balance;
};

// Function to display menu and return user choice
int displayMenu() {
    int choice;
    printf("\n1. Add new record\n2. Display all records\n3. Search record\n4. Update record\n5. Delete record\n6. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add new bank record
void addRecord(struct BankRecord **records, int *count) {
    int i = *count;
    *records = realloc(*records, (*count + 1) * sizeof(struct BankRecord));
    printf("\nEnter name: ");
    scanf("%s", (*records)[i].name);
    printf("Enter account number: ");
    scanf("%d", &(*records)[i].account_no);
    printf("Enter balance: ");
    scanf("%f", &(*records)[i].balance);
    *count += 1;
    printf("\nRecord added successfully!\n");
}

// Function to display all bank records
void displayRecords(struct BankRecord *records, int count) {
    printf("\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\tAccount Number: %d\tBalance: %.2f\n", records[i].name, records[i].account_no, records[i].balance);
    }
}

// Function to search bank record by account number
void searchRecord(struct BankRecord *records, int count) {
    int account_no;
    printf("\nEnter account number to search: ");
    scanf("%d", &account_no);
    for (int i = 0; i < count; i++) {
        if (records[i].account_no == account_no) {
            printf("Name: %s\tAccount Number: %d\tBalance: %.2f\n", records[i].name, records[i].account_no, records[i].balance);
            return;
        }
    }
    printf("Record not found!\n");
}

// Function to update bank record by account number
void updateRecord(struct BankRecord *records, int count) {
    int account_no;
    printf("\nEnter account number to update: ");
    scanf("%d", &account_no);
    for (int i = 0; i < count; i++) {
        if (records[i].account_no == account_no) {
            printf("Enter new name: ");
            scanf("%s", records[i].name);
            printf("Enter new balance: ");
            scanf("%f", &records[i].balance);
            printf("\nRecord updated successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

// Function to delete bank record by account number
void deleteRecord(struct BankRecord **records, int *count) {
    int account_no, del_index = -1;
    printf("\nEnter account number to delete: ");
    scanf("%d", &account_no);
    for (int i = 0; i < *count; i++) {
        if ((*records)[i].account_no == account_no) {
            del_index = i;
            break;
        }
    }
    if (del_index == -1) {
        printf("Record not found!\n");
        return;
    }
    for (int i = del_index; i < *count; i++) {
        (*records)[i] = (*records)[i+1];
    }
    *records = realloc(*records, (*count - 1) * sizeof(struct BankRecord));
    *count -= 1;
    printf("\nRecord deleted successfully!\n");
}

int main() {
    struct BankRecord *records = NULL;
    int count = 0, choice;
    while (1) {
        choice = displayMenu();
        switch(choice) {
            case 1:
                addRecord(&records, &count);
                break;
            case 2:
                displayRecords(records, count);
                break;
            case 3:
                searchRecord(records, count);
                break;
            case 4:
                updateRecord(records, count);
                break;
            case 5:
                deleteRecord(&records, &count);
                break;
            case 6:
                free(records);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}