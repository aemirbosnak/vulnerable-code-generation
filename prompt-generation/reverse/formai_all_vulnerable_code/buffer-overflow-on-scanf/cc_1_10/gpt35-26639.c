//FormAI DATASET v1.0 Category: Banking Record System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bank_record {
    char name[50];
    int account_number;
    float balance;
};

void write_record(struct bank_record *record);
void read_record(struct bank_record *record);
void display_record(struct bank_record *record);

int main() {
    struct bank_record record;
    int choice;

    while(1) {
        printf("---------- Banking Record System ----------\n");
        printf("1. Write Record\n");
        printf("2. Read Record\n");
        printf("3. Display Record\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                write_record(&record);
                break;
            case 2:
                read_record(&record);
                break;
            case 3:
                display_record(&record);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void write_record(struct bank_record *record) {
    printf("Enter name: ");
    scanf("%s", record->name);
    printf("Enter account number: ");
    scanf("%d", &record->account_number);
    printf("Enter balance: ");
    scanf("%f", &record->balance);

    FILE *fp;
    fp = fopen("record.dat", "ab");
    if(fp == NULL) {
        printf("File cannot be opened!\n");
        exit(1);
    }
    fwrite(record, sizeof(struct bank_record), 1, fp);
    fclose(fp);
}

void read_record(struct bank_record *record) {
    int account_number;
    printf("Enter account number to read record: ");
    scanf("%d", &account_number);

    FILE *fp;
    fp = fopen("record.dat", "rb");
    if(fp == NULL) {
        printf("File cannot be opened!\n");
        exit(1);
    }

    int found = 0;
    while(fread(record, sizeof(struct bank_record), 1, fp)) {
        if(record->account_number == account_number) {
            found = 1;
            break;
        }
    }

    if(found) {
        printf("Record found!\n");
    } else {
        printf("Record not found!\n");
    }

    fclose(fp);
}

void display_record(struct bank_record *record) {
    FILE *fp;
    fp = fopen("record.dat", "rb");
    if(fp == NULL) {
        printf("File cannot be opened!\n");
        exit(1);
    }

    printf("Name\t\tAccount Number\t\tBalance\n");
    while(fread(record, sizeof(struct bank_record), 1, fp)) {
        printf("%s\t\t%d\t\t\t%.2f\n", record->name, record->account_number, record->balance);
    }

    fclose(fp);
}