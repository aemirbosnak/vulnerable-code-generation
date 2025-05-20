//FormAI DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record{
    char name[50];
    int accountNum;
    float balance;
};

int main(){
    int numRecords, i, option, found = 0;
    struct record *records;

    printf("Welcome to the Banking Record System!\n");
    printf("Enter the number of records you want to create: ");
    scanf("%d", &numRecords);

    records = (struct record*) malloc(numRecords * sizeof(struct record));

    for(i=0; i<numRecords; i++){
        printf("Record %d\n", i+1);
        printf("Enter name: ");
        scanf("%s", &records[i].name);
        printf("Enter account number: ");
        scanf("%d", &records[i].accountNum);
        printf("Enter balance: ");
        scanf("%f", &records[i].balance);
        printf("\n");
    }

    do{
        printf("Select an option:\n");
        printf("1. Search Record by Account Number\n");
        printf("2. Print All Records\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter account number: ");
                int account;
                scanf("%d", &account);
                for(i=0; i<numRecords; i++){
                    if(records[i].accountNum == account){
                        printf("Record Found!\n");
                        printf("Name: %s\n", records[i].name);
                        printf("Account Number: %d\n", records[i].accountNum);
                        printf("Account Balance: %.2f\n\n", records[i].balance);
                        found = 1;
                    }
                }
                if(found == 0){
                    printf("Record not found.\n\n");
                }
                break;
            case 2:
                printf("Printing all records:\n");
                for(i=0; i<numRecords; i++){
                    printf("Record %d:\n", i+1);
                    printf("Name: %s\n", records[i].name);
                    printf("Account Number: %d\n", records[i].accountNum);
                    printf("Account Balance: %.2f\n\n", records[i].balance);
                }
                break;
            case 3:
                printf("Exiting Banking Record System.\n");
                break;
            default:
                printf("Invalid option, please try again.\n\n");
        }
    }while(option != 3);

    free(records);
    return 0;
}