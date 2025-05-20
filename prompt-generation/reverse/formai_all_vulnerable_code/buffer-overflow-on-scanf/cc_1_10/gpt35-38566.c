//FormAI DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records can be stored

typedef struct {
    int account_no;
    char name[20];
    float balance;
} Banking_Record;

Banking_Record records[MAX_RECORDS]; // Array of Banking_Record structures
int num_records = 0; // Number of records currently stored

// Print the main menu
void print_menu() {
    printf("=============================\n");
    printf("  C Banking Record System\n");
    printf("=============================\n");
    printf("1. Add a new record\n");
    printf("2. View all records\n");
    printf("3. Search for a record\n");
    printf("4. Update a record\n");
    printf("5. Delete a record\n");
    printf("6. Exit\n");
}

// Add a new record
void add_record() {
    if(num_records == MAX_RECORDS){
        printf("Sorry! Maximum number of banking records reached.");
        return;
    }
    
    Banking_Record record;
    printf("Enter Account Number: ");
    scanf("%d", &record.account_no);
    printf("Enter Name: ");
    scanf("%s", record.name);
    printf("Enter Balance: ");
    scanf("%f", &record.balance);
    
    records[num_records++] = record;
    printf("Record added successfully.\n");
}

// View all records
void view_records() {
    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }
    
    printf("%-15s %-20s  %-10s\n", "Account No.", "Name", "Balance");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < num_records; i++) {
        printf("%-15d %-20s  %-10.2f\n", records[i].account_no, records[i].name, records[i].balance);
    }
}

// Search for a record
void search_record() {
    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }
    
    int account_no;
    printf("Enter Account Number: ");
    scanf("%d", &account_no);
    
    for (int i = 0; i < num_records; i++) {
        if (records[i].account_no == account_no) {
            printf("%-15s %-20s  %-10s\n", "Account No.", "Name", "Balance");
            printf("-----------------------------------------------------\n");
            printf("%-15d %-20s  %-10.2f\n", records[i].account_no, records[i].name, records[i].balance);
            return;
        }
    }
    printf("Record not found.\n");
}

// Update a record
void update_record() {
    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }
    
    int account_no;
    printf("Enter Account Number: ");
    scanf("%d", &account_no);
    
    for (int i = 0; i < num_records; i++) {
        if (records[i].account_no == account_no) {
            printf("Enter new Name (leave empty to skip): ");
            scanf("%s", records[i].name);
            printf("Enter new Balance (leave 0 to skip): ");
            scanf("%f", &records[i].balance);
            printf("Record updated successfully.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

// Delete a record
void delete_record() {
    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }
    
    int account_no;
    printf("Enter Account Number: ");
    scanf("%d", &account_no);
    
    for (int i = 0; i < num_records; i++) {
        if (records[i].account_no == account_no) {
            // Delete the record by shifting all records after it to the left
            num_records--;
            for (int j = i; j < num_records; j++) {
                records[j] = records[j+1];
            }
            printf("Record deleted successfully.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

int main() {
    int option;
    while (1) {
        print_menu();
        printf("Enter option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                add_record();
                break;
            case 2:
                view_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                update_record();
                break;
            case 5:
                delete_record();
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}