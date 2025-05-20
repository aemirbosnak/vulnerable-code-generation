//FormAI DATASET v1.0 Category: Banking Record System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct record{
    char name[20];
    int account_num;
    float balance;
}Record;

void addRecord(Record* bank, int size);
void viewRecord(Record* bank, int size);
void deleteRecord(Record* bank, int* size);

int main(){
    int size = 0, choice, i;
    char temp[20];
    Record* bank = malloc(sizeof(Record)* size);

    while(1){
        printf("Welcome to the C Banking Record System!\n");
        printf("1. Add a Record\n");
        printf("2. View All Records\n");
        printf("3. Delete a Record\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addRecord(bank, size);
                size++;
                bank = realloc(bank, sizeof(Record)* size);
                break;
            case 2:
                viewRecord(bank, size);
                break;
            case 3:
                deleteRecord(bank, &size);
                break;
            case 4:
                printf("Thank you for using C Banking Record System!\n");
                free(bank);
                return 0;
            default:
                printf("Invalid Choice! Please Try Again.\n");
                break;
        }
         
    }

    return 0;
}

void addRecord(Record* bank, int size){
    printf("Enter Name of Account Holder: ");
    scanf("%s", (bank+size)->name);
    printf("Enter Account Number: ");
    scanf("%d", &(bank+size)->account_num);
    printf("Enter Account Balance: ");
    scanf("%f", &(bank+size)->balance);

    printf("Record Added Successfully!\n");
}

void viewRecord(Record* bank, int size){
    int i;
    printf("| %-20s | %-10s | %-10s |\n", "Name", "Account", "Balance");
    printf("| -------------------- | ---------- | ---------- |\n");
    for(i = 0; i < size; i++){
        printf("| %-20s | %-10d | %-10.2f |\n", (bank+i)->name, (bank+i)->account_num, (bank+i)->balance);
    }
}

void deleteRecord(Record* bank, int* size){
    int i, account_num, found = 0;
    printf("Enter Account Number: ");
    scanf("%d", &account_num);

    for(i = 0; i < *size; i++){
        if(account_num == (bank+i)->account_num){
            found = 1;
            break;
        }
    }

    if(found == 1){
        for(;i < *size-1; i++){
            strcpy((bank+i)->name, (bank+i+1)->name);
            (bank+i)->account_num = (bank+i+1)->account_num;
            (bank+i)->balance = (bank+i+1)->balance;
        }
        *size = *size - 1;
        bank = realloc(bank, sizeof(Record)* (*size));
        printf("Record Deleted Successfully!\n");
    }else{
        printf("Record Not Found!\n");
    }
}