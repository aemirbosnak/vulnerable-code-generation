//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bank_record {
    char name[50];
    int age;
    int account_number;
    double balance;
};

// Global Variables for Program
struct bank_record bank_data[100];
int num_of_records = 0;

// Function to Add Records into the Bank Record System
void add_record() {
    struct bank_record record;
    printf("\nEnter Name: ");
    scanf("%s", &record.name);
    printf("Enter Age: ");
    scanf("%d", &record.age);
    printf("Enter Account Number: ");
    scanf("%d", &record.account_number);
    printf("Enter Balance: ");
    scanf("%lf", &record.balance);
    bank_data[num_of_records++] = record;
    printf("\nRecord Added Successfully!\n");
}

// Function to Display All Records in the Bank Record System
void display_records() {
    printf("\n\nBank Record System\n");
    printf("--------------------\n");
    printf("Name\t\tAge\tAccount Number\t\tBalance\n");
    printf("---------------------------------------------------------\n");
    for(int i=0; i<num_of_records; i++) {
        printf("%s\t", bank_data[i].name);
        printf("%d\t", bank_data[i].age);
        printf("%d\t\t\t", bank_data[i].account_number);
        printf("%.2f\n", bank_data[i].balance);
    }
    printf("\n\n");
}

// Function to Search a Record in the Bank Record System
void search_record() {
    int account_number;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    for(int i=0; i<num_of_records; i++) {
        if(bank_data[i].account_number == account_number) {
            printf("\nRecord Found!\n");
            printf("Name: %s\n", bank_data[i].name);
            printf("Age: %d\n", bank_data[i].age);
            printf("Account Number: %d\n", bank_data[i].account_number);
            printf("Balance: %.2f\n", bank_data[i].balance);
            return;
        }
    }
    printf("\nRecord Not Found!\n");
}

// Function to Update a Record in the Bank Record System
void update_record() {
    int account_number;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    for(int i=0; i<num_of_records; i++) {
        if(bank_data[i].account_number == account_number) {
            printf("\nRecord Found!\n");
            struct bank_record record = bank_data[i];
            printf("Enter Name [%s]: ", record.name);
            scanf("%s", &record.name);
            printf("Enter Age [%d]: ", record.age);
            scanf("%d", &record.age);
            printf("Enter Account Number [%d]: ", record.account_number);
            scanf("%d", &record.account_number);
            printf("Enter Balance [%.2f]: ", record.balance);
            scanf("%lf", &record.balance);
            bank_data[i] = record;
            printf("\nRecord Updated Successfully!\n");
            return;
        }
    }
    printf("\nRecord Not Found!\n");
}

// Function to Delete a Record from the Bank Record System
void delete_record() {
    int account_number;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    for(int i=0; i<num_of_records; i++) {
        if(bank_data[i].account_number == account_number) {
            printf("\nRecord Found!\n");
            for(int j=i; j<num_of_records-1; j++) {
                bank_data[j] = bank_data[j+1];
            }
            num_of_records--;
            printf("\nRecord Deleted Successfully!\n");
            return;
        }
    }
    printf("\nRecord Not Found!\n");
}

// Main Function
int main() {
    int option;
    do {
        printf("\nBank Record System\n");
        printf("--------------------\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");
        printf("Enter Your Option [1-6]: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
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
                printf("\nThank You For Using Bank Record System!\n");
                break;
            default:
                printf("\nInvalid Option! Please Try Again.\n");
        }
    } while(option != 6);
    return 0;
}