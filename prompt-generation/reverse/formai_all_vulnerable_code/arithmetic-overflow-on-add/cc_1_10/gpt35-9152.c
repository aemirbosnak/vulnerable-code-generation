//FormAI DATASET v1.0 Category: Banking Record System ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>

typedef struct record
{
    char name[30];
    uint32_t account_no;
    float balance;
    char account_type[10];
    char last_transaction[30];
} RECORD;

RECORD* records;
uint32_t count;

void initialize()
{
    count = 0;
    records = NULL;
}

void insert_record(RECORD* new_record)
{
    records = (RECORD*)realloc(records, sizeof(RECORD) * (count + 1));
    records[count].account_no = new_record->account_no;
    records[count].balance = new_record->balance;
    strcpy(records[count].name, new_record->name);
    strcpy(records[count].account_type, new_record->account_type);
    strcpy(records[count].last_transaction, new_record->last_transaction);
    count++;
}

RECORD* get_record_by_account_no(uint32_t account_no)
{
    for(uint32_t i=0; i<count; i++)
    {
        if(records[i].account_no == account_no)
        {
            return &records[i];
        }
    }
    return NULL;
}

void deposit(RECORD* record, float amount)
{
    record->balance += amount;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(record->last_transaction, "%d/%d/%d: Deposited %.2f", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, amount);
}

void withdraw(RECORD* record, float amount)
{
    if(record->balance < amount)
    {
        printf("Not enough balance!\n");
        return;
    }
    record->balance -= amount;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(record->last_transaction, "%d/%d/%d: Withdrawn %.2f", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, amount);
}

void print_record(RECORD record)
{
    printf("-----------------------------\n");
    printf("Name: %s\n", record.name);
    printf("Account No: %u\n", record.account_no);
    printf("Balance: %.2f\n", record.balance);
    printf("Account Type: %s\n", record.account_type);
    printf("Last Transaction: %s\n", record.last_transaction);
    printf("-----------------------------\n");
}

void print_all()
{
    for(uint32_t i=0; i<count; i++)
    {
        print_record(records[i]);
    }
}

int main()
{
    initialize();

    RECORD record1 = {"David", 1001, 50000.00, "Savings", "N/A"};
    insert_record(&record1);

    RECORD record2 = {"Sophie", 1002, 25000.00, "Current", "N/A"};
    insert_record(&record2);

    RECORD record3 = {"John", 1003, 100000.00, "Savings", "N/A"};
    insert_record(&record3);

    RECORD record4 = {"Maya", 1004, 5000.00, "Current", "N/A"};
    insert_record(&record4);

    RECORD* found_record = get_record_by_account_no(1003);
    if(found_record != NULL)
    {
        deposit(found_record, 2000.00);
        print_record(*found_record);
    }

    found_record = get_record_by_account_no(1002);
    if(found_record != NULL)
    {
        withdraw(found_record, 5000.00);
        print_record(*found_record);
    }

    print_all();

    return 0;
}