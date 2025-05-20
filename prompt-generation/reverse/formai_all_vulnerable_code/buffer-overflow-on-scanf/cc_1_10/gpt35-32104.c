//FormAI DATASET v1.0 Category: Banking Record System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    char name[50];
    char account_num[50];
    double balance;
};

void display_header() {
    printf("\n**************************************\n");
    printf("*          BANKING RECORDS           *\n");
    printf("**************************************\n");
}

void display_menu() {
    printf("\n1. Add a record.");
    printf("\n2. View all records.");
    printf("\n3. View record by account number.");
    printf("\n4. Delete record by account number.");
    printf("\n5. Exit.");
}

void add_record(struct record *r) {
    printf("\nName: ");
    scanf("%s", r->name);

    printf("\nAccount Number: ");
    scanf("%s", r->account_num);

    printf("\nBalance: ");
    scanf("%lf", &r->balance);
}

void view_all_records(struct record *records, int num_records) {
    printf("\n%-20s%-20s%-20s", "Name", "Account Number", "Balance");
    
    for(int i = 0; i < num_records; i++) {
        printf("\n%-20s%-20s%-20.2lf", records[i].name, records[i].account_num, records[i].balance);
    }
}

void view_record_by_num(struct record *records, int num_records) {
    char acc_num[50];
    printf("\nAccount Number: ");
    scanf("%s", acc_num);

    for(int i = 0; i < num_records; i++) {
        if(strcmp(records[i].account_num, acc_num) == 0) {
            printf("\n%-20s%-20s%-20.2lf", records[i].name, records[i].account_num, records[i].balance);
            return;
        }
    }

    printf("\nNo records found with account number %s", acc_num);
}

void delete_record_by_num(struct record *records, int *num_records) {
    char acc_num[50];
    printf("\nAccount Number: ");
    scanf("%s", acc_num);

    for(int i = 0; i < *num_records; i++) {
        if(strcmp(records[i].account_num, acc_num) == 0) {
            for(int j = i + 1; j < *num_records; j++) {
                records[j-1] = records[j];
            }
            (*num_records)--;
            printf("\nRecord %s deleted successfully", acc_num);
            return;
        }
    }

    printf("\nNo records found with account number %s", acc_num);
}

int main() {
    int num_records = 0;
    struct record records[100];

    int choice = 0;
    while(choice != 5) {
        display_header();
        display_menu();
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_records < 100) {
                    add_record(&records[num_records]);
                    num_records++;
                } else {
                    printf("\nCannot add record - Maximum limit reached.");
                }
                break;
            case 2:
                if(num_records > 0) {
                    view_all_records(records, num_records);
                } else {
                    printf("\nNo records found.");
                }
                break;
            case 3:
                if(num_records > 0) {
                    view_record_by_num(records, num_records);
                } else {
                    printf("\nNo records found.");
                }
                break;
            case 4:
                if(num_records > 0) {
                    delete_record_by_num(records, &num_records);
                } else {
                    printf("\nNo records found.");
                }
                break;
            case 5:
                printf("\nExiting program.");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
        }

        printf("\n\n");
        system("pause");
        system("cls");
    }

    return 0;
}