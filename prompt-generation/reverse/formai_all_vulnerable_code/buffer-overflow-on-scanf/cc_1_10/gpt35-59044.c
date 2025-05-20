//FormAI DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    int account_number;
    float balance;
} banking_record;

void print_menu(){
    printf("Welcome to the Banking Record System\n\n");
    printf("1. Add a new record\n");
    printf("2. Delete a record\n");
    printf("3. Print all records\n");
    printf("4. Search for a record\n");
    printf("5. Update a record\n");
    printf("6. Exit\n\n");
    printf("Enter your choice (1-6): ");
}

void add_record(banking_record *records, int *num_records){
    printf("Enter the name: ");
    scanf("%s", records[*num_records].name);
    printf("Enter the account number: ");
    scanf("%d", &records[*num_records].account_number);
    printf("Enter the balance: ");
    scanf("%f", &records[*num_records].balance);
    
    (*num_records)++;
}

void delete_record(banking_record *records, int *num_records){
    int account_num, i, index = -1;

    printf("Enter the account number to delete: ");
    scanf("%d", &account_num);

    for(i=0; i<*num_records; i++){
        if(records[i].account_number == account_num){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Account not found\n");
    }
    else{
        for(i=index; i<*num_records-1; i++){
            strcpy(records[i].name, records[i+1].name);
            records[i].account_number = records[i+1].account_number;
            records[i].balance = records[i+1].balance;
        }
        (*num_records)--;
        printf("Record deleted successfully!\n");
    }
}

void print_all_records(banking_record *records, int num_records){
    int i;
    printf("Name\tAccount Number\tBalance\n");
    for(i=0; i<num_records; i++){
        printf("%s\t%d\t%.2f\n", records[i].name, records[i].account_number, records[i].balance);
    }
}

void search_record(banking_record *records, int num_records){
    int account_num, i, index = -1;

    printf("Enter the account number to search: ");
    scanf("%d", &account_num);

    for(i=0; i<num_records; i++){
        if(records[i].account_number == account_num){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Account not found\n");
    }
    else{
        printf("Name: %s\nAccount Number: %d\nBalance: %.2f\n", records[index].name, records[index].account_number, records[index].balance);
    }
}

void update_record(banking_record *records, int num_records){
    int account_num, i, index = -1;

    printf("Enter the account number to update: ");
    scanf("%d", &account_num);

    for(i=0; i<num_records; i++){
        if(records[i].account_number == account_num){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Account not found\n");
    }
    else{
        printf("Enter the new name: ");
        scanf("%s", records[index].name);
        printf("Enter the new balance: ");
        scanf("%f", &records[index].balance);
        printf("Record updated successfully!\n");
    }
}

int main(){
    banking_record records[100];
    int num_records = 0;
    int choice;

    do{
        print_menu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                delete_record(records, &num_records);
                break;
            case 3:
                print_all_records(records, num_records);
                break;
            case 4:
                search_record(records, num_records);
                break;
            case 5:
                update_record(records, num_records);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(1);

    return 0;
}