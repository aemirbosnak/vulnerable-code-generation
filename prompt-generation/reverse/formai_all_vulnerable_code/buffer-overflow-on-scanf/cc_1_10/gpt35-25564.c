//FormAI DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[MAX];
    char address[MAX];
    char account[MAX];
    float balance;
} Record;

void show_menu() {
    printf("\nWelcome to Banking Record System!\n");
    printf("\nMenu Options:\n");
    printf("1. Add a new record\n");
    printf("2. View all records\n");
    printf("3. Find and view one particular record\n");
    printf("4. Update the information of one particular record\n");
    printf("5. Exit the program\n");
    printf("\nEnter your selection: ");
}

void add_record(Record *records, int *count) {
    Record new_record;
    printf("\nEnter the name: ");
    fgets(new_record.name, MAX, stdin);
    new_record.name[strcspn(new_record.name, "\n")] = '\0';
    printf("\nEnter the address: ");
    fgets(new_record.address, MAX, stdin);
    new_record.address[strcspn(new_record.address, "\n")] = '\0';
    printf("\nEnter the account number: ");
    fgets(new_record.account, MAX, stdin);
    new_record.account[strcspn(new_record.account, "\n")] = '\0';
    printf("\nEnter the balance: ");
    scanf("%f", &new_record.balance);
    getchar();
    records[*count] = new_record;
    *count += 1;
}

void view_records(Record *records, int count) {
    if (count == 0) {
        printf("\nThere are no records to display.\n");
    } else {
        printf("\nAll records:\n");
        for (int i = 0; i < count; i++) {
            printf("\nRecord %d:\n", i+1);
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            printf("Account Number: %s\n", records[i].account);
            printf("Balance: %.2f\n", records[i].balance);
        }
    }
}

void find_record(Record *records, int count) {
    char search_account[MAX];
    printf("\nEnter the account number of the record you want to view: ");
    fgets(search_account, MAX, stdin);
    search_account[strcspn(search_account, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].account, search_account) == 0) {
            printf("\nRecord found:\n");
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            printf("Account Number: %s\n", records[i].account);
            printf("Balance: %.2f\n", records[i].balance);
            return;
        }
    }
    printf("\nRecord not found.\n");
}

void update_record(Record *records, int count) {
    char search_account[MAX];
    printf("\nEnter the account number of the record you want to update: ");
    fgets(search_account, MAX, stdin);
    search_account[strcspn(search_account, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].account, search_account) == 0) {
            printf("\nCurrent record:\n");
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            printf("Account Number: %s\n", records[i].account);
            printf("Balance: %.2f\n", records[i].balance);
            printf("\nEnter the updated name: ");
            fgets(records[i].name, MAX, stdin);
            records[i].name[strcspn(records[i].name, "\n")] = '\0';
            printf("\nEnter the updated address: ");
            fgets(records[i].address, MAX, stdin);
            records[i].address[strcspn(records[i].address, "\n")] = '\0';
            printf("\nEnter the updated balance: ");
            scanf("%f", &records[i].balance);
            getchar();
            printf("\nRecord updated successfully.\n");
            return;
        }
    }
    printf("\nRecord not found.\n");
}

int main() {
    Record records[MAX];
    int count = 0;
    int selection;
    do {
        show_menu();
        scanf("%d", &selection);
        getchar();
        switch(selection) {
            case 1:
                add_record(records, &count);
                break;
            case 2:
                view_records(records, count);
                break;
            case 3:
                find_record(records, count);
                break;
            case 4:
                update_record(records, count);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid selection. Please try again.\n");
                break;
        }
    } while (selection != 5);
    return 0;
}