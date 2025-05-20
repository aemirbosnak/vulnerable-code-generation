//FormAI DATASET v1.0 Category: Banking Record System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record{
    char name[50];
    int acc_no;
    float balance;
};

void print_records(struct bank_record records[], int num_records){
    printf("Printing records...\n\n");
    for(int i=0; i<num_records; i++){
        printf("Name: %s\nAccount No: %d\nBalance: $%.2f\n\n", records[i].name, records[i].acc_no, records[i].balance);
    }
    printf("End of records.\n");
}

void update_balance(struct bank_record records[], int num_records, int acc_no, float amount){
    for(int i=0; i<num_records; i++){
        if(records[i].acc_no == acc_no){
            records[i].balance += amount;
            printf("Updated balance for account %d.\nNew balance: $%.2f\n", acc_no, records[i].balance);
            return;
        }
    }
    printf("Unable to find account no %d.\n", acc_no);
}

int main(){
    int choice, num_records = 0;
    struct bank_record records[100];

    do{
        printf("Welcome to the banking record system!\n\n");
        printf("1. Add record\n");
        printf("2. Print records\n");
        printf("3. Update balance\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:{
                char name[50];
                printf("Enter name: ");
                scanf("%s", name);
                int acc_no;
                printf("Enter account no: ");
                scanf("%d", &acc_no);
                float balance;
                printf("Enter balance: ");
                scanf("%f", &balance);

                struct bank_record new_record;
                strcpy(new_record.name, name);
                new_record.acc_no = acc_no;
                new_record.balance = balance;

                records[num_records] = new_record;
                num_records++;

                printf("Record added successfully.\n\n");
                break;
            }
            case 2:{
                print_records(records, num_records);
                break;
            }
            case 3:{
                int acc_no;
                printf("Enter account no: ");
                scanf("%d", &acc_no);
                float amount;
                printf("Enter amount to update: ");
                scanf("%f", &amount);

                update_balance(records, num_records, acc_no, amount);
                break;
            }
            case 4:{
                printf("Thank you for using the banking record system!\n");
                exit(0);
            }
            default:{
                printf("Invalid choice.\n\n");
                break;
            }
        }
    }while(1);

    return 0;
}