//FormAI DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

#define DATABASE_CAPACITY 100 // capacity of banking record system database

// structure of banking record
typedef struct{
    int account_number; // unique account number of customer
    char name[50]; // name of customer
    char address[100]; // address of customer
    char phone_number[20]; // phone number of customer
    float balance; // balance in customer's account
} banking_record;

banking_record database[DATABASE_CAPACITY]; // banking record system database

int num_records = 0; // number of records in the database

// function to add a new banking record to the database
void add_record(){
    if(num_records==DATABASE_CAPACITY){
        printf("\nDatabase full. Cannot add any more records.\n");
        return;
    }
    banking_record new_record;
    printf("\nEnter account number: ");
    scanf("%d",&new_record.account_number);
    printf("Enter name: ");
    fflush(stdin);
    gets(new_record.name);
    printf("Enter address: ");
    fflush(stdin);
    gets(new_record.address);
    printf("Enter phone number: ");
    fflush(stdin);
    gets(new_record.phone_number);
    printf("Enter balance: ");
    scanf("%f",&new_record.balance);
    database[num_records++] = new_record;
    printf("\nRecord added to the database.\n");
}

// function to display all banking records stored in the database
void display_all_records(){
    if(num_records==0){
        printf("\nNo records to display.\n");
        return;
    }
    printf("\n");
    printf("%-20s %-50s %-100s %-20s %-10s\n","Account Number","Name","Address","Phone Number","Balance");
    for(int i=0;i<num_records;i++){
        printf("%-20d %-50s %-100s %-20s %-10.2f\n",
               database[i].account_number,database[i].name,database[i].address,
               database[i].phone_number,database[i].balance);
    }
}

// function to search for a banking record by account number
void search_by_account_number(){
    if(num_records==0){
        printf("\nNo records to search.\n");
        return;
    }
    int account_number;
    printf("\nEnter account number to search for: ");
    scanf("%d",&account_number);
    for(int i=0;i<num_records;i++){
        if(database[i].account_number==account_number){
            printf("\nRecord found with the following details:\n");
            printf("%-20s %-50s %-100s %-20s %-10s\n","Account Number","Name","Address","Phone Number","Balance");
            printf("%-20d %-50s %-100s %-20s %-10.2f\n",
                   database[i].account_number,database[i].name,database[i].address,
                   database[i].phone_number,database[i].balance);
            return;
        }
    }
    printf("\nRecord not found.\n");
}

// function to update a banking record by account number
void update_by_account_number(){
    if(num_records==0){
        printf("\nNo records to update.\n");
        return;
    }
    int account_number;
    printf("\nEnter account number to update: ");
    scanf("%d",&account_number);
    for(int i=0;i<num_records;i++){
        if(database[i].account_number==account_number){
            printf("\nEnter new name: ");
            fflush(stdin);
            gets(database[i].name);
            printf("Enter new address: ");
            fflush(stdin);
            gets(database[i].address);
            printf("Enter new phone number: ");
            fflush(stdin);
            gets(database[i].phone_number);
            printf("Enter new balance: ");
            scanf("%f",&database[i].balance);
            printf("\nRecord updated successfully.\n");
            return;
        }
    }
    printf("\nRecord not found.\n");
}

// function to delete a banking record by account number
void delete_by_account_number(){
    if(num_records==0){
        printf("\nNo records to delete.\n");
        return;
    }
    int account_number;
    printf("\nEnter account number to delete: ");
    scanf("%d",&account_number);
    for(int i=0;i<num_records;i++){
        if(database[i].account_number==account_number){
            for(int j=i;j<num_records-1;j++){
                database[j] = database[j+1];
            }
            num_records--;
            printf("\nRecord deleted successfully.\n");
            return;
        }
    }
    printf("\nRecord not found.\n");
}

// main function of the program
int main(){
    int choice;
    do{
        printf("\n----Banking Record System----\n");
        printf("1. Add new record\n");
        printf("2. Display all records\n");
        printf("3. Search by account number\n");
        printf("4. Update by account number\n");
        printf("5. Delete by account number\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_record();
                    break;
            case 2: display_all_records();
                    break;
            case 3: search_by_account_number();
                    break;
            case 4: update_by_account_number();
                    break;
            case 5: delete_by_account_number();
                    break;
            case 6: printf("Exiting program.\n");
                    exit(0);
            default: printf("Invalid choice. Try again.\n");
                     break;
        }
    }while(1);
    return 0;
}