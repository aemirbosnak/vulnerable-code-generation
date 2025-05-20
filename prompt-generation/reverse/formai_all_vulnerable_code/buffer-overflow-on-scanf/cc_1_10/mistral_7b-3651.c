//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define RECORD_SIZE 100
#define SURPRISE_LIMIT 10

typedef struct {
    char name[50];
    int account_number;
    float balance;
    time_t last_transaction;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record(const char *name, int account_number, float amount) {
    Record new_record;
    strcpy(new_record.name, name);
    new_record.account_number = account_number;
    new_record.balance = records[num_records - 1].balance + amount;
    time(&new_record.last_transaction);

    records[num_records++] = new_record;

    if (num_records > MAX_RECORDS / 2 && rand() % 10 < SURPRISE_LIMIT) {
        printf("\nSURPRISE: You have just unlocked a secret feature!\n");
        printf("Record added successfully.\n");
    } else {
        printf("Record added successfully.\n");
    }
}

void display_records() {
    int i;

    printf("\n--- BANKING RECORDS ---\n");
    for (i = 0; i < num_records; i++) {
        printf("%d. %s - Account %d - Balance: %.2f - Last Transaction: %s\n",
            i + 1, records[i].name, records[i].account_number, records[i].balance,
            ctime(&records[i].last_transaction));
    }
}

int main() {
    int choice, account_number;
    float amount;
    char name[50];

    while (1) {
        printf("\n1. Add Record\n2. Display Records\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Account Number: ");
                scanf("%d", &account_number);
                printf("Enter Amount: ");
                scanf("%f", &amount);
                add_record(name, account_number, amount);
                break;

            case 2:
                display_records();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}