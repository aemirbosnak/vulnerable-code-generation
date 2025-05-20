//FormAI DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to hold the banking record data */
typedef struct BankRecord{
    char name[50];
    char account_number[15];
    double account_balance;
    int customer_id;
} BankRecord;

/* Function prototypes */
void menu();
void add_record();
void find_record();
void display_records();
void update_record();
void delete_record();

/* Global variables */
int num_records = 0;
BankRecord records[100];

int main(){
    menu();
    return 0;
}

/* Function to display the menu and handle user input */
void menu(){
    int choice;
    do{
        printf("\nWelcome to the C Banking Record System\n");
        printf("1. Add Record\n");
        printf("2. Find Record\n");
        printf("3. Display Records\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_record();
                break;
            case 2:
                find_record();
                break;
            case 3:
                display_records();
                break;
            case 4:
                update_record();
                break;
            case 5:
                delete_record();
                break;
            case 6:
                printf("\nThank you for using the C Banking Record System\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 6);
}

/* Function to add a new banking record */
void add_record(){
    BankRecord new_record;
    printf("\nAdding a new record...");

    printf("\nEnter name: ");
    scanf("%s", new_record.name);

    printf("Enter account number: ");
    scanf("%s", new_record.account_number);

    printf("Enter account balance: ");
    scanf("%lf", &new_record.account_balance);

    printf("Enter customer ID: ");
    scanf("%d", &new_record.customer_id);

    records[num_records++] = new_record;

    printf("\nRecord added successfully.\n");
}

/* Function to find a banking record */
void find_record(){
    int customer_id;
    printf("\nFinding a record...");

    printf("\nEnter customer ID: ");
    scanf("%d", &customer_id);

    for(int i = 0; i < num_records; i++){
        if(records[i].customer_id == customer_id){
            printf("\nRecord found:\n");
            printf("Name: %s\n", records[i].name);
            printf("Account Number: %s\n", records[i].account_number);
            printf("Account Balance: $%.2lf\n", records[i].account_balance);
        }
    }
}

/* Function to display all banking records */
void display_records(){
    printf("\nDisplaying all records...\n");

    for(int i = 0; i < num_records; i++){
        printf("\nRecord %d\n", i+1);
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %s\n", records[i].account_number);
        printf("Account Balance: $%.2lf\n", records[i].account_balance);
        printf("Customer ID: %d\n", records[i].customer_id);
    }
}

/* Function to update a banking record */
void update_record(){
    int customer_id;
    printf("\nUpdating a record...");

    printf("\nEnter customer ID: ");
    scanf("%d", &customer_id);

    for(int i = 0; i < num_records; i++){
        if(records[i].customer_id == customer_id){
            printf("\nRecord found:\n");
            printf("Name: %s\n", records[i].name);
            printf("Account Number: %s\n", records[i].account_number);
            printf("Account Balance: $%.2lf\n", records[i].account_balance);

            printf("\nEnter new account balance: ");
            scanf("%lf", &records[i].account_balance);

            printf("\nRecord updated successfully.\n");
            return;
        }
    }
    printf("\nRecord not found.\n");
}

/* Function to delete a banking record */
void delete_record(){
    int customer_id;
    printf("\nDeleting a record...");

    printf("\nEnter customer ID: ");
    scanf("%d", &customer_id);

    for(int i = 0; i < num_records; i++){
        if(records[i].customer_id == customer_id){
            printf("\nRecord found and deleted successfully.\n");
            for(int j = i; j < num_records-1; j++){
                records[j] = records[j+1];
            }
            num_records--;
            return;
        }
    }
    printf("\nRecord not found.\n");
}