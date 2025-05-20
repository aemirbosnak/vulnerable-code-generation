//FormAI DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

// Banking Record Structure
typedef struct {
    int acc_no;
    char name[30];
    float balance;
} bank_record;

// Function to add new record
void add_record(bank_record *record, int n) {
    FILE *fp = fopen("bank_record.dat", "ab");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    for(int i=0; i<n; i++) {
        printf("Enter account number, name & balance for record %d: \n", i+1);
        scanf("%d", &record[i].acc_no);
        fflush(stdin);
        gets(record[i].name);
        scanf("%f", &record[i].balance);
        fwrite(&record[i], sizeof(bank_record), 1, fp);
    }
    fclose(fp);
    printf("%d record(s) has been successfully added to the bank record file.\n", n);
}

// Function to display all records
void display_all_records() {
    FILE *fp = fopen("bank_record.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    bank_record record;
    printf("\n\nAccount No.\tName\t\t\tBalance\n");
    while(fread(&record, sizeof(bank_record), 1, fp) == 1) {
        printf("%d\t\t%s\t\t\t%.2f\n", record.acc_no, record.name, record.balance);
    }
    fclose(fp);
}

// Function to search record by account number
void search_record(int acc_no) {
    FILE *fp = fopen("bank_record.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    bank_record record;
    int found = 0;
    while(fread(&record, sizeof(bank_record), 1, fp) == 1) {
        if(record.acc_no == acc_no) {
            found = 1;
            break;
        }
    }
    if(found) {
        printf("\nAccount No.\tName\t\t\tBalance\n");
        printf("%d\t\t%s\t\t\t%.2f\n", record.acc_no, record.name, record.balance);
    } else {
        printf("\nRecord not found with account number %d.\n", acc_no);
    }
    fclose(fp);
}

// Function to update record by account number
void update_record(int acc_no, float new_balance) {
    FILE *fp = fopen("bank_record.dat", "rb+");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    bank_record record;
    int found = 0;
    while(fread(&record, sizeof(bank_record), 1, fp) == 1) {
        if(record.acc_no == acc_no) {
            found = 1;
            record.balance = new_balance;
            fseek(fp, -sizeof(bank_record), SEEK_CUR);
            fwrite(&record, sizeof(bank_record), 1, fp);
            break;
        }
    }
    if(found) {
        printf("\nAccount No. %d has been successfully updated with new balance %.2f.\n", acc_no, new_balance);
    } else {
        printf("\nRecord not found with account number %d.\n", acc_no);
    }
    fclose(fp);
}

// Function to delete record by account number
void delete_record(int acc_no) {
    FILE *fp = fopen("bank_record.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    FILE *fp_temp = fopen("temp.dat", "wb");
    if(fp_temp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    bank_record record;
    int found = 0;
    while(fread(&record, sizeof(bank_record), 1, fp) == 1) {
        if(record.acc_no != acc_no) {
            fwrite(&record, sizeof(bank_record), 1, fp_temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(fp_temp);
    if(remove("bank_record.dat")) {
        printf("Error deleting file!\n");
        exit(1);
    }
    if(rename("temp.dat", "bank_record.dat")) {
        printf("Error renaming file!\n");
        exit(1);
    }
    if(found) {
        printf("\nRecord with account number %d has been successfully deleted.\n", acc_no);
    } else {
        printf("\nRecord not found with account number %d.\n", acc_no);
    }
}

// Main Function
int main() {
    int choice, n, acc_no;
    float new_balance;
    bank_record record[50];
    do {
        printf("\n------------------------ Welcome to Banking Record System ------------------------\n");
        printf("\nEnter your choice: \n");
        printf("1 -> Add new record\n");
        printf("2 -> Display all records\n");
        printf("3 -> Search record by account number\n");
        printf("4 -> Update record by account number\n");
        printf("5 -> Delete record by account number\n");
        printf("6 -> Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter number of record to add: ");
                scanf("%d", &n);
                add_record(record, n);
                break;
            case 2:
                display_all_records();
                break;
            case 3:
                printf("\nEnter account number to search: ");
                scanf("%d", &acc_no);
                search_record(acc_no);
                break;
            case 4:
                printf("\nEnter account number to update: ");
                scanf("%d", &acc_no);
                printf("Enter new balance: ");
                scanf("%f", &new_balance);
                update_record(acc_no, new_balance);
                break;
            case 5:
                printf("\nEnter account number to delete: ");
                scanf("%d", &acc_no);
                delete_record(acc_no);
                break;
            case 6:
                printf("\nThank you for using Banking Record System!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while(choice != 6);
    return 0;
}