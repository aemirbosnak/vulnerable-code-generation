//FormAI DATASET v1.0 Category: Banking Record System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store banking record data
struct banking_record {
    char name[20];
    char account_type[10];
    float balance;
};

// Function to add new record to array of banking records
void add_record(struct banking_record records[], int *num_records) {
    char name[20];
    char account_type[10];
    float balance;
    
    printf("Enter Account Holder's Name: ");
    scanf("%s", name);
    printf("Enter Account Type: ");
    scanf("%s", account_type);
    printf("Enter Account Balance: ");
    scanf("%f", &balance);
    
    // Create new record with user input and add to array of records
    struct banking_record new_record = {0};
    strcpy(new_record.name, name);
    strcpy(new_record.account_type, account_type);
    new_record.balance = balance;
    records[*num_records] = new_record;
    
    // Increment number of records
    *num_records += 1;
    
    printf("Record added successfully!\n\n");
}

// Function to display all current banking records
void display_records(struct banking_record records[], int num_records) {
    printf("Banking Records:\n\n");
    
    for (int i = 0; i < num_records; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Account Type: %s\n", records[i].account_type);
        printf("Balance: %.2f\n\n", records[i].balance);
    }
}

// Function to display menu of options to user
void display_menu() {
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Exit\n");
}

int main() {
    // Declare array of banking records and current number of records
    struct banking_record records[100] = {0};
    int num_records = 0;
    
    // Display menu and get user input until they choose to exit
    int choice = 0;
    while (choice != 3) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                display_records(records, num_records);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n\n");
                break;
        }
    }
    
    return 0;
}