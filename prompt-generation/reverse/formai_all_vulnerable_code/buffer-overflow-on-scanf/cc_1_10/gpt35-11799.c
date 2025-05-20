//FormAI DATASET v1.0 Category: Banking Record System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "bank.txt"
#define MAX_RECORDS 100

typedef struct {
    char name[50];
    int account_number;
    float balance;
} BankRecord;

int num_records = 0;
BankRecord records[MAX_RECORDS];

void menu();
void add_record();
void view_all_records();
void view_record();
void update_record();
void delete_record();
void save_records();

int main() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Bank record file not found. Creating new file!\n");
        file = fopen(FILENAME, "w");
        fclose(file);
    } else {
        printf("Loading bank records...\n");
        while (!feof(file) && num_records < MAX_RECORDS) {
            BankRecord record;
            fread(&record, sizeof(BankRecord), 1, file);
            if (strlen(record.name) > 0) {
                records[num_records++] = record;
            }
        }
        fclose(file);
    }

    menu();

    // Save records on exit
    save_records();

    return 0;
}

void menu() {
    printf("\nBank Record System\n");
    printf("---------------------------\n");
    printf("1. Add record\n");
    printf("2. View all records\n");
    printf("3. View record\n");
    printf("4. Update record\n");
    printf("5. Delete record\n");
    printf("6. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: add_record(); break;
        case 2: view_all_records(); break;
        case 3: view_record(); break;
        case 4: update_record(); break;
        case 5: delete_record(); break;
        case 6: return;
        default: printf("Invalid choice!\n\n");
    }

    menu();
}

void add_record() {
    if (num_records >= MAX_RECORDS) {
        printf("Maximum number of records reached!\n\n");
        return;
    }

    BankRecord record;
    printf("\nEnter details for new record:\n");

    printf("Name: ");
    scanf("%s", record.name);

    printf("Account number: ");
    scanf("%d", &record.account_number);

    printf("Balance: ");
    scanf("%f", &record.balance);

    records[num_records] = record;
    num_records++;

    printf("Record added successfully!\n\n");
}

void view_all_records() {
    if (num_records == 0) {
        printf("\nNo records found!\n");
    } else {
        printf("\nAll bank records:\n");
        printf("----------------------------------------\n");
        printf("Name\tAccount Number\tBalance\n");
        printf("----------------------------------------\n");
        for (int i = 0; i < num_records; i++) {
            BankRecord record = records[i];
            printf("%s\t%d\t%0.2f\n", record.name, record.account_number, record.balance);
        }
    }
}

void view_record() {
    int account_number;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);

    BankRecord *record = NULL;
    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            record = &records[i];
            break;
        }
    }

    if (record == NULL) {
        printf("\nRecord not found!\n\n");
    } else {
        printf("\nRecord found:\n");
        printf("----------------------------------------\n");
        printf("Name: %s\n", record->name);
        printf("Account Number: %d\n", record->account_number);
        printf("Balance: %0.2f\n", record->balance);
    }
}

void update_record() {
    int account_number;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);

    BankRecord *record = NULL;
    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            record = &records[i];
            break;
        }
    }

    if (record == NULL) {
        printf("\nRecord not found!\n\n");
    } else {
        printf("\nRecord found. Enter new details:\n");

        printf("Name: ");
        scanf("%s", record->name);

        printf("Account number: ");
        scanf("%d", &record->account_number);

        printf("Balance: ");
        scanf("%f", &record->balance);

        printf("\nRecord updated successfully!\n\n");
    }
}

void delete_record() {
    int account_number;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);

    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (records[i].account_number == account_number) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nRecord not found!\n\n");
    } else {
        for (int i = index; i < num_records - 1; i++) {
            records[i] = records[i+1];
        }
        num_records--;

        printf("\nRecord deleted successfully!\n\n");
    }
}

void save_records() {
    FILE *file = fopen(FILENAME, "w");
    for (int i = 0; i < num_records; i++) {
        fwrite(&records[i], sizeof(BankRecord), 1, file);
    }
    fclose(file);
}