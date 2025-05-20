//FormAI DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

//Structure to hold banking records
struct BankingRecord {
    char name[50];
    int account_number;
    float balance;
};

//Function to read data from file
int read_records(FILE *fp, struct BankingRecord records[]) {
    int count = 0;
    while(!feof(fp)) {
        fscanf(fp, "%s %d %f", records[count].name, &records[count].account_number, &records[count].balance);
        count++;
    }
    return count;
}

//Function to write data to file
void write_records(FILE *fp, struct BankingRecord records[], int count) {
    for(int i=0;i<count;i++) {
        fprintf(fp, "%s %d %.2f\n", records[i].name, records[i].account_number, records[i].balance);
    }
}

//Function to search for a record by account number
int search_record(struct BankingRecord records[], int count, int account_number) {
    for(int i=0;i<count;i++) {
        if(records[i].account_number == account_number) {
            return i;
        }
    }
    return -1;
}

//Function to deposit money into an account
void deposit(struct BankingRecord records[], int count, int account_number, float amount) {
    int index = search_record(records, count, account_number);
    if(index != -1) {
        records[index].balance += amount;
    }
}

//Function to withdraw money from an account
void withdraw(struct BankingRecord records[], int count, int account_number, float amount) {
    int index = search_record(records, count, account_number);
    if(index != -1) {
        records[index].balance -= amount;
    }
}

//Main function
int main() {
    FILE *fp;
    struct BankingRecord records[100];
    int choice, count, account_number;
    float balance, amount;
    char name[50];

    //Open file for reading and writing
    fp = fopen("bank_records.txt", "r+");
    if(fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    //Read records from file
    count = read_records(fp, records);

    //Menu driven program
    while(1) {
        printf("Welcome to the banking record system!\n");
        printf("1. View all records\n");
        printf("2. Search for a record by account number\n");
        printf("3. Add a new record\n");
        printf("4. Deposit money into an account\n");
        printf("5. Withdraw money from an account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: //View all records
                printf("Name\tAccount Number\tBalance\n");
                for(int i=0;i<count;i++) {
                    printf("%s\t%d\t\t%.2f\n", records[i].name, records[i].account_number, records[i].balance);
                }
                break;
            case 2: //Search for a record by account number
                printf("Enter account number: ");
                scanf("%d", &account_number);
                int index = search_record(records, count, account_number);
                if(index != -1) {
                    printf("Record found!\n");
                    printf("Name\tAccount Number\tBalance\n");
                    printf("%s\t%d\t\t%.2f\n", records[index].name, records[index].account_number, records[index].balance);
                } else {
                    printf("Record not found!\n");
                }
                break;
            case 3: //Add a new record
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter balance: ");
                scanf("%f", &balance);
                records[count].account_number = account_number;
                records[count].balance = balance;
                strcpy(records[count].name, name);
                count++;
                break;
            case 4: //Deposit money into an account
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(records, count, account_number, amount);
                break;
            case 5: //Withdraw money from an account
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(records, count, account_number, amount);
                break;
            case 6: //Exit
                write_records(fp, records, count);
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}