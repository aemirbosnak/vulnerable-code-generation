//FormAI DATASET v1.0 Category: Banking Record System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for banking records
struct banking_record {
    int account_num;
    char name[50];
    float balance;
};

// Function to display menu options
void display_menu() {
    printf("\n\nWelcome to the ABC Bank\n");
    printf("1. Add Record\n");
    printf("2. View Records\n");
    printf("3. Search Record\n");
    printf("4. Update Record\n");
    printf("5. Delete Record\n");
    printf("6. Exit\n");
}

// Function to add new record
void add_record(struct banking_record *records, int *num_of_records) {
    printf("\nEnter account number: ");
    scanf("%d", &records[*num_of_records].account_num);
    printf("Enter name: ");
    scanf("%s", records[*num_of_records].name);
    printf("Enter balance: ");
    scanf("%f", &records[*num_of_records].balance);
    (*num_of_records)++;
    printf("\nRecord added successfully!\n");
}

// Function to view all records
void view_records(struct banking_record *records, int num_of_records) {
    printf("\n\nAccount Number\tName\t\tBalance\n");
    for (int i = 0; i < num_of_records; i++) {
        printf("%d\t\t%s\t\t%.2f\n", records[i].account_num, records[i].name, records[i].balance);
    }
}

// Function to search a record by account number
void search_record(struct banking_record *records, int num_of_records) {
    int account_num, found = 0;
    printf("\nEnter account number to search: ");
    scanf("%d", &account_num);
    for (int i = 0; i < num_of_records; i++) {
        if (records[i].account_num == account_num) {
            printf("\nAccount Number\tName\t\tBalance\n");
            printf("%d\t\t%s\t\t%.2f\n", records[i].account_num, records[i].name, records[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nRecord not found!\n");
    }
}

// Function to update a record
void update_record(struct banking_record *records, int num_of_records) {
    int account_num, found = 0;
    printf("\nEnter account number to update: ");
    scanf("%d", &account_num);
    for (int i = 0; i < num_of_records; i++) {
        if (records[i].account_num == account_num) {
            printf("\nEnter new name: ");
            scanf("%s", records[i].name);
            printf("Enter new balance: ");
            scanf("%f", &records[i].balance);
            found = 1;
            printf("\nRecord updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("\nRecord not found!\n");
    }
}

// Function to delete a record
void delete_record(struct banking_record *records, int *num_of_records) {
    int account_num, found = 0;
    printf("\nEnter account number to delete: ");
    scanf("%d", &account_num);
    for (int i = 0; i < (*num_of_records); i++) {
        if (records[i].account_num == account_num) {
            // Shift records up to overwrite the deleted record
            for (int j = i; j < (*num_of_records) - 1; j++) {
                records[j] = records[j+1];
            }
            (*num_of_records)--;
            found = 1;
            printf("\nRecord deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("\nRecord not found!\n");
    }
}

// Main function
int main() {
    struct banking_record records[100];
    int num_of_records = 0, choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_record(records, &num_of_records);
                break;
            case 2:
                view_records(records, num_of_records);
                break;
            case 3:
                search_record(records, num_of_records);
                break;
            case 4:
                update_record(records, num_of_records);
                break;
            case 5:
                delete_record(records, &num_of_records);
                break;
            case 6:
                printf("\nThank you for using ABC bank!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}