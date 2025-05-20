//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
    char name[50];
    int account_number;
    int balance;
};

void display_record(struct bank_record r);

int main() {
    struct bank_record r1, r2, r3;

    strcpy(r1.name, "John Doe");
    r1.account_number = 12345678;
    r1.balance = 1000;

    strcpy(r2.name, "Jane Smith");
    r2.account_number = 23456789;
    r2.balance = 5000;

    strcpy(r3.name, "Bob Johnson");
    r3.account_number = 34567890;
    r3.balance = 7000;

    printf("--== Cyberbank Record System ==--\n\n");

    printf("Please select an option:\n");
    printf("1. Display all records\n");
    printf("2. Search for a record by account number\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Name\t\tAccount Number\t\tBalance\n");
        printf("------------------------------------------------\n");
        display_record(r1);
        display_record(r2);
        display_record(r3);
        break;

    case 2:
        printf("Enter account number: ");
        int account_num;
        scanf("%d", &account_num);

        if (account_num == r1.account_number) {
            display_record(r1);
        }
        else if (account_num == r2.account_number) {
            display_record(r2);
        }
        else if (account_num == r3.account_number) {
            display_record(r3);
        }
        else {
            printf("Record not found.\n");
        }
        break;

    default:
        printf("Invalid choice.\n");
    }

    return 0;
}

void display_record(struct bank_record r) {
    printf("%s\t\t%d\t\t\t%d\n", r.name, r.account_number, r.balance);
}