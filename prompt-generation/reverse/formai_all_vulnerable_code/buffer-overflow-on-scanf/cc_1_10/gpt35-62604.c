//FormAI DATASET v1.0 Category: Banking Record System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
    int account_number;
    char name[50];
    float balance;
};

void display_menu() {
    printf("\n---------- BANK RECORD SYSTEM ----------\n");
    printf("1. Add a new record\n");
    printf("2. Modify existing record\n");
    printf("3. Delete a record\n");
    printf("4. Search for a record\n");
    printf("5. Display all records\n");
    printf("6. Exit\n");
    printf("----------------------------------------\n");
}

void add_record(struct bank_record *records, int *count) {
    printf("\nEnter account number: ");
    scanf("%d", &records[*count].account_number);
    printf("Enter name: ");
    fflush(stdin);
    gets(records[*count].name);
    printf("Enter balance: ");
    scanf("%f", &records[*count].balance);
    (*count)++;
}

void modify_record(struct bank_record *records, int count) {
    int account_number, i, choice;
    printf("\nEnter account number to modify: ");
    scanf("%d", &account_number);
    for(i=0; i<count; i++) {
        if(records[i].account_number == account_number) {
            printf("\nRecord Found!\n");
            printf("1. Modify name\n");
            printf("2. Modify balance\n");
            printf("3. Cancel\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("Enter new name: ");
                    fflush(stdin);
                    gets(records[i].name);
                    printf("Record modified successfully!\n");
                    break;
                case 2:
                    printf("Enter new balance: ");
                    scanf("%f", &records[i].balance);
                    printf("Record modified successfully!\n");
                    break;
                case 3:
                    printf("Record not modified!\n");
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
            }
            return;
        }
    }
    printf("\nRecord not found!\n");
}

void delete_record(struct bank_record *records, int *count) {
    int account_number, i, j;
    printf("\nEnter account number to delete: ");
    scanf("%d", &account_number);
    for(i=0; i<*count; i++) {
        if(records[i].account_number == account_number) {    
            for(j=i; j<*count-1; j++) {
                records[j].account_number = records[j+1].account_number;
                strcpy(records[j].name, records[j+1].name);
                records[j].balance = records[j+1].balance;
            }
            (*count)--;
            printf("\nRecord deleted successfully!\n");
            return;
        }
    }
    printf("\nRecord not found!\n");
}

void search_record(struct bank_record *records, int count) {
    int account_number, i;
    printf("\nEnter account number to search: ");
    scanf("%d", &account_number);
    
    printf("\nSearching...\n");
    for(i=0; i<count; i++) {
        if(records[i].account_number == account_number) {
            printf("\nAccount Number: %d\n", records[i].account_number);
            printf("Name: %s\n", records[i].name);
            printf("Balance: %.2f\n", records[i].balance);
            return;
        }
    }
    printf("\nRecord not found!\n");
}

void display_all_records(struct bank_record *records, int count) {
    int i;
    printf("\n");
    printf("Account Number\tName\tBalance\n");
    for(i=0; i<count; i++) {
        printf("%d\t\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);
    }
}

int main() {
    struct bank_record records[100];
    int choice, count=0;
    while(1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_record(records, &count);
                break;
            case 2:
                modify_record(records, count);
                break;
            case 3:
                delete_record(records, &count);
                break;
            case 4:
                search_record(records, count);
                break;
            case 5:
                display_all_records(records, count);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}