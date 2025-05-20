//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct bank_record{
    char name[20];
    int account_number;
    double balance;
    char bank[20];
};

struct bank_record bank_records[20];
int bank_records_count = 0;

int main(){
    srand(time(0));
    char name[20];
    char bank[20];
    int account_number;
    double balance;
    
    printf("Welcome to the Banking Record System\n");
    
    while(1){
        printf("1. Create New Record\n2. View Records\n3. Update Record\n4. Delete Record\n5. Exit\n");
        int choice;
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("Please enter the following details for a new record:\n");
                printf("Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                strncpy(bank_records[bank_records_count].name, name, 20);
                printf("Account Number: ");
                scanf("%d",&account_number);
                bank_records[bank_records_count].account_number = account_number;
                printf("Balance: ");
                scanf("%lf",&balance);
                bank_records[bank_records_count].balance = balance;
                printf("Bank Name: ");
                fgets(bank, sizeof(bank), stdin);
                bank[strcspn(bank, "\n")] = 0;
                strncpy(bank_records[bank_records_count].bank, bank, 20);
                bank_records_count++;
                break;
            case 2:
                printf("List of Bank Records:\n");
                for(int i=0; i<bank_records_count; i++){
                    printf("Record %d: %s | %d | %lf | %s\n", i+1, bank_records[i].name, bank_records[i].account_number, bank_records[i].balance, bank_records[i].bank);
                }
                break;
            case 3:
                printf("Please enter the following details for the record to be updated:\n");
                printf("Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                strncpy(bank_records[bank_records_count].name, name, 20);
                printf("Account Number: ");
                scanf("%d",&account_number);
                bank_records[account_number].account_number = account_number;
                printf("Balance: ");
                scanf("%lf",&balance);
                bank_records[account_number].balance = balance;
                printf("Bank Name: ");
                fgets(bank, sizeof(bank), stdin);
                bank[strcspn(bank, "\n")] = 0;
                strncpy(bank_records[account_number].bank, bank, 20);
                break;
            case 4:
                printf("Please enter the following details of the record to be deleted:\n");
                printf("Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                strncpy(bank_records[bank_records_count].name, name, 20);
                printf("Account Number: ");
                scanf("%d",&account_number);
                bank_records[account_number].account_number = account_number;
                bank_records_count--;
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
        }
    }
    return 0;
}