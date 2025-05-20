//FormAI DATASET v1.0 Category: Banking Record System ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure Declaration for Banking Records
struct BankingRecord{
    int accountNumber;
    char name[50];
    float balance;
};

// Function to add new Banking Record
void AddRecord(struct BankingRecord *bank_records, int *num_records){
    printf("\n----- Add Record -----");
    printf("\nEnter Account Number: ");
    scanf("%d", &bank_records[*num_records].accountNumber);
    printf("Enter Name: ");
    scanf("%s", bank_records[*num_records].name);
    printf("Enter Balance: ");
    scanf("%f", &bank_records[*num_records].balance);
    (*num_records)++;
    printf("\nRecord Added Successfully");
}

// Function to view Banking Records
void ViewRecords(struct BankingRecord *bank_records, int num_records){
    printf("\n----- Records -----\n");
    printf("Account Number\tName\tBalance\n");
    for(int i=0; i<num_records; i++){
        printf("%d\t\t%s\t%f\n", bank_records[i].accountNumber, bank_records[i].name, bank_records[i].balance);
    }
}

// Function to search for a record using Account Number
void SearchRecord(struct BankingRecord *bank_records, int num_records){
    int acc_num;
    printf("\n----- Search for Record -----");
    printf("\nEnter Account Number: ");
    scanf("%d", &acc_num);
    int found=0;
    for(int i=0; i<num_records; i++){
        if(bank_records[i].accountNumber==acc_num){
            printf("\nRecord Found!\n");
            printf("Account Number\tName\tBalance\n");
            printf("%d\t\t%s\t%f\n", bank_records[i].accountNumber, bank_records[i].name, bank_records[i].balance);
            found=1;
            break;
        }
    }
    if(!found){
        printf("\nRecord Not Found!");
    }
}

// Function to delete a record using Account Number
void DeleteRecord(struct BankingRecord *bank_records, int *num_records){
    int acc_num;
    printf("\n----- Delete Record -----");
    printf("\nEnter Account Number: ");
    scanf("%d", &acc_num);
    int found=0;
    for(int i=0; i<*num_records; i++){
        if(bank_records[i].accountNumber==acc_num){
            for(int j=i; j<*num_records; j++){
                bank_records[j]=bank_records[j+1];
            }
            (*num_records)--;
            printf("\nRecord Deleted Successfully.");
            found=1;
            break;
        }
    }
    if(!found){
        printf("\nRecord Not Found!");
    }
}

int main(){
    struct BankingRecord bank_records[100];
    int num_records=0, choice;
    while(1){
        // Printing Menu Options
        printf("\n----- Banking Record System -----\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: AddRecord(bank_records, &num_records);
                    break;
            case 2: ViewRecords(bank_records, num_records);
                    break;
            case 3: SearchRecord(bank_records, num_records);
                    break;
            case 4: DeleteRecord(bank_records, &num_records);
                    break;
            case 5: exit(0);
            default: printf("\nInvalid Choice!");
        }
    }
    return 0;
}