//FormAI DATASET v1.0 Category: Banking Record System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_RECORDS 100

struct banking_record {
    char name[50];
    char address[100];
    char account_number[20];
    float balance;
};

typedef struct banking_record record;

record records[MAX_RECORDS];
int num_of_records = 0;

int is_valid_account_number(char *account_number) {
    int i;
    if(strlen(account_number) != 10) {
        return 0;
    }
    for(i=0;i<strlen(account_number);i++) {
        if(!isdigit(account_number[i])) {
            return 0;
        }
    }
    return 1;
}

void add_record() {
    char name[50], address[100], account_number[20];
    float balance;

    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Address: ");
    scanf("%s", address);
    do {
        printf("Enter Account Number (10 digits only): ");
        scanf("%s", account_number);
    } while(!is_valid_account_number(account_number));
    printf("Enter Balance: ");
    scanf("%f", &balance);

    record new_record = {
        .balance = balance
    };
    strcpy(new_record.name, name);
    strcpy(new_record.address, address);
    strcpy(new_record.account_number, account_number);

    records[num_of_records++] = new_record;

    printf("Record Added Successfully!\n\n");

}

void view_record() {
    char account_number[20];

    do {
        printf("Enter Account Number (10 digits only): ");
        scanf("%s", account_number);
    } while(!is_valid_account_number(account_number));

    int i, found = 0;

    for(i=0;i<num_of_records;i++) {
        if(strcmp(records[i].account_number, account_number) == 0) {
            found = 1;
            printf("Name: %s\nAddress: %s\nAccount Number: %s\nBalance: %.2f\n\n", 
                    records[i].name, records[i].address, records[i].account_number, records[i].balance);
            break;
        }
    }

    if(!found) {
        printf("Record Not Found!\n\n");
    }
}

void list_records() {
    int i;

    for(i=0;i<num_of_records;i++) {
        printf("------------------------------------------------\n");
        printf("Name: %s\nAddress: %s\nAccount Number: %s\nBalance: %.2f\n", 
                records[i].name, records[i].address, records[i].account_number, records[i].balance);
    }

    printf("------------------------------------------------\n");
}

void menu() {
    int menu_choice;

    do {
        printf("1. Add Record\n");
        printf("2. View Record\n");
        printf("3. List All Records\n");
        printf("4. Quit\n");
        printf("Enter Choice: ");
        scanf("%d", &menu_choice);

        switch(menu_choice) {
            case 1:
                add_record();
                break;
            case 2:
                view_record();
                break;
            case 3:
                list_records();
                break;
            case 4:
                printf("Exiting Program!\n");
                break;
            default:
                printf("Invalid Choice! Try Again...\n\n");
                break;
        }

    } while(menu_choice != 4);
}

int main() {
    menu();
    return 0;
}