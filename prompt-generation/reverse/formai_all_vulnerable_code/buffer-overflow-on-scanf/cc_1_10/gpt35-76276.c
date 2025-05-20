//FormAI DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100 // Maximum size for customer records

// Structure for customer record
struct customerRecord {
    char name[50];
    char accountNumber[20];
    float balance;
};

// Function to display main menu
void displayMenu() {
    printf("Main Menu\n");
    printf("1. Add a new customer record\n");
    printf("2. Display all customer records\n");
    printf("3. Search for a customer record\n");
    printf("4. Exit the program\n");
}

// Function to add a new customer record
void addRecord(struct customerRecord records[], int *count) {
    printf("Enter the customer name: ");
    scanf("%s", records[*count].name);
    printf("Enter the customer account number: ");
    scanf("%s", records[*count].accountNumber);
    printf("Enter the customer balance: ");
    scanf("%f", &records[*count].balance);
    *count += 1;
}

// Function to display all customer records
void displayRecords(struct customerRecord records[], int count) {
    printf("Customer Records\n");
    printf("Name\t\tAccount Number\t\tBalance\n");
    for(int i=0;i<count;i++) {
        printf("%s\t\t%s\t\t%.2f\n", records[i].name, records[i].accountNumber, records[i].balance);
    }
}

// Function to search for a customer record
void searchRecord(struct customerRecord records[], int count) {
    char accountNumber[20];
    int found = 0;
    printf("Enter the account number to search for: ");
    scanf("%s", accountNumber);
    for(int i=0;i<count;i++) {
        if(strcmp(records[i].accountNumber, accountNumber) == 0) {
            printf("Customer Record Found\n");
            printf("Name: %s\n", records[i].name);
            printf("Account Number: %s\n", records[i].accountNumber);
            printf("Balance: %.2f\n", records[i].balance);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Customer Record Not Found\n");
    }
}

int main() {
    struct customerRecord records[SIZE];
    int count=0, choice;
    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                displayRecords(records, count);
                break;
            case 3:
                searchRecord(records, count);
                break;
            case 4:
                printf("Exiting the program\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again\n");
                break;
        }
    }
    return 0;
}