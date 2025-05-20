//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 50
#define MAX_ACCOUNT_NUMBER_LEN 20
#define MAX_TRANSACTION_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char account_number[MAX_ACCOUNT_NUMBER_LEN];
    char transaction_type[MAX_TRANSACTION_AMOUNT_LEN];
    char transaction_amount[MAX_TRANSACTION_AMOUNT_LEN];
    int transaction_date;
} record_t;

void add_record(record_t *record) {
    FILE *file;
    file = fopen("banking_records.txt", "a");
    fprintf(file, "%s\t%s\t%s\t%s\t%d\n", record->name, record->account_number, record->transaction_type, record->transaction_amount, record->transaction_date);
    fclose(file);
}

void view_records() {
    FILE *file;
    record_t record;
    file = fopen("banking_records.txt", "r");
    while (fscanf(file, "%s\t%s\t%s\t%s\t%d", record.name, record.account_number, record.transaction_type, record.transaction_amount, &record.transaction_date) == 5) {
        printf("%s\t%s\t%s\t%s\t%d\n", record.name, record.account_number, record.transaction_type, record.transaction_amount, record.transaction_date);
    }
    fclose(file);
}

int main() {
    record_t new_record;
    char choice;
    do {
        printf("Enter account holder name (max %d characters): ", MAX_NAME_LEN);
        scanf("%s", new_record.name);
        printf("Enter account number (max %d characters): ", MAX_ACCOUNT_NUMBER_LEN);
        scanf("%s", new_record.account_number);
        printf("Enter transaction type (max %d characters): ", MAX_TRANSACTION_AMOUNT_LEN);
        scanf("%s", new_record.transaction_type);
        printf("Enter transaction amount (max %d characters): ", MAX_TRANSACTION_AMOUNT_LEN);
        scanf("%s", new_record.transaction_amount);
        printf("Enter transaction date (YYYY-MM-DD): ");
        scanf("%d", &new_record.transaction_date);
        add_record(&new_record);
        printf("\nRecord added successfully!\n");
        printf("Do you want to view records? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    return 0;
}