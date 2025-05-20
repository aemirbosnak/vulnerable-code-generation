//FormAI DATASET v1.0 Category: Banking Record System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int account_no;
    char name[50];
    float balance;
} Record;

void add_record(Record records[], int *num_records);
void display_all_records(Record records[], int num_records);
void display_record(Record record);
void search_record(Record records[], int num_records);
void remove_record(Record records[], int *num_records);

int main(){
    int num_records = 0;
    Record records[100];
    int choice = 0;

    while(choice != 5){
        printf("\nWelcome to the Banking Record System\n");
        printf("Please choose an option:\n");
        printf("1. Add a new record\n");
        printf("2. Display all records\n");
        printf("3. Search for a record\n");
        printf("4. Remove a record\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                display_all_records(records, num_records);
                break;
            case 3:
                search_record(records, num_records);
                break;
            case 4:
                remove_record(records, &num_records);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void add_record(Record records[], int *num_records){
    Record new_record;
    printf("Enter account number: ");
    scanf("%d", &new_record.account_no);
    printf("Enter name: ");
    scanf("%s", &new_record.name);
    printf("Enter balance: ");
    scanf("%f", &new_record.balance);

    records[*num_records] = new_record;
    *num_records += 1;

    printf("Record added successfully!\n");
}

void display_all_records(Record records[], int num_records){
    int i;
    for(i = 0; i < num_records; i++){
        display_record(records[i]);
    }
}

void display_record(Record record){
    printf("Account number: %d\n", record.account_no);
    printf("Name: %s\n", record.name);
    printf("Balance: %.2f\n", record.balance);
}

void search_record(Record records[], int num_records){
    int search_account_no;
    printf("Enter account number to search for: ");
    scanf("%d", &search_account_no);

    int i;
    for(i = 0; i < num_records; i++){
        if(records[i].account_no == search_account_no){
            display_record(records[i]);
            return;
        }
    }

    printf("Record not found.\n");
}

void remove_record(Record records[], int *num_records){
    int remove_account_no;
    printf("Enter account number to remove: ");
    scanf("%d", &remove_account_no);

    int i;
    for(i = 0; i < *num_records; i++){
        if(records[i].account_no == remove_account_no){
            int j;
            for(j = i; j < *num_records - 1; j++){
                records[j] = records[j+1];
            }
            *num_records -= 1;
            printf("Record removed successfully!\n");
            return;
        }
    }

    printf("Record not found.\n");
}