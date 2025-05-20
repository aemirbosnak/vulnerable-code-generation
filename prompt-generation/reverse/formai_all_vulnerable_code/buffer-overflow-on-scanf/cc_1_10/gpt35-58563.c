//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
    char name[50];
    int account_number;
    float balance;
};

void display_menu();
void add_record(struct bank_record *records, int *num_records);
void display_records(struct bank_record *records, int num_records);
void update_record(struct bank_record *records, int num_records);
void delete_record(struct bank_record *records, int *num_records);
void sort_records(struct bank_record *records, int num_records);

int main() {
    int num_records = 0;
    struct bank_record *records = malloc(sizeof(struct bank_record) * 100);
    
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                display_records(records, num_records);
                break;
            case 3:
                update_record(records, num_records);
                break;
            case 4:
                delete_record(records, &num_records);
                break;
            case 5:
                sort_records(records, num_records);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(1);
    
    free(records);
    return 0;
}

void display_menu() {
    printf("*** BANK RECORD SYSTEM ***\n");
    printf("1. Add record\n");
    printf("2. Display records\n");
    printf("3. Update record\n");
    printf("4. Delete record\n");
    printf("5. Sort records\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

void add_record(struct bank_record *records, int *num_records) {
    printf("Enter name: ");
    scanf("%s", records[*num_records].name);
    printf("Enter account number: ");
    scanf("%d", &records[*num_records].account_number);
    printf("Enter balance: ");
    scanf("%f", &records[*num_records].balance);
    (*num_records)++;
    printf("Record added successfully.\n");
}

void display_records(struct bank_record *records, int num_records) {
    if(num_records == 0) {
        printf("No records found.\n");
        return;
    }
    printf("==============================================\n");
    printf("|\tName\t|\tAccount No.\t|\tBalance\t|\n");
    for(int i = 0; i < num_records; i++) {
        printf("|\t%s\t|\t%d\t|\t%.2f\t|\n", records[i].name, records[i].account_number, records[i].balance);
    }
    printf("==============================================\n");
}

void update_record(struct bank_record *records, int num_records) {
    if(num_records == 0) {
        printf("No records found.\n");
        return;
    }
    int account_number;
    printf("Enter account number to update: ");
    scanf("%d", &account_number);
    for(int i = 0; i < num_records; i++) {
        if(records[i].account_number == account_number) {
            printf("Enter new name: ");
            scanf("%s", records[i].name);
            printf("Enter new balance: ");
            scanf("%f", &records[i].balance);
            printf("Record updated successfully.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void delete_record(struct bank_record *records, int *num_records) {
    if(*num_records == 0) {
        printf("No records found.\n");
        return;
    }
    int account_number;
    printf("Enter account number to delete: ");
    scanf("%d", &account_number);
    for(int i = 0; i < *num_records; i++) {
        if(records[i].account_number == account_number) {
            for(int j = i; j < (*num_records) - 1; j++) {
                records[j] = records[j+1];
            }
            (*num_records)--;
            printf("Record deleted successfully.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void sort_records(struct bank_record *records, int num_records) {
    if(num_records == 0) {
        printf("No records found.\n");
        return;
    }
    struct bank_record temp_record;
    for(int i = 0; i < num_records - 1; i++) {
        for(int j = 0; j < num_records - i - 1; j++) {
            if(records[j].account_number > records[j+1].account_number) {
                temp_record = records[j];
                records[j] = records[j+1];
                records[j+1] = temp_record;
            }
        }
    }
    printf("Records sorted successfully.\n");
}