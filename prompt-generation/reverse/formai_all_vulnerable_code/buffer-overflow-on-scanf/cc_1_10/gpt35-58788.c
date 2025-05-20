//FormAI DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define banking record struct
typedef struct {
    char name[50];
    int account_number;
    float balance;
} banking_record;

// Define function to add record to file
void add_record(FILE *file, banking_record *record) {
    // Write record to file
    fwrite(record, sizeof(banking_record), 1, file);
    printf("Record added successfully!\n");
}

// Define function to print all records from file
void print_records(FILE *file) {
    // Reset file pointer to beginning
    fseek(file, 0, SEEK_SET);
    
    // Declare record variable
    banking_record record;
    
    // Print header
    printf("Banking Records:\n");
    printf("Name\tAccount Number\tBalance\n");
    printf("--------------------------------------\n");
    
    // Loop through each record in file and print
    while (fread(&record, sizeof(banking_record), 1, file)) {
        printf("%s\t%d\t\t%.2f\n", record.name, record.account_number, record.balance);
    }
}

// Define function to search for record by account number
void search_for_record(FILE *file, int account_number) {
    // Reset file pointer to beginning
    fseek(file, 0, SEEK_SET);
    
    // Declare record variable
    banking_record record;
    
    // Loop through each record in file and search for matching account number
    while (fread(&record, sizeof(banking_record), 1, file)) {
        if (record.account_number == account_number) {
            printf("Record found:\n");
            printf("Name: %s\nAccount Number: %d\nBalance: %.2f\n", record.name, record.account_number, record.balance);
            return;
        }
    }
    // If no matching record is found, print error message
    printf("Error: Record with account number %d not found.\n", account_number);
}

// Main function begins
int main() {
    printf("Welcome to the Banking Record System.\n");
    printf("How can I help you?\n");
    
    // Declare file variable and open file
    FILE *bank_file = fopen("banking_records.dat", "rb+");
    if (bank_file == NULL) {
        printf("Error: Could not open file.");
        return 1;
    }
    
    // Declare variables for user input
    char option;
    banking_record new_record;
    int account_number;
    
    // Loop to prompt user for input until they choose to exit
    do {
        // Print menu options
        printf("\nMenu Options:\n");
        printf("1. Add new record\n");
        printf("2. Print all records\n");
        printf("3. Search for record by account number\n");
        printf("4. Exit\n");
        printf("Please enter an option (1-4): ");
        
        // Get user input
        scanf(" %c", &option);
        
        // Determine which option was chosen and call appropriate function
        switch(option) {
            case '1':
                printf("Enter name: ");
                scanf("%s", new_record.name);
                printf("Enter account number: ");
                scanf("%d", &new_record.account_number);
                printf("Enter balance: ");
                scanf("%f", &new_record.balance);
                add_record(bank_file, &new_record);
                break;
            case '2':
                print_records(bank_file);
                break;
            case '3':
                printf("Enter account number to search for: ");
                scanf("%d", &account_number);
                search_for_record(bank_file, account_number);
                break;
            case '4':
                printf("Exiting Banking Record System...\n");
                break;
            default:
                printf("Error: Invalid option selected. Please choose 1-4.\n");
                break;
        }
    } while (option != '4');
    
    // Close file
    fclose(bank_file);
    
    return 0;
}