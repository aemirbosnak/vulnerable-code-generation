//FormAI DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void addNewRecord();
void viewAllRecords();
void searchRecord();
void modifyRecord();
void deleteRecord();

// Structure for bank records
struct BankRecord {
    int accountNumber;
    char name[50];
    float balance;
};

int main() {
    int choice;
    do {
        printf("=== BANK RECORD SYSTEM ===\n");
        printf("1. Add new record\n");
        printf("2. View all records\n");
        printf("3. Search record\n");
        printf("4. Modify record\n");
        printf("5. Delete record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewRecord();
                break;
            case 2:
                viewAllRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                modifyRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addNewRecord() {
    printf("=== ADD NEW RECORD ===\n");

    // Open bank record file in append mode
    FILE* file = fopen("bank_records.dat", "ab");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Create new bank record
    struct BankRecord newRecord;

    // Get account number from user
    printf("Enter account number: ");
    scanf("%d", &newRecord.accountNumber);

    // Get name from user (with spaces)
    printf("Enter name: ");
    getchar(); // consume newline character
    fgets(newRecord.name, sizeof(newRecord.name), stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = 0; // remove trailing newline character

    // Get balance from user
    printf("Enter balance: ");
    scanf("%f", &newRecord.balance);

    // Write new record to file
    fwrite(&newRecord, sizeof(newRecord), 1, file);

    // Close file
    fclose(file);

    // Print success message
    printf("Record added successfully!\n\n");
}

void viewAllRecords() {
    printf("=== VIEW ALL RECORDS ===\n");

    // Open bank record file in read mode
    FILE* file = fopen("bank_records.dat", "rb");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Print table header
    printf("Account Number\tName\t\tBalance\n");

    // Read records from file and print them in table format
    struct BankRecord record;
    while (fread(&record, sizeof(record), 1, file) == 1) {
        printf("%d\t\t%s\t\t%.2f\n", record.accountNumber, record.name, record.balance);
    }

    // Close file
    fclose(file);

    printf("\n");
}

void searchRecord() {
    printf("=== SEARCH RECORD ===\n");

    // Open bank record file in read mode
    FILE* file = fopen("bank_records.dat", "rb");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get account number to search for from user
    int accountNumber;
    printf("Enter account number to search for: ");
    scanf("%d", &accountNumber);

    // Read records from file and search for matching account number
    struct BankRecord record;
    int found = 0;
    while (fread(&record, sizeof(record), 1, file) == 1) {
        if (record.accountNumber == accountNumber) {
            printf("Account Number\tName\t\tBalance\n");
            printf("%d\t\t%s\t\t%.2f\n", record.accountNumber, record.name, record.balance);
            found = 1;
            break;
        }
    }

    // Close file
    fclose(file);

    if (!found) {
        printf("Record with account number %d not found.\n", accountNumber);
    }

    printf("\n");
}

void modifyRecord() {
    printf("=== MODIFY RECORD ===\n");

    // Open bank record file in read-write mode
    FILE* file = fopen("bank_records.dat", "rb+");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get account number to modify from user
    int accountNumber;
    printf("Enter account number to modify: ");
    scanf("%d", &accountNumber);

    // Read records from file and search for matching account number
    struct BankRecord record;
    int found = 0;
    while (fread(&record, sizeof(record), 1, file) == 1) {
        if (record.accountNumber == accountNumber) {
            printf("Account Number\tName\t\tBalance\n");
            printf("%d\t\t%s\t\t%.2f\n", record.accountNumber, record.name, record.balance);

            // Get new name from user (with spaces)
            printf("Enter new name: ");
            getchar(); // consume newline character
            fgets(record.name, sizeof(record.name), stdin);
            record.name[strcspn(record.name, "\n")] = 0; // remove trailing newline character

            // Get new balance from user
            printf("Enter new balance: ");
            scanf("%f", &record.balance);

            // Move file pointer to beginning of record to modify
            fseek(file, -sizeof(record), SEEK_CUR);

            // Write modified record to file
            fwrite(&record, sizeof(record), 1, file);

            found = 1;
            break;
        }
    }

    // Close file
    fclose(file);

    if (!found) {
        printf("Record with account number %d not found.\n", accountNumber);
    } else {
        printf("Record modified successfully!\n");
    }

    printf("\n");
}

void deleteRecord() {
    printf("=== DELETE RECORD ===\n");

    // Open bank record file in read-write mode
    FILE* file = fopen("bank_records.dat", "rb+");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get account number to delete from user
    int accountNumber;
    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);

    // Read records from file and search for matching account number
    struct BankRecord record;
    int found = 0;
    while (fread(&record, sizeof(record), 1, file) == 1) {
        if (record.accountNumber == accountNumber) {
            printf("Account Number\tName\t\tBalance\n");
            printf("%d\t\t%s\t\t%.2f\n", record.accountNumber, record.name, record.balance);

            // Move file pointer to beginning of record to delete
            fseek(file, -sizeof(record), SEEK_CUR);

            // Overwrite record with zeros to mark it as deleted
            memset(&record, 0, sizeof(record));
            fwrite(&record, sizeof(record), 1, file);

            found = 1;
            break;
        }
    }

    // Close file
    fclose(file);

    if (!found) {
        printf("Record with account number %d not found.\n", accountNumber);
    } else {
        printf("Record deleted successfully!\n");
    }

    printf("\n");
}