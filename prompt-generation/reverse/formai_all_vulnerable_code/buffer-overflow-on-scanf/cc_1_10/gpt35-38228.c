//FormAI DATASET v1.0 Category: Banking Record System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct record{
    int recordID;
    char name[50];
    double balance;
};

int count;

void createRecord(struct record *records){
    printf("Enter record ID: ");
    scanf("%d", &(records + count)->recordID);
    printf("Enter name: ");
    scanf("%s", (records + count)->name);
    printf("Enter balance: ");
    scanf("%lf", &(records + count)->balance);
    count++;
}

void displayRecords(struct record *records){
    printf("Record ID\tName\t\tBalance\n");
    for(int i = 0; i < count; i++){
        printf("%d\t\t%s\t\t%.2lf\n", (records + i)->recordID, (records + i)->name, (records + i)->balance);
    }
}

void deposit(struct record *records, int recordID, double amount){
    for(int i = 0; i < count; i++){
        if((records + i)->recordID == recordID){
            (records + i)->balance += amount;
            printf("Deposit successful!\n");
            printf("New balance: %.2lf\n", (records + i)->balance);
            return;
        }
    }
    printf("Record not found.\n");
}

void withdraw(struct record *records, int recordID, double amount){
    for(int i = 0; i < count; i++){
        if((records + i)->recordID == recordID){
            if(amount > (records + i)->balance){
                printf("Insufficient funds. Withdrawal failed.\n");
                return;
            }
            (records + i)->balance -= amount;
            printf("Withdrawal successful!\n");
            printf("New balance: %.2lf\n", (records + i)->balance);
            return;
        }
    }
    printf("Record not found.\n");
}

int main(){
    struct record records[100];
    char choice[10];
    count = 0;
    
    while(1){
        printf("\nEnter choice:\n");
        printf("1 - Create record\n2 - Display records\n3 - Deposit\n4 - Withdraw\n5 - Exit\n");
        scanf("%s", choice);
        
        if(strcmp(choice, "1") == 0){
            createRecord(records);
        }
        else if(strcmp(choice, "2") == 0){
            displayRecords(records);
        }
        else if(strcmp(choice, "3") == 0){
            int recordID;
            double amount;
            printf("Enter record ID: ");
            scanf("%d", &recordID);
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            deposit(records, recordID, amount);
        }
        else if(strcmp(choice, "4") == 0){
            int recordID;
            double amount;
            printf("Enter record ID: ");
            scanf("%d", &recordID);
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            withdraw(records, recordID, amount);
        }
        else if(strcmp(choice, "5") == 0){
            break;
        }
        else{
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}