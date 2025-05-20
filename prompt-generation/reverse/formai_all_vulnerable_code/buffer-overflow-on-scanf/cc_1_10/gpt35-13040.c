//FormAI DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store banking record details
struct banking_record {
    char name[50];
    int account_number;
    float balance;
};

// Function to add a new record to the system
void add_record(struct banking_record *records, int num_records) {
    printf("\nEnter details for the new record:\n");
    printf("Name: ");
    scanf("%s", records[num_records].name);
    printf("Account Number: ");
    scanf("%d", &records[num_records].account_number);
    printf("Balance: ");
    scanf("%f", &records[num_records].balance);
    printf("Record added successfully!\n");
}

// Function to search for a record in the system
void search_record(struct banking_record *records, int num_records) {
    int account_number;
    printf("\nEnter Account Number to search for: ");
    scanf("%d", &account_number);
    int i;
    for (i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            printf("Record Found!\nName: %s\nBalance: %f\n", records[i].name, records[i].balance);
            return;
        }
    }
    printf("Record Not Found!\n");
}

// Function to delete a record from the system
void delete_record(struct banking_record *records, int num_records) {
    int account_number;
    printf("\nEnter Account Number to delete: ");
    scanf("%d", &account_number);
    int i;
    for (i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            int j;
            for(j = i; j < num_records - 1; j++) {
                records[j] = records[j + 1];
            }
            printf("Record Deleted Successfully!\n");
            return;
        }
    }
    printf("Record Not Found!\n");
}

// Function to print all records in the system
void print_records(struct banking_record *records, int num_records) {
    printf("\nPrinting All Records...\n");
    int i;
    for (i = 0; i < num_records; i++) {
        printf("Name: %s | Account Number: %d | Balance: %f\n", records[i].name, records[i].account_number, records[i].balance);
    }
}

// Main function
int main() {
    int num_records = 0;
    struct banking_record records[100];
    int option;
    do {
        printf("\nWelcome to the Banking Record System!\n");
        printf("1. Add a Record\n");
        printf("2. Search for a Record\n");
        printf("3. Delete a Record\n");
        printf("4. Print All Records\n");
        printf("5. Exit\n");
        printf("Select an Option (1-5): ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_record(records, num_records);
                num_records++;
                break;
            case 2:
                search_record(records, num_records);
                break;
            case 3:
                delete_record(records, num_records);
                num_records--;
                break;
            case 4:
                print_records(records, num_records);
                break;
            case 5:
                printf("\nThank you for using the Banking Record System!\n");
                break;
            default:
                printf("\nInvalid Option Selected!\n");
                break;
        }
    } while(option != 5);
    return 0;
}