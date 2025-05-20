//FormAI DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100

struct Record {
    int account_number;
    char account_name[MAX_NAME_LENGTH];
    float account_balance;
};

int record_count = 0;
struct Record records[MAX_RECORDS];

void add_record() {
    struct Record new_record;
    printf("Enter account number: ");
    scanf("%d", &new_record.account_number);
    printf("Enter account name: ");
    scanf("%s", new_record.account_name);
    printf("Enter account balance: ");
    scanf("%f", &new_record.account_balance);

    records[record_count] = new_record;
    record_count++;
}

void print_record(struct Record record) {
    printf("Account Number: %d\n", record.account_number);
    printf("Account Name: %s\n", record.account_name);
    printf("Account Balance: $%.2f\n", record.account_balance);
}

void display_records() {
    printf("Total Records: %d\n", record_count);
    for(int i = 0; i < record_count; i++) {
        printf("\nRecord %d:\n", i+1);
        print_record(records[i]);
    }
}

void search_record() {
    int account_number;
    printf("Enter account number to search: ");
    scanf("%d", &account_number);

    for(int i = 0; i < record_count; i++) {
        if(records[i].account_number == account_number) {
            printf("Record found:\n");
            print_record(records[i]);
            return;
        }
    }
    printf("Record not found\n");
}

void delete_record() {
    int account_number;
    printf("Enter account number to delete: ");
    scanf("%d", &account_number);

    for(int i = 0; i < record_count; i++) {
        if(records[i].account_number == account_number) {
            for(int j = i; j < record_count - 1; j++) {
                records[j] = records[j+1];
            }
            record_count--;
            printf("Record deleted\n");
            return;
        }
    }
    printf("Record not found\n");
}

void write_records_to_file() {
    FILE *fp;
    fp = fopen("records.txt", "w");
    for(int i = 0; i < record_count; i++) {
        fwrite(&records[i], sizeof(struct Record), 1, fp);
    }
    fclose(fp);
    printf("Records saved to file\n");
}

void read_records_from_file() {
    FILE *fp;
    fp = fopen("records.txt", "r");
    if(fp == NULL) {
        printf("Error: Cannot open file\n");
        return;
    }

    int count = 0;
    struct Record buffer;
    while(fread(&buffer, sizeof(struct Record), 1, fp)) {
        records[count++] = buffer;
    }
    record_count = count;
    printf("Records read from file\n");
}

int main() {
    char input[10];
    while(1) {
        printf("\n\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Write Records to File\n");
        printf("6. Read Records from File\n");
        printf("7. Quit\n");
        printf("Enter choice: ");
        scanf("%s", input);

        switch(atoi(input)) {
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
                write_records_to_file();
                break;
            case 6:
                read_records_from_file();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid option, please try again\n");
                break;
        }
    }
    return 0;
}