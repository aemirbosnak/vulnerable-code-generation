//FormAI DATASET v1.0 Category: Banking Record System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char name[50];
    int account_number;
    float balance;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record() {
    Record record;
    printf("Enter Name: ");
    scanf("%s", record.name);
    printf("Enter Account Number: ");
    scanf("%d", &record.account_number);
    printf("Enter Balance: ");
    scanf("%f", &record.balance);

    records[num_records] = record;
    num_records++;
}

void display_records() {
    printf("Name | Account Number | Balance\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s | %d | %.2f\n", records[i].name, records[i].account_number, records[i].balance);
    }
}

void search_record() {
    int account_number;
    printf("Enter Account Number to Search: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            printf("Name: %s\nAccount Number: %d\nBalance: %.2f\n", records[i].name, records[i].account_number, records[i].balance);
            return;
        }
    }
    printf("Account Not Found\n");
}

void delete_record() {
    int account_number;
    printf("Enter Account Number to Delete: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            for (int j = i; j < num_records - 1; j++) {
                records[j] = records[j+1];
            }
            num_records--;
            printf("Account Deleted\n");
            return;
        }
    }
    printf("Account Not Found\n");
}

int main() {
    while (1) {
        int choice;
        printf("\nBanking Record System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}