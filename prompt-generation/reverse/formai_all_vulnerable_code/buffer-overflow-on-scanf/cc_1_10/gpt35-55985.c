//FormAI DATASET v1.0 Category: Banking Record System ; Style: careful
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

struct BankRecord {
    char name[50];
    char address[100];
    long int account_number;
    float balance;
};

void print_menu() {
    printf("\n--- BANKING RECORD SYSTEM ---\n");
    printf("1 - Add new record\n");
    printf("2 - Display all records\n");
    printf("3 - Search record\n");
    printf("4 - Update record\n");
    printf("5 - Delete record\n");
    printf("6 - Exit\n");
}

void add_record(struct BankRecord* records, int* count) {
    if (*count < MAX_RECORDS) {
        struct BankRecord new_record;
        printf("Enter name: ");
        fgets(new_record.name, sizeof(new_record.name), stdin);
        printf("Enter address: ");
        fgets(new_record.address, sizeof(new_record.address), stdin);
        printf("Enter account number: ");
        scanf("%ld", &new_record.account_number);
        printf("Enter balance: ");
        scanf("%f", &new_record.balance);
        getchar(); // consume '\n' character left by scanf
        records[*count] = new_record;
        *count += 1;
        printf("Record added successfully!\n");
    }
    else {
        printf("Error: Maximum number of records reached.\n");
    }
}

void display_all_records(struct BankRecord* records, int count) {
    if (count > 0) {
        printf("\n--- All Records ---\n");
        for (int i = 0; i < count; i++) {
            printf("Name: %s", records[i].name);
            printf("Address: %s", records[i].address);
            printf("Account Number: %ld\n", records[i].account_number);
            printf("Balance: %.2f\n", records[i].balance);
            printf("----------------------------\n");
        }
    }
    else {
        printf("No records found.\n");
    }
}

void search_record(struct BankRecord* records, int count) {
    if (count > 0) {
        long int search_account_number;
        printf("Enter account number to search: ");
        scanf("%ld", &search_account_number);
        getchar(); // consume '\n' character left by scanf
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (records[i].account_number == search_account_number) {
                printf("Name: %s", records[i].name);
                printf("Address: %s", records[i].address);
                printf("Account Number: %ld\n", records[i].account_number);
                printf("Balance: %.2f\n", records[i].balance);
                printf("----------------------------\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Record not found.\n");
        }
    }
    else {
        printf("No records found.\n");
    }
}

void update_record(struct BankRecord* records, int count) {
    if (count > 0) {
        long int update_account_number;
        printf("Enter account number to update: ");
        scanf("%ld", &update_account_number);
        getchar(); // consume '\n' character left by scanf
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (records[i].account_number == update_account_number) {
                printf("Current name: %s", records[i].name);
                printf("Enter new name (or press enter to keep current name): ");
                fgets(records[i].name, sizeof(records[i].name), stdin);
                printf("Current address: %s", records[i].address);
                printf("Enter new address (or press enter to keep current address): ");
                fgets(records[i].address, sizeof(records[i].address), stdin);
                printf("Current balance: %.2f\n", records[i].balance);
                printf("Enter new balance (or press enter to keep current balance): ");
                char input[100];
                fgets(input, sizeof(input), stdin);
                if (strcmp(input, "\n") != 0) {
                    sscanf(input, "%f", &records[i].balance);
                }
                found = 1;
                printf("Record updated successfully!\n");
                break;
            }
        }
        if (!found) {
            printf("Record not found.\n");
        }
    }
    else {
        printf("No records found.\n");
    }
}

void delete_record(struct BankRecord* records, int* count) {
    if (*count > 0) {
        long int delete_account_number;
        printf("Enter account number to delete: ");
        scanf("%ld", &delete_account_number);
        getchar(); // consume '\n' character left by scanf
        int found = 0;
        for (int i = 0; i < *count; i++) {
            if (records[i].account_number == delete_account_number) {
                for (int j = i; j < *count-1; j++) {
                    records[j] = records[j+1];
                }
                *count -= 1;
                found = 1;
                printf("Record deleted successfully!\n");
                break;
            }
        }
        if (!found) {
            printf("Record not found.\n");
        }
    }
    else {
        printf("No records found.\n");
    }
}

int main() {
    struct BankRecord records[MAX_RECORDS]; // array to hold all records
    int count = 0; // number of records currently in the array
    
    while (1) {
        print_menu();
        
        int choice;
        scanf("%d", &choice);
        getchar(); // consume '\n' character left by scanf
        
        switch (choice) {
            case 1:
                add_record(records, &count);
                break;
                
            case 2:
                display_all_records(records, count);
                break;
                
            case 3:
                search_record(records, count);
                break;
                
            case 4:
                update_record(records, count);
                break;
                
            case 5:
                delete_record(records, &count);
                break;
                
            case 6:
                printf("\nExiting program...\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}